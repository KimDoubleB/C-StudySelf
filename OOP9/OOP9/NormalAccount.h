#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "Account.h"

class NormalAccount : public Account
{
private:
	double rate;
public:
	NormalAccount(int id, String name, int money, double rate)
		: Account(id, name, money)
	{
		this->rate = rate * 0.01;
	}

	void setRate(double rate) { this->rate = rate; }
	double getRate() const { return rate; }

	// Overriding
	void deposit(int money) {
		Account::deposit(money); // 금액 입금
		Account::deposit((int)(money * getRate())); // 이자 추가
	}
	void printAccount() const {
		Account::printAccount();
		cout << "이자율: " << (int)(getRate()*100) << endl;
	}

};

#endif