#include "AccountHandler.h"

int AccountHandler::searchAccout(const int id) {
	for (int i = 0; i < num; i++) {
		if (id == kBank[i]->getId())
			return i;
	}
	throw IdException();
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
	cout << endl << "[������������]" << endl;
	cout << "1. ���뿹�ݰ��� 2. �ſ�ŷڰ���" << endl;
	cout << "����: ";

	int id, money, subMenu;
	String name;
	double rate;
	
	try {
		cin >> subMenu;
		
		if (subMenu != 1 && subMenu != 2)
			throw MenuException();
		
		cout << "����ID: ";
		cin >> id;

		cout << "�� ��: ";
		cin >> name;

		cout << "�Աݾ�: ";
		cin >> money;

		cout << "������(%): ";
		cin >> rate;

		switch (subMenu) {
		case 1:
			kBank[num] = new NormalAccount(id, name, money, rate);
			break;
		case 2:
			int creditRate;
			cout << "�ſ���(1toA, 2toB, 3toC): ";
			cin >> creditRate;

			kBank[num] = new HighCreditAccount(id, name, money, rate, creditRate);
			break;
		}
		num++;
	}
	catch (Exception& e) {
		e.showException();
	}
}

void AccountHandler::deposit() {
	int de_id, de_money, numAccount;
	cout << "[ �� �� ]" << endl;

	try {
		if (num == 0)
			throw NothingException();

		cout << "����ID: ";
		cin >> de_id;

		numAccount = searchAccout(de_id);

		cout << "�Աݾ�: ";
		cin >> de_money;

		kBank[numAccount]->deposit(de_money);
		cout << "�ԱݿϷ�" << endl;
	}
	catch (Exception& e) {
		e.showException();
	}
}

void AccountHandler::withdraw() {
	int wi_id, wi_money, numAccount;
	cout << "[ �� �� ]" << endl;

	try {
		if (num == 0)
			throw NothingException();

		cout << "����ID: ";
		cin >> wi_id;

		numAccount = searchAccout(wi_id);

		cout << "��ݾ�: ";
		cin >> wi_money;

		kBank[numAccount]->withdraw(wi_money);
		cout << "��ݿϷ�" << endl;
	}
	catch (Exception& e) {
		e.showException();
	}
}


void AccountHandler::printAccout() {
	try {
		if (num == 0)
			throw NothingException();
		else {
			for (int i = 0; i < num; i++) {
				kBank[i]->printAccount();
			}
		}
	}
	catch (Exception& e) {
		e.showException();
	}
}

AccountHandler::~AccountHandler() {
	for (int i = 0; i < num; i++)
		delete kBank[i];
	/*
	������ ��Ģ�� �ٰ��� �ڷ����� account�� ��Ҹ� ������ ��� account�� destructor�� ȣ��Ǵµ�
	derived class���� heap of memory�� ����Ǵ� ��Ұ� ���� ������ �޸� ������ ���� �ʴ´�.
	������ ���� derived class�� �þ�� ���� dynamic allocation ��Ұ� �߰��� �� ������ �̸�
	Account class destructor�� virtual ���·� �����س��Ҵ�.
	��� ���� �� fucntion�� ����Ǹ� Account�� ���ϴ� derived class�� destructor���� �ֻ�� super class(Account)�� destructor
	���� �������� ����ȴ�.
	*/
}
