#include "AccountArray.h"

AccountArray::AccountArray(int len)
	:arrLen(len)
{
	kBank = new AccountPtr[len];
}

AccountPtr& AccountArray::operator[](int idx) {
	if (idx < 0 || idx >= arrLen)
	{
		cout << "Error; Wrong access - Account array" << endl;
		exit(1);
	}

	return kBank[idx];
}
AccountPtr AccountArray::operator[](int idx) const {
	if (idx < 0 || idx >= arrLen)
	{
		cout << "Error; Wrong access - Account array" << endl;
		exit(1);
	}

	return kBank[idx];
}
