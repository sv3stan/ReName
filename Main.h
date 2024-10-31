//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "JvExExtCtrls.hpp"
#include "JvExtComponent.hpp"
#include "JvPanel.hpp"
#include "JvSplit.hpp"
#include <Vcl.ExtCtrls.hpp>
#include "JvComponentBase.hpp"
#include "JvDragDrop.hpp"
#include "JvExComCtrls.hpp"
#include "JvListView.hpp"
#include <Vcl.ComCtrls.hpp>
#include "JvBaseDlg.hpp"
#include "JvBrowseFolder.hpp"
#include <Vcl.Dialogs.hpp>
#include "JvDialogs.hpp"
#include "JvDriveCtrls.hpp"
#include "JvExStdCtrls.hpp"
#include "JvListBox.hpp"
#include <Vcl.FileCtrl.hpp>
#include "JvCombobox.hpp"
#include "JvImage.hpp"
#include "JvColorBox.hpp"
#include "JvColorButton.hpp"
#include "JvExControls.hpp"
#include "JvArrowButton.hpp"
#include "JvCheckBox.hpp"
#include "JvgGroupBox.hpp"
#include "JvGroupBox.hpp"
#include "JvRadioGroup.hpp"
#include "JvButton.hpp"
#include "JvTransparentButton.hpp"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TJvPanel *JvPanel1;
	TJvxSplitter *JvxSplitter1;
	TJvPanel *JvPanel2;
	TJvxSplitter *JvxSplitter2;
	TJvPanel *JvPanel3;
	TJvxSplitter *JvxSplitter3;
	TJvPanel *JvPanel4;
	TJvxSplitter *JvxSplitter4;
	TJvPanel *JvPanel5;
	TJvPanel *JvPanel6;
	TJvPanel *JvPanel7;
	TJvxSplitter *JvxSplitter5;
	TJvxSplitter *JvxSplitter6;
	TJvPanel *JvPanel8;
	TJvDragDrop *JvDragDrop1;
	TJvListView *JvListView1;
	TJvBrowseForFolderDialog *JvBrowseForFolderDialog1;
	TJvOpenDialog *JvOpenDialog1;
	TLabel *Label1;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label2;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	TLabel *Label13;
	TLabel *Label14;
	TLabel *Label15;
	TLabel *Label16;
	TJvImage *JvImage1;
	TLabel *Label17;
	TLabel *Label18;
	TLabel *Label19;
	TLabel *Label20;
	TLabel *Label21;
	TLabel *Label22;
	TLabel *Label23;
	TLabel *Label24;
	TLabel *Label25;
	TLabel *Label26;
    TJvRadioGroup *JvRadioGroup1;
    TJvGroupBox *JvGroupBox1;
    TJvCheckBox *JvCheckBox5;
    TJvCheckBox *JvCheckBox6;
    TJvCheckBox *JvCheckBox7;
    TJvCheckBox *JvCheckBox8;
    TJvCheckBox *JvCheckBox1;
    TJvCheckBox *JvCheckBox2;
    TJvCheckBox *JvCheckBox3;
    TJvCheckBox *JvCheckBox4;
    TJvGroupBox *JvGroupBox2;
    TJvTransparentButton *JvTransparentButton1;
    TJvTransparentButton *JvTransparentButton2;
    TJvTransparentButton *JvTransparentButton3;
    TJvTransparentButton *JvTransparentButton4;
	void __fastcall JvDragDrop1Drop(TObject *Sender, TPoint &Pos, TStrings *Value);
	void __fastcall JvListView1Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall JvListView1SelectItem(TObject *Sender, TListItem *Item, bool Selected);


private:	// User declarations
void __fastcall ProcessFolder(const UnicodeString &folderPath, TListItems *items);
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
