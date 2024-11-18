//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "../include/Utils.h"
#include "../include/ExifUtils.h"
#include <shlobj.h> // Подключаем заголовок для SHObjectProperties
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
#pragma link "JvStatusBar"
#pragma link "JvBaseDlg"
#pragma link "JvBrowseFolder"
#pragma link "JvButton"
#pragma link "JvCheckBox"
#pragma link "JvComponentBase"
#pragma link "JvDialogs"
#pragma link "JvDragDrop"
#pragma link "JvExComCtrls"
#pragma link "JvExControls"
#pragma link "JvExExtCtrls"
#pragma link "JvExStdCtrls"
#pragma link "JvExtComponent"
#pragma link "JvGroupBox"
#pragma link "JvImage"
#pragma link "JvListView"
#pragma link "JvPanel"
#pragma link "JvRadioGroup"
#pragma link "JvSplit"
#pragma link "JvStatusBar"
#pragma link "JvTransparentButton"
#pragma link "JvTimer"
#pragma link "VirtualTrees.HeaderPopup"
#pragma link "JvMenus"
#pragma link "JvEdit"
#pragma resource "*.dfm"
ULONG_PTR gdiplusToken;
TForm1* Form1;
bool DATE_CREATED_CHECK = false;
bool DATE_MODIFIED_CHECK = false;
bool DATE_OPENED_CHECK = false;
bool DATE_ORIGINAL_CHECK = false;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {}
//---------------------------------------------------------------------------

void __fastcall TForm1::JvDragDrop1Drop(
    TObject* Sender, TPoint &Pos, TStrings* Value)

{
    storeDraggedFilesToMap(Value);

    fromMapToStoreListView(JvListView1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::JvListView1Click(TObject* Sender)
{
    //    TListItem* selectedItem = JvListView1->Selected;
    //    ProcessSelectedFile(selectedItem, this, JvImage1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject* Sender)
{
    GdiplusStartupInput gdiplusStartupInput;
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
    InitGlobalFormatSettings();
    //    DATE_CREATED_CHECK = false;
    //    DATE_MODIFIED_CHECK = false;
    //    DATE_OPENED_CHECK = false;

    //    if (JvCheckBox9->Checked == True) {
    //        JvListView1->Columns->Items[0]->Width = 0;
    //    } else {
    //        JvListView1->Columns->Items[0]->Width = 100;
    //    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject* Sender, TCloseAction &Action)
{
    GdiplusShutdown(gdiplusToken);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::JvListView1SelectItem(
    TObject* Sender, TListItem* Item, bool Selected)

{
    if (Selected && Item != nullptr) {
        // Проверим, что элемент действительно выбран
        if (Item == JvListView1->Selected) {
            ProcessSelectedFile(Item, this, JvImage1);
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::JvCheckBox5Click(TObject* Sender)
{
    JvListView1->Columns->Items[1]->Width = 0;
    JvListView1->Columns->Items[5]->Width = 0;
    JvListView1->Columns->Items[7]->Width = 0;
    JvListView1->Columns->Items[9]->Width = 0;
    JvListView1->Columns->Items[11]->Width = 0;
    JvListView1->Columns->Items[13]->Width = 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::JvTransparentButton3Click(TObject* Sender)
{
    JvListView1->SortOnClick = False;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::JvListView1BeginColumnResize(
    TCustomListView* Sender, int ColumnIndex, int ColumnWidth, bool &CanResize)
{
    if (ColumnIndex == 1) {
        if (JvCheckBox9->Checked == False) {
            CanResize = false;
            JvListView1->Columns->Items[0]->Width = 0;
        } else {
            CanResize = True;
            JvListView1->Columns->Items[0]->Width = 200;
        }
    }

    if (ColumnIndex == 2) {
        if (JvCheckBox9->Checked == False) {
            CanResize = false;
            JvListView1->Columns->Items[5]->Width = 0;
        } else {
            CanResize = True;
            JvListView1->Columns->Items[5]->Width = 200;
        }
    }

    if (ColumnIndex == 5) {
        if (JvCheckBox1->Checked == False) {
            CanResize = false;
            JvListView1->Columns->Items[5]->Width = 0;
        } else {
            CanResize = True;
            JvListView1->Columns->Items[5]->Width = 120;
        }
    }

    if (ColumnIndex == 7) {
        if (JvCheckBox2->Checked == False) {
            CanResize = false;
            JvListView1->Columns->Items[7]->Width = 0;
        } else {
            CanResize = True;
        }
    }

    if (ColumnIndex == 9) {
        if (JvCheckBox3->Checked == False) {
            CanResize = false;
            JvListView1->Columns->Items[9]->Width = 0;
        } else {
            CanResize = True;
        }
    }

    if (ColumnIndex == 11) {
        if (JvCheckBox4->Checked == False) {
            CanResize = false;
            JvListView1->Columns->Items[11]->Width = 0;
        } else {
            CanResize = True;
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::JvCheckBox1Click(
    TObject* Sender) // CheckBox  Filename to date -> date created
{
    if (JvCheckBox1->Checked == True) {
        JvListView1->Columns->Items[5]->Width = 120;
        DATE_CREATED_CHECK = true;
    } else {
        JvListView1->Columns->Items[5]->Width = 0;
        DATE_CREATED_CHECK = false;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::JvCheckBox2Click(
    TObject* Sender) // CheckBox  Filename to date -> date modified
{
    if (JvCheckBox2->Checked == True) {
        JvListView1->Columns->Items[7]->Width = 120;
        DATE_MODIFIED_CHECK = true;
    } else {
        JvListView1->Columns->Items[7]->Width = 0;
        DATE_MODIFIED_CHECK = false;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::JvCheckBox3Click(
    TObject* Sender) // CheckBox  Filename to date -> date opened
{
    if (JvCheckBox3->Checked == True) {
        JvListView1->Columns->Items[9]->Width = 120;

        DATE_OPENED_CHECK = true;
    } else {
        JvListView1->Columns->Items[9]->Width = 0;
        DATE_OPENED_CHECK = false;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::JvCheckBox4Click(TObject* Sender)
{
    if (JvCheckBox4->Checked == True) {
        JvListView1->Columns->Items[11]->Width = 120;
        DATE_ORIGINAL_CHECK = true;
    } else {
        JvListView1->Columns->Items[11]->Width = 0;
        DATE_ORIGINAL_CHECK = false;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::JvCheckBox9Click(TObject* Sender)
{
    if (JvCheckBox9->Checked == True) {
        JvListView1->Columns->Items[2]->Width = 200;
    } else {
        JvListView1->Columns->Items[2]->Width = 0;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::JvTimer1Timer(TObject* Sender)
{
    JvStatusBar1->Panels->Items[1]->Text = UnicodeString(itemMap.size());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::JvListView1CustomDrawItem(TCustomListView* Sender,
    TListItem* Item, TCustomDrawState State, bool &DefaultDraw)
{
    //    // Проверяем, отмечен ли элемент чекбоксом и задаём цвет фона
    //    if (Item->Checked) {
    //        Sender->Canvas->Brush->Color = clGreen;  // Цвет фона для отмеченных элементов
    //        Sender->Canvas->Font->Color = clWhite;   // Цвет текста
    //    } else {
    //        Sender->Canvas->Brush->Color = clWindow; // Цвет фона для обычных элементов
    //        Sender->Canvas->Font->Color = clWindowText;
    //    }
    //
    //    // Выполняем заливку фона
    //    Sender->Canvas->FillRect(Item->DisplayRect(drBounds));
    //
    //    // Рисуем текст элемента вручную
    //    Sender->Canvas->TextOut(Item->DisplayRect(drLabel).Left, Item->DisplayRect(drLabel).Top, Item->Caption);
    //
    //    // Чтобы применить кастомную отрисовку, отключаем стандартную
    //    DefaultDraw = false;

    if (Item->Checked) {
        TRect Rect = Item->DisplayRect(drBounds);
        JvListView1->Canvas->Brush->Color = clGreen;
        JvListView1->Canvas->FillRect(Rect);
        JvListView1->Canvas->Font->Color = clWhite;
        JvListView1->Canvas->TextOut(Rect.Left + 12, Rect.Top, Item->Caption);
        DefaultDraw = false;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::JvListView1CustomDrawSubItem(TCustomListView* Sender,
    TListItem* Item, int SubItem, TCustomDrawState State, bool &DefaultDraw)
{
    // Устанавливаем цвет фона и текста для подэлементов
    //    if (Item->Checked) {
    //        Sender->Canvas->Brush->Color = clGreen;  // Фон для подэлементов отмеченных строк
    //        Sender->Canvas->Font->Color = clWhite;   // Цвет текста для подэлементов
    //    } else {
    //        Sender->Canvas->Brush->Color = clWindow; // Обычный фон для подэлементов
    //        Sender->Canvas->Font->Color = clWindowText;
    //    }
    //
    //    // Вычисляем прямоугольник для текущего подэлемента
    //    TRect SubItemRect = Item->DisplayRect(drBounds);
    //    int leftOffset = 0;
    //
    //    // Суммируем ширину предыдущих столбцов, чтобы найти начало текущего подэлемента
    //    for (int i = 0; i < SubItem; ++i) {
    //        leftOffset += Sender->Columns->Items[i]->Width;
    //    }
    //    SubItemRect.Left += leftOffset;
    //    SubItemRect.Right = SubItemRect.Left + Sender->Columns->Items[SubItem]->Width;
    //
    //    // Заливаем фон для подэлемента
    //    Sender->Canvas->FillRect(SubItemRect);
    //
    //    // Рисуем текст подэлемента
    //    Sender->Canvas->TextOut(SubItemRect.Left + 2, SubItemRect.Top, Item->SubItems->Strings[SubItem - 1]);
    //
    //    // Отключаем стандартную отрисовку для подэлементов
    //    DefaultDraw = false;

    // Получаем область для отображения элемента
    TRect ItemRect = Item->DisplayRect(drBounds);

    // Проверяем, отмечен ли элемент
    if (Item->Checked) {
        ShowMessage("++++++");
        // Задаем цвет фона для отмеченного элемента
        JvListView1->Canvas->Brush->Color = clGreen;
        JvListView1->Canvas->FillRect(ItemRect); // Заливаем фон

        // Устанавливаем цвет шрифта
        JvListView1->Canvas->Font->Color = clWhite;

        // Отрисовка текста для первого столбца
        JvListView1->Canvas->TextOut(
            ItemRect.Left + 2, ItemRect.Top, Item->Caption);

        // Отрисовка текста для остальных столбцов
        for (int i = 1; i < Item->SubItems->Count;
             i++) // Начинаем с первого подэлемента
        {
            // Получаем область для каждого подэлемента
            TRect SubItemRect = Item->DisplayRect(drBounds);
            SubItemRect.Left += JvListView1->Column[i - 1]->Width *
                                i; // Сдвигаем по ширине предыдущих столбцов

            // Отрисовываем текст подэлемента
            JvListView1->Canvas->TextOut(SubItemRect.Left + 2, SubItemRect.Top,
                Item->SubItems->Strings[i - 1]);
        }

        DefaultDraw = false; // Отменяем стандартное рисование
    }
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Path1Click(TObject* Sender)
{
    if (JvCheckBox9->Checked == True) {
        JvListView1->Columns->Items[2]->Width = 200;
    } else {
        JvListView1->Columns->Items[2]->Width = 0;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Mark_Selected_Click(TObject* Sender)
{
    for (int i = 0; i < JvListView1->Items->Count; i++) {
        if (JvListView1->Items->Item[i]->Selected == true) {
            JvListView1->Items->Item[i]->Checked = true;
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Mark_All_Click(TObject* Sender)
{
    for (int i = 0; i < JvListView1->Items->Count; i++) {
        JvListView1->Items->Item[i]->Checked = true;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Unmark_All_Click(TObject* Sender)
{
    for (int i = 0; i < JvListView1->Items->Count; i++) {
        JvListView1->Items->Item[i]->Checked = false;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Unmark_Selected_Click(TObject* Sender)
{
    for (int i = 0; i < JvListView1->Items->Count; i++) {
        if (JvListView1->Items->Item[i]->Selected == true) {
            JvListView1->Items->Item[i]->Checked = false;
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Invert_Marked_Click(TObject* Sender)
{
    for (int i = 0; i < JvListView1->Items->Count; i++) {
        if (JvListView1->Items->Item[i]->Checked == true) {
            JvListView1->Items->Item[i]->Checked = false;
        } else {
            JvListView1->Items->Item[i]->Checked = true;
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Select_All_Click(TObject* Sender)
{
    for (int i = 0; i < JvListView1->Items->Count; i++) {
        JvListView1->Items->Item[i]->Selected = true;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Deselect_All_Click(TObject* Sender)
{
    for (int i = 0; i < JvListView1->Items->Count; i++) {
        JvListView1->Items->Item[i]->Selected = false;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Invert_Selection_Click(TObject* Sender)
{
    for (int i = 0; i < JvListView1->Items->Count; i++) {
        if (JvListView1->Items->Item[i]->Selected == true) {
            JvListView1->Items->Item[i]->Selected = false;
        } else {
            JvListView1->Items->Item[i]->Selected = true;
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Insert_Click(TObject* Sender)
{
    JvOpenDialog1->Options
        << ofAllowMultiSelect; // Allow multiple file selection

    if (JvOpenDialog1->Execute()) {
        TStrings* selectedFiles =
            JvOpenDialog1->Files; // Get the list of selected files as TStrings*
        storeDraggedFilesToMap(selectedFiles);
        fromMapToStoreListView(JvListView1);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Open_With_Click(TObject* Sender)
{
    if (JvListView1->Selected) {
        UnicodeString fullFileName =
            JvListView1->Selected->SubItems->Strings[PATH] +
            JvListView1->Selected->Caption;

        if (FileExists(fullFileName)) {
            SHELLEXECUTEINFO shExecInfo = { 0 };
            shExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
            shExecInfo.fMask = SEE_MASK_INVOKEIDLIST;
            shExecInfo.hwnd = Handle; // Snap to the current form window
            shExecInfo.lpVerb = L"open";
            shExecInfo.lpFile = fullFileName.w_str();
            shExecInfo.lpParameters = NULL;
            shExecInfo.lpDirectory = NULL;
            shExecInfo.nShow = SW_SHOWNORMAL;
            shExecInfo.hInstApp = NULL;

            // Checking the result and error message
            if (!ShellExecuteEx(&shExecInfo)) {
                DWORD err = GetLastError();
                ShowMessage(L"Failed to open file: " + fullFileName +
                            L". Error code: " +
                            UnicodeString(std::to_wstring(err).c_str()));
            }
        } else {
            ShowMessage(L"File not found: " + fullFileName);
        }
    } else {
        ShowMessage(L"Select file to open.");
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Properties_Click(TObject* Sender)
{
    if (JvListView1->Selected) {
        String fullFileName = JvListView1->Selected->SubItems->Strings[PATH] +
                              JvListView1->Selected->Caption;
        if (FileExists(fullFileName)) {
            // Open the file properties window via SHObjectProperties
            SHObjectProperties(0, SHOP_FILEPATH, fullFileName.w_str(), NULL);
        } else {
            ShowMessage(L"File not found: " + fullFileName);
        }
    } else {
        ShowMessage(L"Select file to open.");
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Open_File_Location_Click(TObject* Sender)
{
    if (JvListView1->Selected) {
        String fullFileName = JvListView1->Selected->SubItems->Strings[PATH] +
                              JvListView1->Selected->Caption;
        if (FileExists(fullFileName)) {
            // Create and fill the SHELLEXECUTEINFO structure
            SHELLEXECUTEINFO shExecInfo = { 0 };
            shExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
            shExecInfo.fMask = SEE_MASK_INVOKEIDLIST;
            shExecInfo.hwnd = NULL;
            shExecInfo.lpVerb = L"open";
            shExecInfo.lpFile = L"explorer";
            String params = JvListView1->Selected->SubItems->Strings[1];
            shExecInfo.lpParameters = params.w_str();
            shExecInfo.lpDirectory = NULL;
            shExecInfo.nShow = SW_SHOWNORMAL;
            shExecInfo.hInstApp = NULL;

            // Launch Explorer and select the file
            if (!ShellExecuteEx(&shExecInfo)) {
                ShowMessage(L"Failed to open file directory : " + fullFileName);
            }
        } else {
            ShowMessage(L"File not found: " + fullFileName);
        }
    } else {
        ShowMessage(L"Select file to open.");
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Delete_Click(TObject* Sender)
{
    // Disable rendering of JvListView1 to improve performance
    JvListView1->Items->BeginUpdate();
    for (int i = JvListView1->Items->Count - 1; i >= 0; --i) {
        TListItem* item = JvListView1->Items->Item[i];
        // Checking that the element is selected
        if (item->Selected) {
            // Generate a key and remove it from itemMap
            UnicodeString key = item->SubItems->Strings[1] + item->Caption;
            itemMap.erase(key);
            // Removing an element from JvListView
            item->Delete();
        }
    }
    // Turn rendering back on
    JvListView1->Items->EndUpdate();
    // Update the status bar
    JvStatusBar1->Panels->Items[0]->Text =
        "Total files : " + UnicodeString(itemMap.size());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Delete_All_Click(TObject* Sender)
{
    itemMap.clear();
    JvListView1->Items->Clear();
    JvStatusBar1->Panels->Items[0]->Text =
        "Total files : " + UnicodeString(itemMap.size());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Refresh_Click(TObject* Sender)
{
    JvListView1->Items->Clear();
    fromMapToStoreListView(JvListView1);
}
//---------------------------------------------------------------------------

/**
 * @brief Processes all checked items in JvListView1 and calls the function
 * `setChangedFileDateTime` to set new date and time settings for each file.
 *
 * @param Sender Pointer to the object that triggered the event.
 */
void __fastcall TForm1::Filename_To_Date_Button_Click(
    TObject* Sender) // Filename to date
{
    ApplyFilenameToDate(JvListView1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Filename_To_Date_Click(TObject* Sender)
{
    ApplyFilenameToDate(JvListView1);
}
//---------------------------------------------------------------------------




void __fastcall TForm1::JvTransparentButton2Click(TObject *Sender)
{
GetFileCreationDateTime(JvListView1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DateTemplateEditChange(TObject *Sender)
{
    // Получаем текст шаблона из поля TemplateEdit (TJvEdit)
    UnicodeString templateStr = DateTemplateEdit->Text;

    try
    {
        // Форматируем текущую дату согласно шаблону
        TDateTime currentDate = Date();
        UnicodeString formattedDate = FormatDateTime(templateStr, currentDate);

        // Отображаем результат в поле FormattedDateEdit (TJvEdit)
        FormattedDateEdit->Text = formattedDate;
    }
    catch (const Exception &e)
    {
        // Если шаблон некорректный, выводим сообщение
        FormattedDateEdit->Text = "Invalid format";
    }
}
//---------------------------------------------------------------------------


