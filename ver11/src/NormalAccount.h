#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "Account.h"
#include "String.h"

class NormalAccount :public Account
{
	private:
		int interRate;
	public:
//		NormalAccount(int ID, int balance, const char *cusName, int rate)
		NormalAccount(int ID, int balance, String cusName, int rate)
			:Account(ID, balance, cusName), interRate(rate)
		{}
		virtual void Deposit(int money)
		{
			Account::Deposit(money);
			Account::Deposit(money*(interRate/100.0));
		}
};

#endif
