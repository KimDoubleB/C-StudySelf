#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include <iostream>
#include <cstring>
#include "BankingCommonDecl.h"
#include "String.h"
#include "Exception.h"

using namespace std;

class Account {
private:
	int id;
	String name;
	int inMoney;

public:
	// Constructor
	Account(int id, String name, int money)
		: id(id), inMoney(money), name(name)
	{
		if (money < 0)
			throw NegativeException(money);
	}

	/* No need
	(String class를 도입함으로써 멤버간 Shallow copy더라도 deep copy가 된다.

	// Copying Constructor (for deep copy)
	Account(const Account &copy)
		:id(copy.id), inMoney(copy.inMoney)
	{
		name = new char[strlen(copy.name) + 1];
		strcpy(name, copy.name);
	}

	// Overloading operator
	Account& operator=(const Account& copy);
	*/

	// Mutators
	void setId(int id)
	{
		this->id = id;
	}
	void setName(String name) {
		this->name = name;
	}
	void setMoney(int money) {
		this->inMoney = money;
	}
	// Accessers
	int getId() const { return id; }
	String getName() const { return name; }
	int getMoney() const { return inMoney; }

	// Functions
	virtual void deposit(int money);
	void withdraw(int money);
	virtual void printAccount() const;

};

#endif