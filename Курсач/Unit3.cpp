//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	ListBox1 -> Items -> SaveToFile("C:\\Users\\ilyap\\source\\repos\\������\\Win32\\Debug\\auto.txt");
}
//---------------------------------------------------------------------------
void __fastcall TForm3::FormCreate(TObject *Sender)
{
	ListBox1 -> Items -> LoadFromFile("C:\\Users\\ilyap\\source\\repos\\������\\Win32\\Debug\\auto.txt");;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::SpeedButton3Click(TObject *Sender)
{
	ListBox1 -> Items -> Delete(ListBox1 -> ItemIndex);
}
//---------------------------------------------------------------------------

void __fastcall TForm3::SpeedButton1Click(TObject *Sender)
{
	Form4 -> ShowModal();
	Form4 -> DateTimePicker1 -> Date = Date();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::SpeedButton2Click(TObject *Sender)
{
	TStringList *Strings = new TStringList;
	Strings -> DelimitedText = ListBox1 -> Items -> Strings[ListBox1 -> ItemIndex].c_str();
	Form4 -> DateTimePicker1 -> Date = Strings -> Strings[0];
	Form4 -> Edit2 -> Text = Strings -> Strings[1];
	Form4 -> Edit4 -> Text = Strings -> Strings[3];
	Form4 -> Edit5 -> Text = Strings -> Strings[4];
	if (Form4 -> ShowModal() == mrOk)
		ListBox1 -> Items -> Delete(ListBox1 -> ItemIndex);
}
//---------------------------------------------------------------------------

