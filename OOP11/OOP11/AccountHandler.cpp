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
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << "선택: ";
	cin >> menu;
}

void AccountHandler::makeAccount() {
	cout << endl << "[계좌종류선택]" << endl;
	cout << "1. 보통예금계좌 2. 신용신뢰계좌" << endl;
	cout << "선택: ";

	int id, money, subMenu;
	String name;
	double rate;
	
	try {
		cin >> subMenu;
		
		if (subMenu != 1 && subMenu != 2)
			throw MenuException();
		
		cout << "계좌ID: ";
		cin >> id;

		cout << "이 름: ";
		cin >> name;

		cout << "입금액: ";
		cin >> money;

		cout << "이자율(%): ";
		cin >> rate;

		switch (subMenu) {
		case 1:
			kBank[num] = new NormalAccount(id, name, money, rate);
			break;
		case 2:
			int creditRate;
			cout << "신용등급(1toA, 2toB, 3toC): ";
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
	cout << "[ 입 금 ]" << endl;

	try {
		if (num == 0)
			throw NothingException();

		cout << "계좌ID: ";
		cin >> de_id;

		numAccount = searchAccout(de_id);

		cout << "입금액: ";
		cin >> de_money;

		kBank[numAccount]->deposit(de_money);
		cout << "입금완료" << endl;
	}
	catch (Exception& e) {
		e.showException();
	}
}

void AccountHandler::withdraw() {
	int wi_id, wi_money, numAccount;
	cout << "[ 출 금 ]" << endl;

	try {
		if (num == 0)
			throw NothingException();

		cout << "계좌ID: ";
		cin >> wi_id;

		numAccount = searchAccout(wi_id);

		cout << "출금액: ";
		cin >> wi_money;

		kBank[numAccount]->withdraw(wi_money);
		cout << "출금완료" << endl;
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
	다형성 원칙에 근거해 자료형이 account인 요소만 제거할 경우 account의 destructor만 호출되는데
	derived class에서 heap of memory에 저장되는 요소가 없기 때문에 메모리 누수가 되지 않는다.
	하지만 추후 derived class가 늘어남에 따라 dynamic allocation 요소가 추가될 수 있으니 미리
	Account class destructor는 virtual 형태로 정의해놓았다.
	고로 현재 이 fucntion이 실행되면 Account의 최하단 derived class의 destructor부터 최상단 super class(Account)의 destructor
	까지 차근차근 수행된다.
	*/
}
