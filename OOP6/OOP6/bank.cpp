#include "bank.h"
// ���� �޼��� Ȯ�� Ŭ���� ������
// --> Exception class

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
	cout << endl << "[������������]" << endl;
	cout << "1. ���뿹�ݰ��� 2. �ſ�ŷڰ���" << endl;
	cout << "����: ";

	int id, money, subMenu;
	char name[NAME_LENGTH];
	double rate;

	cin >> subMenu;
	if (subMenu != 1 && subMenu != 2)
	{
		cout << endl << "-����; �߸��� ���� ���� �޴��Դϴ�." << endl << "Ȯ�� ��Ź�帳�ϴ�." << endl;
		return;
	}

	cout << "����ID: ";
	cin >> id;

	cout << "�� ��: ";
	cin >> name;

	cout << "�Աݾ�: ";
	cin >> money;

	cout << "������: ";
	cin >> rate;

	switch (subMenu) {
	case 1:
		kBank[num] = new NormalAccount(id, name, money, rate);
		break;
	case 2:
		int creditRate;
		cout << "�ſ���(1toA, 2toB, 3toC): ";
		cin >> creditRate;
		switch (creditRate)
		{
		case CREDIT_RATE::RATE_A:
		case CREDIT_RATE::RATE_B:
		case CREDIT_RATE::RATE_C:
			break;
		default:
			cout << endl << "-����; �߸��� �ſ����Դϴ�." << endl << "Ȯ�� ��Ź�帳�ϴ�." << endl;
			return;
		}
		kBank[num] = new HighCreditAccount(id, name, money, rate, creditRate);
		break;
	}

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
		cout << endl << "-����; �Է��Ͻ� ����ID�� �������� �ʽ��ϴ�." << endl << "Ȯ�� ��Ź�帳�ϴ�." << endl;
		return;
	}

	cout << "�Աݾ�: ";
	cin >> de_money;

	kBank[numAccount]->deposit(de_money);
	cout << "�ԱݿϷ�" << endl;

}

void AccountHandler::withdraw() {
	int wi_id, wi_money, numAccount;
	cout << "[ �� �� ]" << endl;

	cout << "����ID: ";
	cin >> wi_id;

	numAccount = searchAccout(wi_id);
	if (numAccount == -1)
	{
		cout << endl << "-����; �Է��Ͻ� ����ID�� �������� �ʽ��ϴ�." << endl << "Ȯ�� ��Ź�帳�ϴ�." << endl;
		return;
	}

	cout << "��ݾ�: ";
	cin >> wi_money;

	kBank[numAccount]->withdraw(wi_money);
	cout << "��ݿϷ�" << endl;

}


void AccountHandler::printAccout() {
	if (num == 0)
		cout << endl << "������� ���°� �������� �ʽ��ϴ�." << endl;
	else {
		for (int i = 0; i < num; i++) {
			kBank[i]->printAccount();
		}
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

// Overriding
void NormalAccount::deposit(int money) {
	Account::deposit(money); // �ݾ� �Ա�
	Account::deposit(money * getRate()); // ���� �߰�
}
void NormalAccount::printAccount() const {
	Account::printAccount();
	cout << "������: " << getRate() << endl;
}

// Overriding
void HighCreditAccount::deposit(int money) {
	NormalAccount::deposit(money); // �Ա�&���� �߰�
	Account::deposit(money * getCreditRate()); // �߰� ���� �߰�
}
void HighCreditAccount::printAccount() const {
	NormalAccount::printAccount();
	cout << "�ſ���(1toA, 2toB, 3toC): " << getCreditRate() << endl;
}
