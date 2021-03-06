//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit3.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
    ComboBox1 -> Items = Form1 -> ComboBox1 -> Items;
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button1Click(TObject *Sender)
{
	String newAuto = "";
	newAuto += DateToStr(DateTimePicker1 -> Date);
    newAuto += " ";
	newAuto += Edit2 -> Text;
	newAuto += " ";
	newAuto += ComboBox1 -> Items -> Strings[ComboBox1->ItemIndex].c_str();
	newAuto += " ";
	newAuto += Edit4 -> Text;
    newAuto += " ";
	newAuto += Edit5 -> Text;
	Form3 -> ListBox1 -> Items -> Add(newAuto);
    DateTimePicker1 -> Date = Date();
	Edit2 -> Text = "";
    ComboBox1 -> ItemIndex = -1;
	Edit4 -> Text = "";
	Edit5 -> Text = "";
    ModalResult = mrOk;
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button2Click(TObject *Sender)
{
    DateTimePicker1 -> Date = Date();
	Edit2 -> Text = "";
    ComboBox1 -> ItemIndex = -1;
	Edit4 -> Text = "";
	Edit5 -> Text = "";
    ModalResult = mrCancel;
}
//---------------------------------------------------------------------------

void __fastcall TForm4::FormCloseQuery(TObject *Sender, bool &CanClose)
{
    DateTimePicker1 -> Date = Date();
	Edit2 -> Text = "";
    ComboBox1 -> ItemIndex = -1;
	Edit4 -> Text = "";
	Edit5 -> Text = "";
}
//---------------------------------------------------------------------------

