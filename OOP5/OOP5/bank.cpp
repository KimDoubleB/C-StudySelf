#include "bank.h"

int AccountHandler::searchAccout(const int id) {
	for (int i = 0; i < num; i++) {
		if (id == kBank[i]->getId())
			return i;
	}

	return -1;
}
void AccountHandler::printMenu(int& menu) {
	cout << "-----Menu-----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
	cout << "����: ";
	cin >> menu;
}

void AccountHandler::makeAccount() {
	cout << "[���°���]" << endl;
	int id, money;
	char name[NAME_LENGTH];

	cout << "����ID: ";
	cin >> id;

	cout << "�� ��: ";
	cin >> name;

	cout << "�Աݾ�: ";
	cin >> money;

	kBank[num] = new Account(id, name, money);

	num++;
}

void AccountHandler::deposit() {
	int de_id, de_money, numAccount;
	cout << "[ �� �� ]" << endl;

	cout << "����ID: ";
	cin >> de_id;

	numAccount = searchAccout(de_id);
	if (numAccount == -1)
	{
		cout << "�Է��Ͻ� ����ID�� �������� �ʽ��ϴ�." << endl << "Ȯ�� ��Ź�帳�ϴ�." << endl;
		return;
	}

	cout << "�Աݾ�: ";
	cin >> de_money;

	kBank[numAccount]->deposit(de_money);
}

void AccountHandler::withdraw() {
	int wi_id, wi_money, numAccount;
	cout << "[ �� �� ]" << endl;

	cout << "����ID: ";
	cin >> wi_id;

	numAccount = searchAccout(wi_id);
	if (numAccount == -1)
	{
		cout << "�Է��Ͻ� ����ID�� �������� �ʽ��ϴ�." << endl << "Ȯ�� ��Ź�帳�ϴ�." << endl;
		return;
	}

	cout << "��ݾ�: ";
	cin >> wi_money;

	kBank[numAccount]->withdraw(wi_money);
}


void AccountHandler::printAccout() {
	for (int i = 0; i < num; i++) {
		kBank[i]->printAccount();
	}
}

AccountHandler::~AccountHandler() {
	for (int i = 0; i < num; i++)
		delete kBank[i];
}
void Account::deposit(int money) {
	this->inMoney += money;
	cout << "�ԱݿϷ�" << endl;

}

void Account::withdraw(int money) {
	if (this->inMoney < money)
	{
		cout << "�Է��Ͻ� �ݾ��� ���� ���¿� �����ϴ� �ݾ׺��� Ů�ϴ�." << endl << "Ȯ�� ��Ź�帳�ϴ�." << endl;
		return;
	}

	this->inMoney -= money;
	cout << "��ݿϷ�" << endl;
}

void Account::printAccount() const {
	cout << endl << "����ID: " << this->id << endl;
	cout << "�� ��: " << this->name << endl;
	cout << "�� ��: " << this->inMoney << endl;
}