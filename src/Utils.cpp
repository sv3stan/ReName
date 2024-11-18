//---------------------------------------------------------------------------

#pragma hdrstop

#include "../include/Utils.h"
#include "../include/ExifUtils.h"
#include "Main.h"
#include <Vcl.ComCtrls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <vcl.h>
#include <regex>
#include <string>
#include <System.SysUtils.hpp>
#include <gdiplus.h>
#include <iomanip>
#include <sstream>

//---------------------------------------------------------------------------
#pragma package(smart_init)

using namespace Gdiplus;
std::unordered_map<System::UnicodeString, FullItemData> itemMap;

void storeDraggedFilesToMap(TStrings* Value)
{
    for (int i = 0; i < Value->Count; i++) {
        UnicodeString uFileName = Value->Strings[i];

        // Проверяем, является ли путь папкой
        if (DirectoryExists(uFileName)) {
            ProcessFolder(uFileName,
                Form1->JvListView1->Items); // Обрабатываем папку рекурсивно
        } else {
            // Создаем объект FileData и заполняем его
            FullItemData fullItemData;
            //FileData fileData;
            fullItemData.fileData.path = ExtractFilePath(uFileName);
            fullItemData.fileData.name = ExtractFileName(uFileName);

            SYSTEMTIME systemTime;
            // Получение атрибутов файла
            WIN32_FILE_ATTRIBUTE_DATA fileInfo;
            if (GetFileAttributesExW(
                    uFileName.w_str(), GetFileExInfoStandard, &fileInfo))
            {
                LARGE_INTEGER fileSize;
                fileSize.HighPart = fileInfo.nFileSizeHigh;
                fileSize.LowPart = fileInfo.nFileSizeLow;
                fullItemData.fileData.size = fileSize.QuadPart;

                double variantTime;
                SYSTEMTIME systemTime;

                FileTimeToSystemTime(&fileInfo.ftCreationTime, &systemTime);
                SystemTimeToVariantTime(&systemTime, &variantTime);
                fullItemData.fileData.dateCreated =
                    System::TDateTime(variantTime);

                FileTimeToSystemTime(&fileInfo.ftLastWriteTime, &systemTime);
                SystemTimeToVariantTime(&systemTime, &variantTime);
                fullItemData.fileData.dateModified =
                    System::TDateTime(variantTime);

                FileTimeToSystemTime(&fileInfo.ftLastAccessTime, &systemTime);
                SystemTimeToVariantTime(&systemTime, &variantTime);
                fullItemData.fileData.dateOpened =
                    System::TDateTime(variantTime);

                fullItemData.fileData.attribute =
                    FormatFileAttributes(fileInfo.dwFileAttributes);
            }

            UnicodeString newDate = parseDateFromFileName(uFileName);
            UnicodeString dateStr, timeStr;
            parseNewNameFromFileDateTime(
                fullItemData.fileData.dateCreated, dateStr, timeStr);
                fullItemData.newData.newName = dateStr + " & " + timeStr;

            fullItemData.newData.newDateCreated = newDate;
            fullItemData.newData.newDateModified = newDate;
            fullItemData.newData.newDateOpened = newDate;
            fullItemData.newData.newDateOriginal = newDate;

            fullItemData.exifData.date = GetExifDate(uFileName);

            if (fullItemData.exifData.date == TDateTime(0)) {
                GetImageDimensions(uFileName, fullItemData.exifData.width,
                    fullItemData.exifData.height);
            } else {
                GetImageSize(uFileName, fullItemData.exifData.width,
                    fullItemData.exifData.height);
                fullItemData.exifData.make = GetCameraMake(uFileName);
                fullItemData.exifData.model = GetCameraModel(uFileName);
            }

            UnicodeString key =
                fullItemData.fileData.path + fullItemData.fileData.name;
            if (itemMap.find(key) == itemMap.end()) {
                itemMap[key] = fullItemData;
            }

            //            itemMap[fullItemData.fileData.path + fullItemData.fileData.name] =
            //                fullItemData;

            //             String str = itemMap.size();
            //            ShowMessage(str);
            //form->JvStatusBar1->panel[0]->Text = str;

            Form1->JvStatusBar1->Panels->Items[0]->Text =
                "Total files : " + UnicodeString(itemMap.size());
        }
    }

    //  ShowMessage(UnicodeString(itemMap.size()));
}

void fromMapToStoreListView(TJvListView* jvListView)
//void fromMapToStoreListView(TJvListView* jvListView, TStrings* value)
{
    jvListView->Items->BeginUpdate();
    jvListView->Items->Clear(); // Очищаем предыдущие элементы
    int sizeItemMap = itemMap.size();

    for (auto it = itemMap.begin(); it != itemMap.end(); ++it) {
        // const UnicodeString &filePath = value->Strings[i];

        // Проверяем, существует ли элемент в itemMap
        // auto it = itemMap.find(filePath);
        //   if (it != itemMap.end()) {
        const FullItemData &fullItemData = it->second;
        // Создаем новый элемент для JvListView
        TListItem* newItem = jvListView->Items->Add();
        newItem->Caption = fullItemData.fileData.name;
        newItem->SubItems->Add(fullItemData.newData.newName);
        newItem->SubItems->Add(fullItemData.fileData.path);
        newItem->SubItems->Add(fullItemData.fileData.size);
        newItem->SubItems->Add(fullItemData.fileData.dateCreated);
        newItem->SubItems->Add(fullItemData.newData.newDateCreated);
        newItem->SubItems->Add(fullItemData.fileData.dateModified);
        newItem->SubItems->Add(fullItemData.newData.newDateModified);
        newItem->SubItems->Add(fullItemData.fileData.dateOpened);
        newItem->SubItems->Add(fullItemData.newData.newDateOpened);
        newItem->SubItems->Add(fullItemData.exifData.date);
        newItem->SubItems->Add(fullItemData.newData.newDateOriginal);
        newItem->SubItems->Add(fullItemData.fileData.attribute);

        // }
    }
    jvListView->Items->EndUpdate();
}

void ProcessSelectedFile(TListItem* selectedItem, TForm1* form, TJvImage* image)
{
    String itemName = selectedItem->Caption;
    String itemPath = selectedItem->SubItems->Strings[1];
    auto it = itemMap.find(itemPath + itemName);

    if (it != itemMap.end()) {
        const FullItemData &fullItemData = it->second;

        form->Label9->Caption = fullItemData.fileData.path;
        form->Label10->Caption = fullItemData.fileData.name;
        form->Label11->Caption = GetFileExtension(fullItemData.fileData.name);
        form->Label12->Caption = fullItemData.fileData.size;
        form->Label13->Caption = fullItemData.fileData.dateCreated;
        form->Label14->Caption = fullItemData.fileData.dateModified;
        form->Label15->Caption = fullItemData.fileData.dateOpened;
        form->Label16->Caption = fullItemData.fileData.attribute;
        form->Label22->Caption = fullItemData.exifData.date;
        form->Label23->Caption = fullItemData.exifData.width;
        form->Label24->Caption = fullItemData.exifData.height;
        form->Label25->Caption = fullItemData.exifData.make;
        form->Label26->Caption = fullItemData.exifData.model;

        //
        //        form->Label11->Caption = GetFileExtension(fullItemData.fileData.name);
        //        form->Label12->Caption = fullItemData.fileData.size + " bytes";
    }
    //form->Repaint();

    TLabel* labels[] = { Form1->Label9, Form1->Label10, Form1->Label11,
        Form1->Label12, Form1->Label13, Form1->Label14, Form1->Label15,
        Form1->Label16, Form1->Label22, Form1->Label23, Form1->Label24,
        Form1->Label25, Form1->Label26 };

    for (TLabel* label : labels) {
        label->Visible = true;
    }

    image->Picture->LoadFromFile(itemPath + itemName);
}

void ProcessFolder(const UnicodeString &folderPath, TListItems* items)
{
    TSearchRec searchRec;
    if (FindFirst(folderPath + "\\*.*", faAnyFile, searchRec) == 0) {
        do {
            if (searchRec.Name != "." && searchRec.Name != "..") {
                UnicodeString fullPath = folderPath + "\\" + searchRec.Name;

                // Создаем временный список
                TStringList* tempList = new TStringList();

                // Если это папка, обрабатываем её рекурсивно
                if (searchRec.Attr & faDirectory) {
                    ProcessFolder(
                        fullPath, items); // Рекурсивный вызов для подпапок
                } else {
                    // Добавляем полный путь к файлу в tempList и обрабатываем
                    tempList->Add(fullPath);

                    // Передаем tempList в storeDraggedFilesToMap
                    storeDraggedFilesToMap(tempList);
                    //                    fromMapToStoreListView(Form1->JvListView1, tempList);
                }

                // Освобождаем память tempList после обработки
                delete tempList;
            }
        } while (FindNext(searchRec) == 0);

        FindClose(searchRec);
    }
}

/**
 * @brief Parses the date and time from a filename string, formatted as YYYYMMDD_HHMMSS.
 *
 * This function extracts a date and time from the given filename string based on a specific
 * pattern (e.g., "20231108_153045.jpg"). The pattern expects the date to follow the format
 * "YYYYMMDD_HHMMSS" and is designed to support common image file extensions such as .jpg, .jpeg, or .png.
 *
 * @param fileName The filename containing the date and time in the specified format.
 * @return A TDateTime object representing the parsed date and time from the filename.
 *         If the date and time are not found, the function returns the current date and time.
 */
TDateTime parseDateFromFileName(const System::UnicodeString &fileName)
{
    std::string fileNameStr = AnsiString(fileName).c_str();
    std::regex dateTimePattern(R"((?:_)?(\d{4})(0[1-9]|1[0-2])(0[1-9]|[12]\d|3[01])(?:_)?([01]\d|2[0-3])([0-5]\d)([0-5]\d)\.(?:jpg|jpeg|png))");
    // Regular expression to extract date and time from filename, format YYYYMMDD_HHMMSS
    // Pattern searches for:
    // - Optional underscore (_) before the date.
    // - 4-digit year (\d{4}), for example, 2023.
    // - Month, represented by two digits from 01 to 12 (0[1-9]|1[0-2]).
    // - Day, represented by two digits from 01 to 31 (0[1-9]|[12]\d|3[01]).
    // - Optional underscore (_) before time.
    // - Two-digit hours from 00 to 23 ([01]\d|2[0-3]).
    // - Minutes and seconds from two digits from 00 to 59 ([0-5]\d).
    // - The file extension is .jpg, .jpeg, or .png (?:jpg|jpeg|png), which is not captured in the group.
    //
    // Example of a corresponding file name: "20231108_153045.jpg"
    int year = 0, month = 0, day = 0, hour = 0, minute = 0, second = 0;
    std::smatch matches;
    if (std::regex_search(fileNameStr, matches, dateTimePattern)) {
        year = std::stoi(matches[1].str());
        month = std::stoi(matches[2].str());
        day = std::stoi(matches[3].str());
        hour = std::stoi(matches[4].str());
        minute = std::stoi(matches[5].str());
        second = std::stoi(matches[6].str());
        return TDateTime(year, month, day, hour, minute, second, 0);
    }
    // If the date is not found, return the current date and time
    return TDateTime();
}

bool setChangedFileDateTime(
    const UnicodeString &filePath, const UnicodeString &fileName)
{
    auto it = itemMap.find(filePath + fileName);
    if (it == itemMap.end()) {
        ShowMessage("File not found in itemMap.");
        return false;
    }

    const auto &fileData = it->second.fileData;
    const auto &newData = it->second.newData;

    std::wstring fullPath =
        std::wstring(filePath.w_str()) + std::wstring(fileName.w_str());
    FILETIME fileTime;

    // Open the file
    HANDLE fileHandle = CreateFileW(fullPath.c_str(),
        GENERIC_WRITE, // Write permission
        FILE_SHARE_READ, // Allow other processes to read the file
        NULL, // Защита по умолчанию
        OPEN_EXISTING, // Открываем только существующий файл
        FILE_ATTRIBUTE_NORMAL, // Атрибуты по умолчанию
        NULL // Без шаблона файла
    );

    if (fileHandle == INVALID_HANDLE_VALUE) {
        ShowMessage("Failed to open file.");
        return false;
    }

    bool result = true;

    if (DATE_CREATED_CHECK) { // Set the time DATE CREATED
        if (!TDateTimeToFileTime(newData.newDateCreated, fileTime)) {
            ShowMessage("Failed to convert creation time.");
            result = false;
        } else if (!SetFileTime(fileHandle, &fileTime, NULL, NULL)) {
            ShowMessage(L"Could not set file creation date.");
            result = false;
        } else {
            it->second.fileData.dateCreated = it->second.newData.newDateCreated;
        }
    }

    if (DATE_MODIFIED_CHECK) { // Set the time DATE MODIFIED
        if (!TDateTimeToFileTime(newData.newDateModified, fileTime)) {
            ShowMessage("Failed to convert modified time.");
            result = false;
        } else if (!SetFileTime(fileHandle, NULL, NULL, &fileTime)) {
            ShowMessage(L"Failed to convert modified time.");
            result = false;
        } else {
            it->second.fileData.dateModified =
                it->second.newData.newDateModified;
        }
    }

    if (DATE_OPENED_CHECK) { // Set the time DATE OPENED
        if (!TDateTimeToFileTime(newData.newDateOpened, fileTime)) {
            ShowMessage("Failed to convert opened time.");
            result = false;
        } else if (!SetFileTime(fileHandle, NULL, &fileTime, NULL)) {
            ShowMessage(L"Failed to convert opened time.");
            result = false;
        } else {
            it->second.fileData.dateOpened = it->second.newData.newDateOpened;
        }
    }

    CloseHandle(fileHandle); // Closing the file descriptor

    if (DATE_ORIGINAL_CHECK) { // Set the time DATE ORIGINAL
        result = SetExifDateTimeOriginal(
                     filePath, fileName, newData.newDateOriginal) != 0;
        if (!result) {
            ShowMessage(L"Failed to set date origin file.");
            result = false;
        }
    }

    for (int i = 0; i < Form1->JvListView1->Items->Count; i++) {
        TListItem* item = Form1->JvListView1->Items->Item[i];

        UnicodeString itemFilePath = item->SubItems->Strings[PATH];
        UnicodeString itemFileName = item->Caption;
        UnicodeString itemKey = itemFilePath + itemFileName;

        if (itemKey == filePath + fileName) {
            item->SubItems->Strings[DATE_CREATED] =
                it->second.fileData.dateCreated;

            item->SubItems->Strings[DATE_MODIFIED] =
                it->second.fileData.dateModified;

            item->SubItems->Strings[DATE_OPENED] =
                it->second.fileData.dateOpened;

            break;
        }
    }

    return result;
}

/**
 * @brief Converts a date string to a SYSTEMTIME structure.
 *
 * @param dateTimeStr The date and time as a string.
 * @param systemTime The SYSTEMTIME structure to populate.
 * @return true if the conversion was successful, false otherwise.
 */

bool StringToSystemTime(const String &dateTimeStr, SYSTEMTIME &systemTime)
{
    try {
        TDateTime dateTime = StrToDateTime(dateTimeStr);
        dateTime.DecodeDate(
            &systemTime.wYear, &systemTime.wMonth, &systemTime.wDay);
        dateTime.DecodeTime(&systemTime.wHour, &systemTime.wMinute,
            &systemTime.wSecond, &systemTime.wMilliseconds);
        return true;
    } catch (...) {
        ShowMessage("Failed to convert string to SYSTEMTIME");
        return false;
    }
}

/**
 * @brief Gets the CLSID of the codec for the specified image format.
 *
 * The function searches for the CLSID of the codec that is used to encode images
 * to a given format, such as "image/jpeg" or "image/png". This CLSID is required
 * for saving images in GDI+.
 *
 * @param format Image format as a `const WCHAR*` string, for example L"image/jpeg".
 * @param pClsid A pointer to the CLSID that will be set if the codec for the given
 * format found.
 *
 * @return Index of the codec in the `ImageCodecInfo` array if found, or -1 on error
 * (codec not found or memory allocation failed).
 *
 * @note Before calling the function, `pClsid` must point to pre-allocated memory for the CLSID.
 *
 * @details
 * The function first gets the number and size of all installed codecs using
 * `GetImageEncodersSize`. Then allocates memory for the `ImageCodecInfo` array and receives
 * information about each installed codec via `GetImageEncoders`. In the loop the function searches
 * matches the `MimeType` format, and if a match is found, writes the `CLSID` to `pClsid`.
 * At the end, frees memory and returns the codec index or -1 if the codec is not found.
 *
 *Usage example:
 * @code
 * CLSID jpegClsid;
 * int result = GetEncoderClsid(L"image/jpeg", &jpegClsid);
 * if (result != -1) {
 * // jpegClsid now contains the CLSID of the JPEG codec
 * }
 * @endcode
 */
int GetEncoderClsid(const WCHAR* format, CLSID* pClsid)
{
    UINT num = 0; // Number of all installed codecs
    UINT size = 0; // ImageCodecInfo array size

    ImageCodecInfo* pImageCodecInfo = NULL;

    // Get the number and total size of codecs
    GetImageEncodersSize(&num, &size);
    if (size == 0) {
        return -1;
    }

    // Allocate memory for the ImageCodecInfo array
    pImageCodecInfo = (ImageCodecInfo*)(malloc(size));
    if (pImageCodecInfo == NULL) {
        return -1; // Ошибка выделения памяти
    }

    // Get information about codecs
    GetImageEncoders(num, size, pImageCodecInfo);

    for (UINT i = 0; i < num; ++i) {
        if (wcscmp(pImageCodecInfo[i].MimeType, format) == 0) {
            *pClsid = pImageCodecInfo[i].Clsid;
            free(pImageCodecInfo);
            return i;
        }
    }

    // Free memory if codec not found
    free(pImageCodecInfo);
    return -1;
}

/**
 * @brief Converts a date and time to an Exif format string.
 *
 * The function converts the `TDateTime` object to a format string used in Exif metadata
 * to record date and time: "yyyy:mm:dd hh:nn:ss".
 *
 * @param dateTime A `TDateTime` object containing the date and time to convert.
 *
 * @return Returns an `AnsiString` with the date and time in the format "yyyy:mm:dd hh:nn:ss".
 *
 * @note The Exif format requires a colon as the year, month, and day separator.
 *
 * @details
 * For example, when passing a `TDateTime` object representing October 15, 2024, 2:30:45 p.m.
 * the function will return the string "2024:10:15 14:30:45".
 *
 *Usage example:
 * @code
 * TDateTime dateTime = Now();
 * AnsiString exifDateTime = DateTimeToExifFormat(dateTime);
 * ShowMessage(exifDateTime); // Prints the current date and time in Exif format
 * @endcode
 */
AnsiString DateTimeToExifFormat(const TDateTime &dateTime)
{
    return dateTime.FormatString("yyyy:mm:dd hh:nn:ss");
}

/**
 * @brief Sets the creation date and time of the original image in the EXIF ??tag.
 *
 * The function loads the image, sets the date and time in the EXIF ??tag "DateTimeOriginal",
 * then saves the modified file with a new name, adding the prefix "modified_" to the file name.
 * For correct operation, the function initializes and terminates GDI+.
 *
 * @param filePath Path to the directory containing the image file.
 * @param fileName The name of the image file.
 * @param newDate The date and time to set in the EXIF ??tag.
 * @return true if the operation completed successfully; false if an error occurred (for example,
 *could not load image, set tag or save file).
 *
 * @note The function only supports formats that are supported by GDI+, such as JPEG.
 *
 * @details
 *Usage example:
 * @code
 * TDateTime newDate = TDateTime::CurrentDateTime();
 * bool success = SetExifDateTimeOriginal("C:\\images\\", "photo.jpg", newDate);
 * if (success) {
 * ShowMessage("EXIF date set successfully.");
 * } else {
 * ShowMessage("Failed to set EXIF ??date.");
 * }
 * @endcode
 */
bool SetExifDateTimeOriginal(const UnicodeString &filePath,
    const UnicodeString &fileName, const TDateTime &newDate)
{
    GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR gdiplusToken;
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
    bool result = false;

    try {
        // Forming the full path to the file
        const UnicodeString fullFilePath = filePath + fileName;

        // Uploading an image
        Image image(fullFilePath.c_str());
        if (image.GetLastStatus() != Ok) {
            ShowMessage(
                L"Failed to load source image. Check the path and file format.");
            GdiplusShutdown(gdiplusToken);
            return false;
        }

        // EXIF tag ID for date
        const PROPID PropertyTagExifDateTimeOriginal = 0x9003;

        // Преобразуем дату в строку EXIF
        AnsiString exifDateStr = DateTimeToExifFormat(newDate);
        std::string exifDateStd = exifDateStr.c_str();

        // Create a PropertyItem for the EXIF ??tag
        PropertyItem propertyItem;
        propertyItem.id = PropertyTagExifDateTimeOriginal;
        propertyItem.length = static_cast<UINT>(
            exifDateStd.size() + 1); // +1 для null-терминатора
        propertyItem.type = PropertyTagTypeASCII;
        propertyItem.value = const_cast<char*>(exifDateStd.c_str());

        // Set EXIF date origial tag
        Status status = image.SetPropertyItem(&propertyItem);
        if (status != Ok) {
            ShowMessage(L"Failed to set new EXIF tag value.");
            GdiplusShutdown(gdiplusToken);
            return false;
        }

        // Save the modified image
        CLSID jpegClsid;
        GetEncoderClsid(
            L"image/jpeg", &jpegClsid); // Getting the CLSID for the JPEG format

        UnicodeString newFilename = filePath + L"modified_" + fileName;

        status = image.Save(newFilename.c_str(), &jpegClsid);
        if (status != Ok) {
            ShowMessage(L"Failed to save image with new EXIF tag.");
            return false;
        }
        result = true;
    } catch (...) {
        ShowMessage(L"An unexpected error occurred while setting EXIF date.");
    }

    // Quit working with GDI+
    GdiplusShutdown(gdiplusToken);
    return result;
}

bool TDateTimeToFileTime(const TDateTime &dateTime, FILETIME &fileTime)
{
    // Определяем начало эпохи для FILETIME (1 января 1601 года)
    //    TDateTime epoch = EncodeDateTime(1601, 1, 1, 0, 0, 0, 0); // Год, месяц, день, час, минута, секунда, миллисекунда
    TDateTime epoch = EncodeDate(1601, 1, 1) + EncodeTime(0, 0, 0, 0);
    //     TDateTime epoch(1601, 1, 1, 0, 0, 0);

    // Проверка: если дата до эпохи FILETIME, возвращаем ошибку
    if (dateTime < epoch) {
        return false; // Ошибка: дата раньше 1601 года
    }

    // Вычисляем разницу в днях
    double deltaDays = dateTime - epoch;

    // Преобразуем дни в 100-наносекундные интервалы
    LONGLONG fileTimeValue =
        static_cast<LONGLONG>(deltaDays * 24 * 60 * 60 * 10000000);

    // Заполняем FILETIME
    fileTime.dwLowDateTime = static_cast<DWORD>(fileTimeValue & 0xFFFFFFFF);
    fileTime.dwHighDateTime = static_cast<DWORD>(fileTimeValue >> 32);

    return true; // Успешное завершение
}

void ApplyFilenameToDate(TListView* listView)
{
    for (int i = 0; i < listView->Items->Count; i++) {
        TListItem* item = listView->Items->Item[i];
        if (item->Checked) {
            setChangedFileDateTime(
                item->SubItems->Strings[PATH], item->Caption);
        }
    }
}

void GetFileCreationDateTime(TListView* listView)
{
    WIN32_FILE_ATTRIBUTE_DATA fileInfo;

    for (int i = 0; i < listView->Items->Count; i++) {
        TListItem* item = listView->Items->Item[i];

        if (item->Checked) {
            // Получение информации о файле

            UnicodeString dateStr, timeStr;

            const UnicodeString fullFileName =
                item->SubItems->Strings[PATH] + item->Caption;

            if (GetFileAttributesEx(
                    fullFileName.w_str(), GetFileExInfoStandard, &fileInfo))
            {
                // Преобразование времени создания файла в SYSTEMTIME

                UnicodeString dateForNewNameFile =
                    item->SubItems->Strings[DATE_CREATED];

                FILETIME ftLocal;
                FileTimeToLocalFileTime(&fileInfo.ftCreationTime, &ftLocal);

                SYSTEMTIME st;
                FileTimeToSystemTime(&ftLocal, &st);

                dateStr = System::Sysutils::Format(L"%04d%02d%02d",
                    OPENARRAY(System::TVarRec, (st.wYear, st.wMonth, st.wDay)));

                timeStr = System::Sysutils::Format(
                    L"%02d%02d%02d", OPENARRAY(System::TVarRec,
                                         (st.wHour, st.wMinute, st.wSecond)));
                item->SubItems->Strings[NEW_FILE_NAME] =
                    dateStr + "_" + timeStr;

            } else {
                throw Exception(L"Не удалось получить информацию о файле.");
            }

            //            try {
            //                //                String directory = ExtractFileDir(fullFileName);
            //                //                String ext = ExtractFileExt(fullFileName);
            //                //                String newName =
            //                //                    directory + L"\\" + dateStr + L"_" + timeStr + ext;
            //
            //                // Переименование файла
            //                if (!RenameFile(fullFileName, newName)) {
            //                    throw Exception(L"Ошибка переименования файла.");
            //                }
            //            } catch (const Exception &e) {
            //                ShowMessage(e.Message);
            //            }
        }
    }
}

void parseNewNameFromFileDateTime(
        System::TDateTime dateTime,
    UnicodeString &formattedDate,
    UnicodeString &formattedTime)
{
    try {
        formattedDate = dateTime.FormatString("yyyy-mm-dd"); // Формат даты
        formattedTime = dateTime.FormatString("hh-nn-ss"); // Формат времени
    } catch (...) {
        formattedDate = "InvalidDate";
        formattedTime = "InvalidTime";
    }
}

