//---------------------------------------------------------------------------

#include <vcl.h>
#include <vector>
#include <string>
#include <math.h>
#include "money.h"
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
extern vector<Wallet> wallets;
extern int chosenWallet;
TDateTime chosenDate;
TStringList* dischargeList = new TStringList;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::SpeedButton1Click(TObject *Sender)
{
	Memo1 -> Clear();
	for (int i = 0; i < dischargeList->Count; i++) 
	{
		TStringList *Strings = new TStringList;
		Strings->DelimitedText = dischargeList -> Strings[i];
		if (Strings -> Strings[1] != wallets[chosenWallet].name.c_str()) continue;
		TDateTime temp = StrToDate(Strings -> Strings[0]);
		if ((chosenDate.Val - temp.Val) >= 0 && (chosenDate.Val - temp.Val) < 365)
			Memo1 -> Lines -> Add(dischargeList -> Strings[i]);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::SpeedButton2Click(TObject *Sender)
{
	Memo1 -> Clear();
	for (int i = 0; i < dischargeList->Count; i++) 
	{
		TStringList *Strings = new TStringList;
		Strings->DelimitedText = dischargeList -> Strings[i];
		if (Strings -> Strings[1] != wallets[chosenWallet].name.c_str()) continue;
		TDateTime temp = StrToDate(Strings -> Strings[0]);
		if ((chosenDate.Val - temp.Val) >= 0 && (chosenDate.Val - temp.Val) < 31)
			Memo1 -> Lines -> Add(dischargeList -> Strings[i]);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::SpeedButton3Click(TObject *Sender)
{
	Memo1 -> Clear();
	for (int i = 0; i < dischargeList->Count; i++) 
	{
		TStringList *Strings = new TStringList;
		Strings->DelimitedText = dischargeList -> Strings[i];
		if (Strings -> Strings[1] != wallets[chosenWallet].name.c_str()) continue;
		TDateTime temp = StrToDate(Strings -> Strings[0]);
		if ((chosenDate.Val - temp.Val) >= 0 && (chosenDate.Val - temp.Val) < 7)
			Memo1 -> Lines -> Add(dischargeList -> Strings[i]);
	}		
}
//---------------------------------------------------------------------------

void __fastcall TForm2::SpeedButton4Click(TObject *Sender)
{
	Memo1 -> Clear();
	for (int i = 0; i < dischargeList->Count; i++) 
	{
		TStringList *Strings = new TStringList;
		Strings->DelimitedText = dischargeList -> Strings[i];
		if (Strings -> Strings[1] != wallets[chosenWallet].name.c_str()) continue;
		TDateTime temp = StrToDate(Strings -> Strings[0]);
		if (chosenDate.Val == temp.Val) Memo1 -> Lines -> Add(dischargeList -> Strings[i]);
	}		
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	Memo1 -> Clear();	
}
//---------------------------------------------------------------------------

void __fastcall TForm2::DateTimePicker1Change(TObject *Sender)
{
    chosenDate = DateTimePicker1 -> Date;
}
//---------------------------------------------------------------------------


void __fastcall TForm2::FormActivate(TObject *Sender)
{
    DateTimePicker1 -> Date = Date();
	chosenDate = DateTimePicker1 -> Date;
	dischargeList -> LoadFromFile("C:\\Users\\ilyap\\source\\repos\\������\\Win32\\Debug\\discharge.txt");
}
//---------------------------------------------------------------------------

