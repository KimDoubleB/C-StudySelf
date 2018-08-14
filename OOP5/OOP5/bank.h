#ifndef __BANK_H__
#define __BANK_H__

#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LENGTH = 20;

namespace BANK_REQUEST {
	enum {
		MAKE = 1,
		DEPOSIT,
		WITHDRAW,
		INQUIRE,
		EXIT
	};
}

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
	void deposit(int money);
	void withdraw(int money);
	void printAccount() const;

	// Destructor
	~Account() {
		delete[] name;
	}
};

class AccountHandler {
private:
	Account * kBank[100];
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