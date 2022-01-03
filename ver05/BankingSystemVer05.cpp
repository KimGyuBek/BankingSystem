#include<iostream>
#include<cstring>

using namespace std;
const int NAME_LEN = 20;

enum {MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

class Account
{
	private:
		int accID;
		int balance;
		char *cusName;
	public:
		Account(int ID, int money, char * cusName);
		Account(const Account &ref);

		int GetAccID() const;
		void Deposit(int money);
		int Withdraw(int money);
		void ShowAccInfo() const;
		~Account();
};

Account::Account(int ID, int money, char *cusName)
	:accID(ID), balance(money)
{
	this->cusName = new char[strlen(cusName)+1];
	strcpy(this->cusName, cusName);
}

Account::Account(const Account &ref)
	:accID(ref.accID), balance(ref.balance)
{
	this->cusName = new char[strlen(ref.cusName)+1];
	strcpy(this->cusName, ref.cusName);
}

int Account::GetAccID() const {return accID; }

void Account::Deposit(int money)
{
	balance += money;
}

int Account::Withdraw(int money)
{
	if(balance < money)
		return 0;
	balance -=money;
	return money;
}

void Account::ShowAccInfo() const
{
	cout << "계좌 ID : "<< accID << endl;
	cout <<  "이름 : " << cusName << endl;
	cout << "잔액 : " << balance << endl;
}

Account::~Account()
{
	delete []cusName;
}


class AccountHandler
{
	private:
		Account *accArr[100];
		int accNum;
	public:
		AccountHandler();
		void ShowMenu(void) const;
		void MakeAccount(void);
		void DepositMoney(void);
		void WithdrawMoney(void);
		void ShowAllAccInfo() const;
		~AccountHandler();
};

void AccountHandler::ShowMenu(void) const
{
	cout << "----------Menu----------" << endl;
	cout << "1. 계좌 개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void AccountHandler::MakeAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[계좌 개설]" << endl;
	cout << "계좌 ID : "; cin >> id;
	cout << "이름 : "; cin >> name;
	cout << "입금액 : "; cin >> balance;
	cout << endl;

	accArr[accNum++] = new Account(id, balance, name);
}

void AccountHandler::DepositMoney(void)
{
	int money;
	int id;
	
	cout << "[입금] "<< endl;
	cout << "계좌 ID : "; cin >> id;
	cout << "입금액 : "; cin >>money;

	for(int i = 0; i<accNum; i++)
	{
		if(accArr[i]->GetAccID() == id)
		{
			accArr[i]->Deposit(money);
			cout << "입금 완료" << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID입니다" <<endl<< endl;
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
				cout <<  "잔액 부족" << endl;
				return;
			}
			cout << "출금완료" << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다 " <<endl<< endl;
}

AccountHandler::AccountHandler() :accNum(0) {}

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
	{
		delete accArr[i];
	}
}

int main(void)
{
	AccountHandler manager;
	int choice;

	while(1)
	{
		manager.ShowMenu();
		cout << "선택 : "; cin >> choice;
		cout << endl;

		switch(choice)
		{
			case MAKE:
				manager.MakeAccount();
				break;
			case DEPOSIT:
				manager.DepositMoney();
				break;
			case WITHDRAW:
				manager.WithdrawMoney();
				break;
			case INQUIRE:
				manager.ShowAllAccInfo();
				break;
			case EXIT:
				return 0;
			default:
				cout << "Illegal selection..." << endl;
		}
	}
	return 0;
}

