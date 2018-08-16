#include "Account.h"
// ���� �޼��� Ȯ�� Ŭ���� ������
// --> Exception class

void Account::deposit(int money) {
	this->inMoney += money;
}

void Account::withdraw(int money) {
	if (this->inMoney < money)
	{
		cout << endl << "-����; �Է��Ͻ� �ݾ��� ���� ���¿� �����ϴ� �ݾ׺��� Ů�ϴ�." << endl << "Ȯ�� ��Ź�帳�ϴ�." << endl;
		return;
	}

	this->inMoney -= money;
}

void Account::printAccount() const {
	cout << endl << "����ID: " << this->id << endl;
	cout << "�� ��: " << this->name << endl;
	cout << "�� ��: " << this->inMoney << endl;
}
