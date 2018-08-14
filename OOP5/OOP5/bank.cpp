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
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << "선택: ";
	cin >> menu;
}

void AccountHandler::makeAccount() {
	cout << "[계좌개설]" << endl;
	int id, money;
	char name[NAME_LENGTH];

	cout << "계좌ID: ";
	cin >> id;

	cout << "이 름: ";
	cin >> name;

	cout << "입금액: ";
	cin >> money;

	kBank[num] = new Account(id, name, money);

	num++;
}

void AccountHandler::deposit() {
	int de_id, de_money, numAccount;
	cout << "[ 입 금 ]" << endl;

	cout << "계좌ID: ";
	cin >> de_id;

	numAccount = searchAccout(de_id);
	if (numAccount == -1)
	{
		cout << "입력하신 계좌ID는 존재하지 않습니다." << endl << "확인 부탁드립니다." << endl;
		return;
	}

	cout << "입금액: ";
	cin >> de_money;

	kBank[numAccount]->deposit(de_money);
}

void AccountHandler::withdraw() {
	int wi_id, wi_money, numAccount;
	cout << "[ 출 금 ]" << endl;

	cout << "계좌ID: ";
	cin >> wi_id;

	numAccount = searchAccout(wi_id);
	if (numAccount == -1)
	{
		cout << "입력하신 계좌ID는 존재하지 않습니다." << endl << "확인 부탁드립니다." << endl;
		return;
	}

	cout << "출금액: ";
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
	cout << "입금완료" << endl;

}

void Account::withdraw(int money) {
	if (this->inMoney < money)
	{
		cout << "입력하신 금액은 현재 계좌에 존재하는 금액보다 큽니다." << endl << "확인 부탁드립니다." << endl;
		return;
	}

	this->inMoney -= money;
	cout << "출금완료" << endl;
}

void Account::printAccount() const {
	cout << endl << "계좌ID: " << this->id << endl;
	cout << "이 름: " << this->name << endl;
	cout << "잔 액: " << this->inMoney << endl;
}