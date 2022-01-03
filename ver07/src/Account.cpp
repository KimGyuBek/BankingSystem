#include "BankingCommonDecl.h"
#include "Account.h"

Account::Account(int ID, int money, const char *cusName)
	:accID(ID), balance(money)
{
	this->cusName = new char[strlen(cusName)+1];
	strcpy(this->cusName, cusName);
}

Account::Account(const Account &ref)
	:accID(ref.accID), balance(ref.balance)
{
	cusName = new char[strlen(ref.balance)+1];
	strcpy(cusName, ref.cusName);
}

int Account::GetAccID() const
{
	return accID;
}

void Account::Deposit(int money)
{
	balance += money;
}

int Account::Withdraw(int money)
{
	if(balance < money)
		return 0;
	balance -= money;
}

void Account::ShowAccInfo() const
{
	cout << "계좌 ID : " << accID << endl;
	cout << "이름 : " << cusName << endl;
	cout << "잔액  : " << balance << endl;
}

Account::~Account()
{
	delete []cusName;
}
