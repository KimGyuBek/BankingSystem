#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"
//#include "AccountArray.h"
#include "BoundCheckArray.h"

class AccountHandler
{
	private:
		int accNum;
//		BoundCheckAccountPtrArray accArr;
		BoundCheckArray<Account*> accArr;
	public:
		AccountHandler();
		void ShowMenu() const;
		void MakeAccount(void);
		void DepositMoney(void);
		void WithdrawMoney(void);
		void ShowAllAccInfo(void) const;
		~AccountHandler();

	protected:
		void MakeNormalAccount(void);
		void MakeCreditAccount(void);
};

#endif
