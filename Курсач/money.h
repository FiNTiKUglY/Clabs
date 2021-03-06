//---------------------------------------------------------------------------

#ifndef moneyH
#define moneyH
#include <vcl.h>
#include "Unit1.h"
#include <vector>
using namespace std;
//---------------------------------------------------------------------------
#endif

class Wallet
{
    public:
	String name;
    float money;
};

void initialization(vector<Wallet> *list, String fileName);
void discharge(Wallet acc, String text, String fileName);
void synchronization(vector<Wallet> list, String fileName);
void moneyWithdraw(Wallet* acc, float money, String fileName, String flag);
void moneyTopUp(Wallet* acc, float money, String fileName, String flag);
void printMoney(int index, TLabel* Label8, float money);
float moneyConvert(int index, float money);
void checkAutoPays(vector<Wallet> *list, String fileName);
int getIndex(vector<Wallet> list, String name);
float expenses(vector<TLabel*> labels, String walletName, String fileName);
float income(vector<TLabel*> labels, String walletName, String fileName);
float totalMoney(vector<float> amounts);
void printTotalMoney(int index, TLabel* Label, float money);
