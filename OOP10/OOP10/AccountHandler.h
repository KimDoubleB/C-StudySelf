#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "BoundCheckArray.h"
class AccountHandler {
private:
	BoundCheckArray<Account*> kBank;
	int num;
public:
	AccountHandler() : num(0) {}
	int searchAccout(const int id);
	void printMenu(int& menu);
	void makeAccount();
	void deposit();
	void withdraw();
	void printAccout();
	~AccountHandler();
};

#endif