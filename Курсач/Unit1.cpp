﻿//---------------------------------------------------------------------------

#include <vcl.h>
#include <vector>
#include <time.h>
#include <Registry.hpp>
#include <locale.h>
#pragma hdrstop

#include "money.h"
#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
String date;
String timeL;
vector<Wallet> wallets;
vector<TLabel*> expensesLabels;
vector<TLabel*> incomeLabels;
float totalExpenses = 0;
float totalIncome = 0;
int chosenWallet = -1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	expensesLabels = {Label9, Label10, Label11, Label12, Label13, Label14, Label15, Label16, Label17};
    incomeLabels = {Label18, Label19, Label20, Label21};

    TRegistry *reg = new TRegistry();
	reg->RootKey=HKEY_CURRENT_USER;
	reg->OpenKey("Software\\Microsoft\\Windows\\CurrentVersion\\Run",true);
	reg->WriteString("MoneyManager",Application->ExeName);
	reg->CloseKey();

	TBorderIcons tempBI = BorderIcons;
    tempBI >> biMaximize;
	BorderIcons = tempBI;

	initialization(&wallets, "C:\\Users\\ilyap\\source\\repos\\Курсач\\Win32\\Debug\\data.txt");

	for (int i = 0; i < wallets.size(); i++)
	{
		ComboBox1 -> Items -> Add(wallets[i].name.c_str());
	}

	Application->OnMinimize = ApplicationMinimize;

	date = Date().FormatString("dd.mm.yyyy");
	timeL = Time().FormatString("hh:mm:ss");
	Label1 -> Caption = date;
    Label6 -> Caption = timeL;

    DWORD nSize=4096;
	TCHAR lpBuffer[4096];
	GetUserName(lpBuffer,&nSize);
	Label2 -> Caption=AnsiString(lpBuffer);

	checkAutoPays(&wallets, "C:\\Users\\ilyap\\source\\repos\\Курсач\\Win32\\Debug\\auto.txt");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TrayIcon1Click(TObject *Sender)
{
	TrayIcon1 -> Visible = false;
	ShowWindow(Form1->Handle, SW_SHOW);
    Form1 -> Visible = True;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ApplicationMinimize(TObject *Sender)
{
    TrayIcon1->Visible = true;
	ShowWindow(Form1->Handle, SW_HIDE);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
    Application->ShowMainForm = false;
    TrayIcon1->Visible = true;
	ShowWindow(Form1->Handle, SW_HIDE);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	timeL = Time().FormatString("hh:mm:ss");
    Label6 -> Caption = timeL;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox2Change(TObject *Sender)
{
	printMoney(ComboBox2 -> ItemIndex, Label8, wallets[chosenWallet].money);
    printTotalMoney(ComboBox2 -> ItemIndex, Label22, totalExpenses);
	printTotalMoney(ComboBox2 -> ItemIndex, Label23, totalIncome);
	printTotalMoney(ComboBox2 -> ItemIndex, Label24, totalIncome - totalExpenses);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton15Click(TObject *Sender)
{
    Form2 -> ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCloseQuery(TObject *Sender, bool &CanClose)
{
    synchronization(wallets, "C:\\Users\\ilyap\\source\\repos\\Курсач\\Win32\\Debug\\data.txt");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
	SpeedButton15 -> Enabled = True;
	SpeedButton17 -> Enabled = True;
	SpeedButton18 -> Enabled = True;
    ComboBox2 -> Enabled = True;
	chosenWallet = ComboBox1 -> ItemIndex;
	printMoney(ComboBox2 -> ItemIndex, Label8, wallets[chosenWallet].money);
	totalExpenses = expenses(expensesLabels, wallets[chosenWallet].name, "C:\\Users\\ilyap\\source\\repos\\Курсач\\Win32\\Debug\\discharge.txt");
	totalIncome = income(incomeLabels, wallets[chosenWallet].name, "C:\\Users\\ilyap\\source\\repos\\Курсач\\Win32\\Debug\\discharge.txt");
	printTotalMoney(ComboBox2 -> ItemIndex, Label22, totalExpenses);
	printTotalMoney(ComboBox2 -> ItemIndex, Label23, totalIncome);
	printTotalMoney(ComboBox2 -> ItemIndex, Label24, totalIncome - totalExpenses);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton17Click(TObject *Sender)
{
	String flag;
	if (SpeedButton1 -> Down == True) flag = "развлечения ";
	else if (SpeedButton2 -> Down == True) flag = "такси ";
	else if (SpeedButton3 -> Down == True) flag = "жильё ";
	else if (SpeedButton4 -> Down == True) flag = "еда ";
	else if (SpeedButton5 -> Down == True) flag = "одежда ";
	else if (SpeedButton6 -> Down == True) flag = "здоровье ";
	else if (SpeedButton7 -> Down == True) flag = "транспорт ";
	else if (SpeedButton8 -> Down == True) flag = "путешествия ";
	else if (SpeedButton10 -> Down == True) flag = "прочее(расход) ";
	float money = moneyConvert(ComboBox2 -> ItemIndex, StrToFloat(Edit1 -> Text));;
	moneyWithdraw(&wallets[chosenWallet], money, "C:\\Users\\ilyap\\source\\repos\\Курсач\\Win32\\Debug\\discharge.txt", flag);
	printMoney(ComboBox2 -> ItemIndex, Label8, wallets[chosenWallet].money);
	totalExpenses = expenses(expensesLabels, wallets[chosenWallet].name, "C:\\Users\\ilyap\\source\\repos\\Курсач\\Win32\\Debug\\discharge.txt");
	totalIncome = income(incomeLabels, wallets[chosenWallet].name, "C:\\Users\\ilyap\\source\\repos\\Курсач\\Win32\\Debug\\discharge.txt");
	printTotalMoney(ComboBox2 -> ItemIndex, Label22, totalExpenses);
	printTotalMoney(ComboBox2 -> ItemIndex, Label23, totalIncome);
	printTotalMoney(ComboBox2 -> ItemIndex, Label24, totalIncome - totalExpenses);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton18Click(TObject *Sender)
{
    String flag;
	if (SpeedButton11 -> Down == True) flag = "зарплата ";
	else if (SpeedButton12 -> Down == True) flag = "подарки ";
	else if (SpeedButton13 -> Down == True) flag = "ставки ";
	else if (SpeedButton14 -> Down == True) flag = "прочее(доход) ";
	float money = moneyConvert(ComboBox2 -> ItemIndex, StrToFloat(Edit2 -> Text));
	moneyTopUp(&wallets[chosenWallet], money, "C:\\Users\\ilyap\\source\\repos\\Курсач\\Win32\\Debug\\discharge.txt", flag);
	printMoney(ComboBox2 -> ItemIndex, Label8, wallets[chosenWallet].money);
	totalExpenses = expenses(expensesLabels, wallets[chosenWallet].name, "C:\\Users\\ilyap\\source\\repos\\Курсач\\Win32\\Debug\\discharge.txt");
	totalIncome = income(incomeLabels, wallets[chosenWallet].name, "C:\\Users\\ilyap\\source\\repos\\Курсач\\Win32\\Debug\\discharge.txt");
	printTotalMoney(ComboBox2 -> ItemIndex, Label22, totalExpenses);
	printTotalMoney(ComboBox2 -> ItemIndex, Label23, totalIncome);
	printTotalMoney(ComboBox2 -> ItemIndex, Label24, totalIncome - totalExpenses);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton16Click(TObject *Sender)
{
    Form3 -> ShowModal();
}
//---------------------------------------------------------------------------



