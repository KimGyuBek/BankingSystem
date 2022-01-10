#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "String.h"
#include "AccountException.h"

class Account
{
	private:
		
		int accID;
		int balance;
		String cusName;
	public:
		Account(int ID, int money, String cusName);
//		Account(const Account &ref);
//		Account& operator=(const Account& ref);

		int GetAccID() const;
		virtual void Deposit(int money); 
		int Withdraw(int money); 
		void ShowAccInfo() const;
//		~Account();
};

#endif
