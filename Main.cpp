//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "Utils.h"
#include "ExifUtils.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "JvExExtCtrls"
#pragma link "JvExtComponent"
#pragma link "JvPanel"
#pragma link "JvSplit"
#pragma link "JvComponentBase"
#pragma link "JvDragDrop"
#pragma link "JvExComCtrls"
#pragma link "JvListView"
#pragma link "JvBaseDlg"
#pragma link "JvBrowseFolder"
#pragma link "JvDialogs"
#pragma link "JvDriveCtrls"
#pragma link "JvExStdCtrls"
#pragma link "JvListBox"
#pragma link "JvCombobox"
#pragma link "JvImage"
#pragma link "JvColorBox"
#pragma link "JvColorButton"
#pragma link "JvExControls"
#pragma link "JvArrowButton"
#pragma link "JvCheckBox"
#pragma link "JvgGroupBox"
#pragma link "JvGroupBox"
#pragma link "JvRadioGroup"
#pragma link "JvButton"
#pragma link "JvTransparentButton"
#pragma resource "*.dfm"
ULONG_PTR gdiplusToken;
TForm1* Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {}
//---------------------------------------------------------------------------

void __fastcall TForm1::ProcessFolder(
    const UnicodeString &folderPath, TListItems* items)
{
    TSearchRec searchRec;
    if (FindFirst(folderPath + "\\*.*", faAnyFile, searchRec) == 0) {
        do {
            if (searchRec.Name != "." && searchRec.Name != "..") {
                UnicodeString fullPath = folderPath + "\\" + searchRec.Name;
                if (searchRec.Attr & faDirectory) // Если это папка
                {
                    ProcessFolder(
                        fullPath, items); // Рекурсивно обрабатываем папку
                } else // Если это файл
                {
                    TListItem* item = JvListView1->Items->Add();
                    item->Caption = ExtractFilePath(fullPath); // Путь
                    item->SubItems->Add(ExtractFileName(fullPath)); // Имя

                    item->SubItems->Add("");

                    // Получение атрибутов файла
                    WIN32_FILE_ATTRIBUTE_DATA fileInfo;
                    if (GetFileAttributesExW(
                            fullPath.w_str(), GetFileExInfoStandard, &fileInfo))
                    {
                        LARGE_INTEGER fileSize;
                        fileSize.HighPart = fileInfo.nFileSizeHigh;
                        fileSize.LowPart = fileInfo.nFileSizeLow;
                        item->SubItems->Add(
                            IntToStr(fileSize.QuadPart) + " bytes");

                        SYSTEMTIME systemTime;

                        FileTimeToSystemTime(
                            &fileInfo.ftCreationTime, &systemTime);
                        item->SubItems->Add(
                            DateTimeToStr(SystemTimeToDateTime(systemTime)));

                        item->SubItems->Add("");

                        FileTimeToSystemTime(
                            &fileInfo.ftLastWriteTime, &systemTime);
                        item->SubItems->Add(
                            DateTimeToStr(SystemTimeToDateTime(systemTime)));

                        item->SubItems->Add("");

                        FileTimeToSystemTime(
                            &fileInfo.ftLastAccessTime, &systemTime);
                        item->SubItems->Add(
                            DateTimeToStr(SystemTimeToDateTime(systemTime)));

                        item->SubItems->Add("");

                        std::string attributes =
                            FormatFileAttributes(fileInfo.dwFileAttributes);

                        // Преобразуем std::string в UnicodeString
                        UnicodeString formatted =
                            UnicodeString(attributes.c_str());

                        // Используем formatted в коде
                        item->SubItems->Add(formatted);

                        item->SubItems->Add("");
                    }
                }
            }
        } while (FindNext(searchRec) == 0);
        FindClose(searchRec);
    }
}

void __fastcall TForm1::JvDragDrop1Drop(
    TObject* Sender, TPoint &Pos, TStrings* Value)

{
    for (int i = 0; i < Value->Count; i++) {
        UnicodeString uFileName = Value->Strings[i];

        // Проверяем, является ли путь папкой
        if (DirectoryExists(uFileName)) {
            ProcessFolder(
                uFileName, JvListView1->Items); // Обрабатываем папку рекурсивно
        } else {
            TListItem* item = JvListView1->Items->Add();
            item->Caption = ExtractFilePath(uFileName); // Путь
            item->SubItems->Add(ExtractFileName(uFileName)); // Имя
            item->SubItems->Add("");

            // Получение атрибутов файла
            WIN32_FILE_ATTRIBUTE_DATA fileInfo;
            if (GetFileAttributesExW(
                    uFileName.w_str(), GetFileExInfoStandard, &fileInfo))
            {
                LARGE_INTEGER fileSize;
                fileSize.HighPart = fileInfo.nFileSizeHigh;
                fileSize.LowPart = fileInfo.nFileSizeLow;
                item->SubItems->Add(IntToStr(fileSize.QuadPart) + " bytes");

                SYSTEMTIME systemTime;

                FileTimeToSystemTime(&fileInfo.ftCreationTime, &systemTime);
                item->SubItems->Add(
                    DateTimeToStr(SystemTimeToDateTime(systemTime)));

                item->SubItems->Add("");

                FileTimeToSystemTime(&fileInfo.ftLastWriteTime, &systemTime);
                item->SubItems->Add(
                    DateTimeToStr(SystemTimeToDateTime(systemTime)));

                item->SubItems->Add("");

                FileTimeToSystemTime(&fileInfo.ftLastAccessTime, &systemTime);
                item->SubItems->Add(
                    DateTimeToStr(SystemTimeToDateTime(systemTime)));
                item->SubItems->Add("");
                std::string attributes =
                    FormatFileAttributes(fileInfo.dwFileAttributes);

                // Преобразуем std::string в UnicodeString
                UnicodeString formatted = UnicodeString(attributes.c_str());

                // Используем formatted в коде
                item->SubItems->Add(formatted);
                item->SubItems->Add("");
            }
        }
    }

    // Устанавливаем ширину столбцов, если это необходимо
    JvListView1->Columns->Items[0]->AutoSize =
        true; // Ширина для первого столбца (имя файла)
    JvListView1->Columns->Items[1]->Width = 250;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::JvListView1Click(TObject* Sender)
{
    TListItem* selectedItem = JvListView1->Selected;
    ProcessSelectedFile(selectedItem, this, JvImage1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject* Sender)
{
    GdiplusStartupInput gdiplusStartupInput;
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject* Sender, TCloseAction &Action)
{
    GdiplusShutdown(gdiplusToken);
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TForm1::JvListView1SelectItem(
    TObject* Sender, TListItem* Item, bool Selected)

{
    TListItem* selectedItem = JvListView1->Selected;
    ProcessSelectedFile(selectedItem, this, JvImage1);
}
//---------------------------------------------------------------------------

