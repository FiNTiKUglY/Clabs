//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ComCtrls.hpp>
#include <IdBaseComponent.hpp>
#include <IdSASL.hpp>
#include <IdSASLSKey.hpp>
#include <IdSASLUserPass.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.Imaging.jpeg.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TSpeedButton *SpeedButton3;
	TSpeedButton *SpeedButton7;
	TTrayIcon *TrayIcon1;
	TSpeedButton *SpeedButton1;
	TSpeedButton *SpeedButton2;
	TSpeedButton *SpeedButton4;
	TSpeedButton *SpeedButton5;
	TSpeedButton *SpeedButton6;
	TComboBox *ComboBox1;
	TSpeedButton *SpeedButton8;
	TComboBox *ComboBox2;
	TSpeedButton *SpeedButton10;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TShape *Shape1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label6;
	TTimer *Timer1;
	TLabel *Label7;
	TLabel *Label8;
	TSpeedButton *SpeedButton11;
	TSpeedButton *SpeedButton12;
	TSpeedButton *SpeedButton13;
	TSpeedButton *SpeedButton14;
	TSpeedButton *SpeedButton15;
	TSpeedButton *SpeedButton16;
	TSpeedButton *SpeedButton17;
	TSpeedButton *SpeedButton18;
	TEdit *Edit1;
	TEdit *Edit2;
	TImage *Image1;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label14;
	TLabel *Label13;
	TLabel *Label12;
	TLabel *Label17;
	TLabel *Label16;
	TLabel *Label15;
	TLabel *Label18;
	TLabel *Label19;
	TLabel *Label20;
	TLabel *Label21;
	TLabel *Label22;
	TLabel *Label23;
	TLabel *Label24;
	void __fastcall TrayIcon1Click(TObject *Sender);
	void __fastcall ApplicationMinimize(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall ComboBox2Change(TObject *Sender);
	void __fastcall SpeedButton15Click(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall ComboBox1Change(TObject *Sender);
	void __fastcall SpeedButton17Click(TObject *Sender);
	void __fastcall SpeedButton18Click(TObject *Sender);
	void __fastcall SpeedButton16Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
