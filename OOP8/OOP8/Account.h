#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include <iostream>
#include <cstring>
#include "BankingCommonDecl.h"

using namespace std;

class Account {
private:
	int id;
	char* name;
	int inMoney;

public:
	// Constructor
	Account(int id, char* name, int money)
		: id(id), inMoney(money)
	{
		this->setName(name);
	}
	// Copying Constructor (for deep copy)
	Account(const Account &copy)
		:id(copy.id), inMoney(copy.inMoney)
	{
		name = new char[strlen(copy.name) + 1];
		strcpy(name, copy.name);
	}

	// Mutators
	void setId(int id)
	{
		this->id = id;
	}
	void setName(char* name) {
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
	void setMoney(int money) {
		this->inMoney = money;
	}
	// Accessers
	int getId() const { return id; }
	char* getName() const { return name; }
	int getMoney() const { return inMoney; }

	// Functions
	virtual void deposit(int money);
	void withdraw(int money);
	virtual void printAccount() const;

	// Overloading operator
	Account& operator=(const Account& copy);
	
	// Destructor
	virtual ~Account() {
		delete[] name;
	}
};

#endif