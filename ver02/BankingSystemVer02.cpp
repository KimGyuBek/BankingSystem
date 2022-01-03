#include<iostream>
#include<cstring>

using namespace std;

const int NAME_LEN = 20;

void ShowMenu(void);
void MakeAccount(void);
void DepositMoney(void);
void WithdrawMoney(void);
void ShowAllAccInfo(void);

enum {MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

class Account
{
	private:
		int accID;
		int balance;
		char *cusName;
	public:
		Account(int ID, int money, char *name) 
			:accID(ID), balance(money)
		{
			cusName = new char[strlen(name)+1];
			strcpy(cusName, name);

		}
		int GetAccID() {return accID;}

		void Deposit(int money)
		{
			balance += money;
		}

		int Withdraw(int money)
		{
			if(balance < money)
				return 0;
			balance -=money;
			return money;
		}

		void ShowAccInfo()
		{
			cout << "계좌 ID : " << accID << endl;
			cout << "이   름 : " << cusName << endl;
			cout << "잔   액 : " << balance << endl;
		}

		~Account()
		{
			delete []cusName;
		}
};

Account *accArr[100];
int accNum = 0;

int main(void)
{
	int choice;

	while(1)
	{
		ShowMenu();
		cout << "선택 ";
		cin >> choice;
		cout << endl;

		switch(choice)
		{
			case MAKE:
				MakeAccount();
				break;
			case DEPOSIT:
				DepositMoney();
				break;
			case WITHDRAW:
				WithdrawMoney();
				break;
			case INQUIRE:
				ShowAllAccInfo();
				break;
			case EXIT:
				for(int i = 0; i<accNum; i++)
					delete accArr[i];
				return 0;

			default:
				cout<<"Illegal selection..." << endl;


		}

	}
	return 0;

}

void ShowMenu(void)
{
	cout << "----------Menu----------" <<endl;
	cout << "1. 입금 계좌 개설" << endl;
	cout << "2. 입          금" << endl;
	cout << "3. 출          금" << endl;
	cout << "4. 계좌 정보 전체 출" << endl;
	cout << "5. Exit" << endl;
}

void MakeAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[계좌 개설]" << endl;
	cout << "계좌   ID : "; cin >> id;
	cout << "이     름 : "; cin >> name;
	cout << "입금 금액 : "; cin >> balance;
	cout << endl;

	accArr[accNum++] = new Account(id, balance, name);
}

void DepositMoney(void)
{
	int money;
	int id;

	cout << "[입    금]" << endl;
	cout << "계좌  ID : "; cin >> id;
	cout << "입 금 액 : "; cin >> money;
        cout << endl;

	for(int i = 0; i<accNum; i++)
	{
		if(accArr[i]->GetAccID() == id)
		{
			accArr[i]->Deposit(money);
			cout << "입금 완료"<<endl;
			return;
		}
		cout << "유효하지 않은 ID 입니다. " << endl;
	}


}

void WithdrawMoney(void)
{
	int money;
	int id;
	
	cout<< "[출   금]"<< endl;
	cout << "계좌 ID"; cin >> id;
	cout <<"출 금 액 : "; cin >> money;
	cout << endl;

	for(int i = 0; i<accNum; i++)
	{
		if(accArr[i]->GetAccID() == id)
		{
			if(accArr[i]->Withdraw(money) == 0)
			{
				cout << "잔액 부족" << endl;
				return;
			}
			cout << "출금 완료" << endl;
			return;
		}
	}

}

void ShowAllAccInfo(void) 
{

	for(int i = 0; i<accNum; i++)
	{
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}

