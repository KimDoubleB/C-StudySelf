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
		Account::deposit(money); // �ݾ� �Ա�
		Account::deposit((int)(money * getRate())); // ���� �߰�
	}
	void printAccount() const {
		Account::printAccount();
		cout << "������: " << (int)(getRate()*100) << endl;
	}

};

#endif