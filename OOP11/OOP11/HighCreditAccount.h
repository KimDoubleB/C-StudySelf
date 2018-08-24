#ifndef __HIGH_CREDIT_ACCOUNT_H__
#define __HIGH_CREDIT_ACCOUNT_H__

#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount
{
private:
	double rate, creditRate;
public:
	HighCreditAccount(int id, String name, int money, double rate, int creditRate)
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
		default:
			throw SpecialException("잘못된 신용등급입니다.");
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
		cout << "신용등급에 따른 추가 이율: " << getCreditRate() << endl;
	}

};

#endif
