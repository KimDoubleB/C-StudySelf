#include "Account.h"
// 오류 메세지 확인 클래스 만들자
// --> Exception class

void Account::deposit(int money){

	if (money < 0)
		throw NegativeException(money);
	this->inMoney += money;
}

void Account::withdraw(int money){
	if (this->inMoney < money)
		throw WithdrawException(money);
	else if (money < 0)
		throw NegativeException(money);

	this->inMoney -= money;
}

void Account::printAccount() const {
	cout << endl << "계좌ID: " << this->id << endl;
	cout << "이 름: " << this->name << endl;
	cout << "잔 액: " << this->inMoney << endl;
}
/* No need
(String class를 도입함으로써 멤버간 Shallow copy더라도 deep copy가 된다.

Account& Account::operator=(const Account& copy) {
	delete[] name;
	this->id = copy.id;
	this->inMoney = copy.inMoney;

	this->name = new char[strlen(copy.name) + 1];
	strcpy(this->name, copy.name);

	return (*this);
}
*/