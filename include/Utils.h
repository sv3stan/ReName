//---------------------------------------------------------------------------

#ifndef UtilsH
#define UtilsH
//---------------------------------------------------------------------------

#include <System.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.StdCtrls.hpp>

#include <System.SysUtils.hpp>
#include "Main.h"
#include <optional>
#include <chrono>
//

class TForm1; // Forward declaration

TFormatSettings GlobalFormatSettings;

void InitGlobalFormatSettings()
{
    GlobalFormatSettings = TFormatSettings::Create();
    GlobalFormatSettings.ShortDateFormat = "yyyy:mm:dd";
    GlobalFormatSettings.LongTimeFormat = "hh:nn:ss";
    GlobalFormatSettings.DateSeparator = ':';
    GlobalFormatSettings.TimeSeparator = ':';
}
//

struct ExifData
{
    System::TDateTime date;
    unsigned int width; // Ширина изображения
    unsigned int height; // Высота изображения
    System::UnicodeString make; // Производитель
    System::UnicodeString model; // Модель
};

struct NewData
{
    System::TDateTime newDateCreated; // Новая дата создания
    System::TDateTime newDateModified; // Новая дата модификации
    System::TDateTime newDateOpened; // Новая дата открытия
    System::TDateTime newDateOriginal; // Новая дата фото
    System::UnicodeString newAttribute; // Новый атрибут
    System::UnicodeString newName; // Новое имя
};

struct FileData
{
    System::UnicodeString path; // Путь
    System::UnicodeString name; // Имя
    long size; // Размер
    System::TDateTime dateCreated; // Дата создания
    System::TDateTime dateModified; // Дата модификации
    System::TDateTime dateOpened; // Дата открытия
    System::UnicodeString attribute = L"----"; // Атрибут
    ExifData exifData; // Exif-данные
    NewData newData; // Новая информация о файле
};

struct FullItemData
{
    FileData fileData;
    NewData newData;
    ExifData exifData;
};

extern void InitGlobalFormatSettings();
extern std::unordered_map<System::UnicodeString, FullItemData> itemMap;

// Функция для обработки информации о выбранном файле
void ProcessSelectedFile(
    TListItem* selectedItem, TForm1* form, TJvImage* image);
void storeDraggedFilesToMap(TStrings* Value);
void fromMapToStoreListView(TJvListView* jvListView);
void ProcessFolder(const UnicodeString &folderPath, TListItems* items);

TDateTime parseDateFromFileName(const System::UnicodeString &fileName);
bool setChangedFileDateTime(const UnicodeString &filePath,
    const UnicodeString &fileName);
bool StringToSystemTime(const String &dateTimeStr, SYSTEMTIME &systemTime);
int GetEncoderClsid(const WCHAR* format, CLSID* pClsid);
AnsiString DateTimeToExifFormat(const TDateTime &dateTime);
bool SetExifDateTimeOriginal(const UnicodeString &filePath,
    const UnicodeString &fileName, const TDateTime &newDate);
bool TDateTimeToFileTime(const TDateTime &dateTime, FILETIME &fileTime);
void ApplyFilenameToDate(TListView* listView);
void GetFileCreationDateTime(TListView* listView);
void parseNewNameFromFileDateTime(
        System::TDateTime dateTime,
    UnicodeString &formattedDate,
    UnicodeString &formattedTime);

#endif // UTILS_H

