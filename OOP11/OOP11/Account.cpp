#include "Account.h"
// ���� �޼��� Ȯ�� Ŭ���� ������
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
	cout << endl << "����ID: " << this->id << endl;
	cout << "�� ��: " << this->name << endl;
	cout << "�� ��: " << this->inMoney << endl;
}
/* No need
(String class�� ���������ν� ����� Shallow copy���� deep copy�� �ȴ�.

Account& Account::operator=(const Account& copy) {
	delete[] name;
	this->id = copy.id;
	this->inMoney = copy.inMoney;

	this->name = new char[strlen(copy.name) + 1];
	strcpy(this->name, copy.name);

	return (*this);
}
*/