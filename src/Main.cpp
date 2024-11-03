//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "../include/Utils.h"
#include "../include/ExifUtils.h"
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
#pragma resource "*.dfm"
ULONG_PTR gdiplusToken;
TForm1* Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {}
//---------------------------------------------------------------------------

void __fastcall TForm1::JvDragDrop1Drop(
    TObject* Sender, TPoint &Pos, TStrings* Value)

{
    storeDraggedFilesToMap(Value);

    // ShowMessage("End");
    fromMapToStoreListView(JvListView1, Value);

    //    String str = itemMap.size();
    //    JvStatusBar1->Panels->Items[0]->Text =
    //    JvStatusBar1->Panels->Items[0]->Text + str;

    // Устанавливаем ширину столбцов, если это необходимо
    JvListView1->Columns->Items[0]->AutoSize =
        true; // Ширина для первого столбца (имя файла)
    JvListView1->Columns->Items[1]->AutoSize =
        true;

    //Form1->JvStatusBar1->Panels->Items[0]->Text = "Всего файлов: " + UnicodeString(itemMap.size());
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

    if (JvCheckBox9->Checked == True) {
        JvListView1->Columns->Items[0]->Width = 80;
    } else {
        JvListView1->Columns->Items[0]->Width = 0;
    }
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
    JvListView1->Columns->Items[2]->Width = 0;
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
    if (ColumnIndex == 0) {
        if (JvCheckBox9->Checked == False) {
            CanResize = false;
            JvListView1->Columns->Items[0]->Width = 0;
        } else {
            CanResize = True;
            JvListView1->Columns->Items[0]->Width = 100;
        }
    }

    if (ColumnIndex == 5) {
        if (JvCheckBox1->Checked == False) {
            CanResize = false;
            JvListView1->Columns->Items[5]->Width = 0;
        } else {
            CanResize = True;
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

void __fastcall TForm1::JvCheckBox1Click(TObject* Sender)
{
    if (JvCheckBox1->Checked == True) {
        JvListView1->Columns->Items[5]->Width = 80;
    } else {
        JvListView1->Columns->Items[5]->Width = 0;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::JvCheckBox2Click(TObject* Sender)
{
    if (JvCheckBox2->Checked == True) {
        JvListView1->Columns->Items[7]->Width = 80;
    } else {
        JvListView1->Columns->Items[7]->Width = 0;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::JvCheckBox3Click(TObject* Sender)
{
    if (JvCheckBox3->Checked == True) {
        JvListView1->Columns->Items[9]->Width = 80;
    } else {
        JvListView1->Columns->Items[9]->Width = 0;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::JvCheckBox4Click(TObject* Sender)
{
    if (JvCheckBox4->Checked == True) {
        JvListView1->Columns->Items[11]->Width = 80;
    } else {
        JvListView1->Columns->Items[11]->Width = 0;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::JvCheckBox9Click(TObject* Sender)
{
    if (JvCheckBox9->Checked == True) {
        JvListView1->Columns->Items[0]->Width = 80;
    } else {
        JvListView1->Columns->Items[0]->Width = 0;
    }
}
//---------------------------------------------------------------------------

