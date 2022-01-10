#ifndef __ACCOUNT_EXCEPTION_H__
#define __ACCOUNT_EXCEPTION_H__

class InsuffException
{
	private:
		int balance;
		int reqval;
	public:
		InsuffException(int _balance, int _reqval)
			:balance(_balance), reqval(_reqval)
		{}
		void PrintErrorMessage() const
		{
			cout << "[잔액부족 : " << balance << " ]" << endl;
			cout << reqval << "원 출금 불가" << endl;
		}
};

class MinusException 
{
	private:
		int reqval;
	public:
		MinusException(int _reqval)
			:reqval(_reqval)
		{}
		void PrintErrorMessage() const
		{
			cout << "[Error!]" << endl;
			cout << reqval << "원 : 유효하지 않음" << endl;
		}
};

#endif
