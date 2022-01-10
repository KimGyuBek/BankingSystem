#ifndef __ACCOUNT_CHECK_ARRAY_H__
#define __ACCOUNT_CHECK_ARRAY_H__

#include "BankingCommonDecl.h"

template <typename T>
class BoundCheckArray
{
	private:
		T *arr;
		int arrLen;
		BoundCheckArray(const BoundCheckArray &arr) {}
		BoundCheckArray& operator= (const BoundCheckArray& arr) {}
	public:
		BoundCheckArray(int len = 100);
		T& operator[] (int idx);
		T operator[] (int idx) const;
		int GetArrLen() const;
		~BoundCheckArray();
};

template<typename T>
BoundCheckArray<T>::BoundCheckArray(int len)
	:arrLen(len)
{
	arr = new T[len];
}

template<typename T>
T& BoundCheckArray<T>::operator[] (int idx)
{
	if(idx < 0 || idx > arrLen)
	{
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}

template<typename T>
T BoundCheckArray<T>::operator[] (int idx) const
{
	if(idx < 0 || idx > arrLen)
	{
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}

template<typename T>
int BoundCheckArray<T>::GetArrLen() const
{
	return arrLen;
}

template<typename T>
BoundCheckArray<T>::~BoundCheckArray()
{
	delete []arr;
}
	
#endif
