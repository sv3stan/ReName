//---------------------------------------------------------------------------

#pragma hdrstop

#include "Utils.h"
#include "ExifUtils.h"
#include <Vcl.ComCtrls.hpp>
#include <Vcl.StdCtrls.hpp>

//---------------------------------------------------------------------------
#pragma package(smart_init)





void ProcessSelectedFile(TListItem *selectedItem, TForm1 *form, TJvImage *image) {


 if (selectedItem != nullptr) {
        // Если элемент выбран, вы можете получить его данные
        String itemPath = selectedItem->Caption; // Имя элемента
        String itemName =
            selectedItem->SubItems->Strings[0]; // Первый подэлемент

        UnicodeString uFileName = itemPath + itemName;
        Form1->Label9->Caption = itemPath; // Путь
        Form1->Label10->Caption = itemName; // Имя
        Form1->Label11->Caption = GetFileExtension(itemName);

        WIN32_FILE_ATTRIBUTE_DATA fileInfo;
        if (GetFileAttributesExW(
                uFileName.w_str(), GetFileExInfoStandard, &fileInfo))
        {
            LARGE_INTEGER fileSize;
            fileSize.HighPart = fileInfo.nFileSizeHigh;
            fileSize.LowPart = fileInfo.nFileSizeLow;
            Form1->Label12->Caption = IntToStr(fileSize.QuadPart) + " bytes";

            SYSTEMTIME systemTime;

            FileTimeToSystemTime(&fileInfo.ftCreationTime, &systemTime);
            Form1->Label13->Caption =
                DateTimeToStr(SystemTimeToDateTime(systemTime));

            FileTimeToSystemTime(&fileInfo.ftLastWriteTime, &systemTime);
            Form1->Label14->Caption =
                DateTimeToStr(SystemTimeToDateTime(systemTime));

            FileTimeToSystemTime(&fileInfo.ftLastAccessTime, &systemTime);
            Form1->Label15->Caption =
                DateTimeToStr(SystemTimeToDateTime(systemTime));

            std::string attributes =
                FormatFileAttributes(fileInfo.dwFileAttributes);
            // Преобразуем std::string в UnicodeString
            UnicodeString formatted = UnicodeString(attributes.c_str());
            // Используем formatted в коде
            Form1->Label16->Caption = formatted;
        }

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

        ExifData exifData = GetExifData(itemPath + itemName);

        Form1->Label22->Caption = exifData.date;
        Form1->Label23->Caption = exifData.width;
        Form1->Label24->Caption = exifData.height;
        Form1->Label25->Caption = exifData.make;
        Form1->Label26->Caption = exifData.model;
        //        ShowMessage(GetExifDate(itemPath + itemName));
        // Используйте itemName и itemPath по вашему усмотрению
    } else {
        //		Form1->Label9->Visible = false;
        //		Form1->Label10->Visible = false;
        //		Form1->Label11->Visible = false;
        //		Form1->Label12->Visible = false;
        //		Form1->Label13->Visible = false;
        //		Form1->Label14->Visible = false;
        //		Form1->Label15->Visible = false;
        //		Form1->Label16->Visible = false;

        // Если элемент не выбран, можете обработать это
        //		ShowMessage("Элемент не выбран!");
    }

}