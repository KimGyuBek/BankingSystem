#ifndef __HIGHCREDIT_ACCOUNT__
#define __HIGHCREDIT_ACCOUNT__

#include "NormalAccount.h"

class HighCreditAccount :public NormalAccount
{
	private:
		int specialRate;
	public:
		HighCreditAccount(int ID, int balance, const char *cusName, int rate, int special)
			:NormalAccount(ID, balance, cusName, rate), specialRate(special)
		{}

		virtual void Deposit(int money)
		{
			NormalAccount::Deposit(money);
			NormalAccount::Deposit(money*(specialRate/100.0));
		}
};

#endif
