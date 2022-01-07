#include "BankingCommonDecl.h"
#include "Account.h"

Account::Account(int ID, int money, String cusName)
	:accID(ID), balance(money)
{
//	this->cusName = new char[strlen(cusName)+1];
//	strcpy(this->cusName, cusName);
	
	this->cusName = cusName;
}

//Account::Account(const Account &ref)
//	:accID(ref.accID), balance(ref.balance)
//{
//	cusName = new char[strlen(ref.cusName)+1];
//	strcpy(cusName, ref.cusName);
//}
//
//Account& Account::operator=(const Account& ref)
//{
//	accID = ref.accID;
//	balance = ref.balance;
//
//	delete []cusName;
//	cusName = new char[strlen(ref.cusName)+1];
//	strcpy(cusName, ref.cusName);
//
//	return *this;
//}

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
	return balance;
}

void Account::ShowAccInfo() const
{
	cout << "계좌 ID : " << accID << endl;
	cout << "이름 : " << cusName << endl;
	cout << "잔액  : " << balance << endl;
}

//Account::~Account()
//{
//	delete []cusName;
//}
