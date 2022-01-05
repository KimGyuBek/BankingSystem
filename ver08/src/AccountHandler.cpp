#include "BankingCommonDecl.h"
#include "AccountHandler.h"
//#include "Account.h"
#include "Account.cpp"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

void AccountHandler::ShowMenu(void) const
{
	cout << "----------Menu----------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 계좌정보 전체출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void AccountHandler::MakeAccount(void)
{
	int sel;

	cout << "[계좌 종류 선택]" << endl;
	cout << "1. 보통예금계좌" << endl;
	cout << "2. 신용신뢰계좌" << endl; cin >> sel;

	if(sel == NORMAL)
		MakeNormalAccount();
	else
		MakeCreditAccount();
}

void AccountHandler::MakeNormalAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;
	int interRate;

	cout << "[보통예금계좌개설]" << endl;
	cout << "계좌 ID : " ; cin >> id;
	cout << "이름 : " ; cin >>  name;
	cout << "입금액 : "; cin >> balance;
	cout << "이자율 : "; cin >> interRate;
	cout << endl;

	accArr[accNum++] = new NormalAccount(id, balance, name, interRate);
}

void AccountHandler::MakeCreditAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;
	int interRate;
	int creditLevel;

	cout << "[신용신뢰계좌개설]" << endl;
	cout << "계좌 ID : " ; cin >> id;
	cout << "이름 : " ; cin >>  name;
	cout << "입금액 : "; cin >> balance;
	cout << "이자율 : "; cin >> interRate;
	cout << "신용등급 (1toA, 2toB, 3toC) : "; cin >> creditLevel;

	cout << endl;

	switch(creditLevel)
	{
		case 1:
			accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_A);
			break;
		case 2:
			accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_B);
			break;
		case 3:
			accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_C);
			break;
	}
}

void AccountHandler::DepositMoney(void)
{
	int money;
	int id;

	cout << "[입금]" <<  endl;
	cout << "계좌 ID : " ; cin >> id;
	cout << "입금액 : " ; cin >> money;

	for(int i = 0; i<accNum; i++)
	{
		if(accArr[i]->GetAccID() == id)
		{
			accArr[i]->Deposit(money);
			cout << "입금완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID입니다" << endl << endl;
}

void AccountHandler::WithdrawMoney(void)
{
	int money;
	int id;

	cout << "[출금]" << endl;
	cout << "계좌 ID : "; cin >> id;
	cout << "출금액 : "; cin >> money;
	
	for(int i = 0; i<accNum; i++)
	{
		if(accArr[i]->GetAccID() == id)
		{
			if(accArr[i]->Withdraw(money) == 0)
			{
				cout << "잔약부족" << endl << endl;
				return;
			}
			cout << "출금완료" << endl << endl;
			return;
		}
	}
	cout << "존재하지 않은 ID입니다" << endl << endl;
}

AccountHandler::AccountHandler() :accNum(0)
{}

void AccountHandler::ShowAllAccInfo(void) const
{
	for(int i = 0; i<accNum; i++)
	{
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}

AccountHandler::~AccountHandler()
{
	for(int i = 0; i<accNum; i++)
		delete accArr[i];
}




