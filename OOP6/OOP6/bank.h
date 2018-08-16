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

namespace CREDIT_RATE {
	enum {
		RATE_A = 1,
		RATE_B = 2,
		RATE_C = 3
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
	virtual void deposit(int money);
	void withdraw(int money);
	virtual void printAccount() const;

	// Destructor
	virtual ~Account() {
		delete[] name;
	}
};

class NormalAccount : public Account
{
private:
	double rate;
public:
	NormalAccount(int id, char* name, int money, double rate)
		: Account(id, name, money)
	{
		this->rate = rate * 0.01;
	}

	void setRate(double rate) { this->rate = rate; }
	double getRate() const { return rate; }
	void deposit(int money);
	void printAccount() const;

};

class HighCreditAccount : public NormalAccount
{
private:
	double rate, creditRate;
public:
	HighCreditAccount(int id, char* name, int money, double rate, int creditRate)
		: NormalAccount(id, name, money, rate)
	{
		switch (creditRate) {
		case CREDIT_RATE::RATE_A:
			this->creditRate = 0.07;
			break;
		case CREDIT_RATE::RATE_B:
			this->creditRate = 0.04;
			break;
		case CREDIT_RATE::RATE_C:
			this->creditRate = 0.02;
			break;
		}
	}
	void setCreditRate(int creditRate) { this->creditRate = creditRate; }
	double getCreditRate() const { return creditRate; }
	void deposit(int money);
	void printAccount() const;

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