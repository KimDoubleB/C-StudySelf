#ifndef __HIGH_CREDIT_ACCOUNT_H__
#define __HIGH_CREDIT_ACCOUNT_H__

#include "NormalAccount.h"

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

	// Overriding
	void deposit(int money) {
		NormalAccount::deposit(money); // 입금&이자 추가
		Account::deposit((int)(money * getCreditRate())); // 추가 이자 추가
	}
	void printAccount() const {
		NormalAccount::printAccount();
		cout << "신용등급(1toA, 2toB, 3toC): " << getCreditRate() << endl;
	}

};

#endif
