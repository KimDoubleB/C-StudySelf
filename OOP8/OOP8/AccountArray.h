#ifndef __ACCOUNT_ARRAY_H__
#define __ACCOUNT_ARRAY_H__

#include "Account.h"
#include <cstdlib>
typedef Account* AccountPtr;
class AccountArray {
private:
	AccountPtr * kBank;
	int arrLen;
public:
	AccountArray(int len = 100);

	AccountPtr& operator[](int idx);
	AccountPtr operator[](int idx) const;

	int getArrLen() { return arrLen; }
	~AccountArray() { delete[] kBank; }
};
#endif