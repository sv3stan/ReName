//---------------------------------------------------------------------------

#pragma hdrstop

#include "../include/Utils.h"
#include "../include/ExifUtils.h"
#include "Main.h"
#include <Vcl.ComCtrls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <System.SysUtils.hpp>

//---------------------------------------------------------------------------
#pragma package(smart_init)

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
            // ExifData exifData = GetExifData(uFileName);

            fullItemData.exifData.date = GetExifDate(uFileName);
//                         ShowMessage((fullItemData.exifData.date));


            if (fullItemData.exifData.date == TDateTime(0)) {
//                ShowMessage("++++++");
                GetImageDimensions(uFileName, fullItemData.exifData.width,
                    fullItemData.exifData.height);
            } else {

//                   ShowMessage("------------");
                //fullItemData.exifData.width = GetImageWidth(uFileName);



           GetImageSize(uFileName, fullItemData.exifData.width, fullItemData.exifData.height);
//                Form1->JvStatusBar1->Panels->Items[1]->Text =
//                    "Разрешение: " + UnicodeString(fullItemData.exifData.height);

//                ShowMessage(UnicodeString(fullItemData.exifData.width));
               // fullItemData.exifData.height = GetImageHeight(uFileName);

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
                "Всего файлов: " + UnicodeString(itemMap.size());
        }
    }

    //  ShowMessage(UnicodeString(itemMap.size()));
}

void fromMapToStoreListView(TJvListView* jvListView, TStrings* value)
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
        newItem->Caption = fullItemData.fileData.path;
        newItem->SubItems->Add(fullItemData.fileData.name);
        newItem->SubItems->Add(fullItemData.newData.newName);
        newItem->SubItems->Add(fullItemData.fileData.size);
        newItem->SubItems->Add(fullItemData.fileData.dateCreated);
        newItem->SubItems->Add(fullItemData.newData.newDateCreated);
        newItem->SubItems->Add(fullItemData.fileData.dateModified);
        newItem->SubItems->Add(fullItemData.newData.newDateModified);
        newItem->SubItems->Add(fullItemData.fileData.dateOpened);
        newItem->SubItems->Add(fullItemData.newData.newDateOpened);
        newItem->SubItems->Add(fullItemData.exifData.date);
        newItem->SubItems->Add(fullItemData.newData.newDatePhoto);
        newItem->SubItems->Add(fullItemData.fileData.attribute);
        // }
    }
    jvListView->Items->EndUpdate();
}

void ProcessSelectedFile(TListItem* selectedItem, TForm1* form, TJvImage* image)
{
    String itemPath = selectedItem->Caption;
    String itemName = selectedItem->SubItems->Strings[0];

    //ShowMessage(fullItemData.exifData.date);

    auto it = itemMap.find(itemPath + itemName);
    //              ShowMessage(it.second.exifData.date);
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

    Form1->Label9->Visible = true;
    Form1->Label10->Visible = true;
    Form1->Label11->Visible = true;
    Form1->Label12->Visible = true;
    Form1->Label13->Visible = true;
    Form1->Label14->Visible = true;
    Form1->Label15->Visible = true;
    Form1->Label16->Visible = true;

    Form1->Label22->Visible = true;
    Form1->Label23->Visible = true;
    Form1->Label24->Visible = true;
    Form1->Label25->Visible = true;
    Form1->Label26->Visible = true;

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

