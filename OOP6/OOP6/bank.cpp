#include "bank.h"
// 오류 메세지 확인 클래스 만들자
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
	char name[NAME_LENGTH];
	double rate;

	cin >> subMenu;
	if (subMenu != 1 && subMenu != 2)
	{
		cout << endl << "-오류; 잘못된 계좌 개설 메뉴입니다." << endl << "확인 부탁드립니다." << endl;
		return;
	}

	cout << "계좌ID: ";
	cin >> id;

	cout << "이 름: ";
	cin >> name;

	cout << "입금액: ";
	cin >> money;

	cout << "이자율: ";
	cin >> rate;

	switch (subMenu) {
	case 1:
		kBank[num] = new NormalAccount(id, name, money, rate);
		break;
	case 2:
		int creditRate;
		cout << "신용등급(1toA, 2toB, 3toC): ";
		cin >> creditRate;
		switch (creditRate)
		{
		case CREDIT_RATE::RATE_A:
		case CREDIT_RATE::RATE_B:
		case CREDIT_RATE::RATE_C:
			break;
		default:
			cout << endl << "-오류; 잘못된 신용등급입니다." << endl << "확인 부탁드립니다." << endl;
			return;
		}
		kBank[num] = new HighCreditAccount(id, name, money, rate, creditRate);
		break;
	}

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
		cout << endl << "-오류; 입력하신 계좌ID는 존재하지 않습니다." << endl << "확인 부탁드립니다." << endl;
		return;
	}

	cout << "입금액: ";
	cin >> de_money;

	kBank[numAccount]->deposit(de_money);
	cout << "입금완료" << endl;

}

void AccountHandler::withdraw() {
	int wi_id, wi_money, numAccount;
	cout << "[ 출 금 ]" << endl;

	cout << "계좌ID: ";
	cin >> wi_id;

	numAccount = searchAccout(wi_id);
	if (numAccount == -1)
	{
		cout << endl << "-오류; 입력하신 계좌ID는 존재하지 않습니다." << endl << "확인 부탁드립니다." << endl;
		return;
	}

	cout << "출금액: ";
	cin >> wi_money;

	kBank[numAccount]->withdraw(wi_money);
	cout << "출금완료" << endl;

}


void AccountHandler::printAccout() {
	if (num == 0)
		cout << endl << "만들어진 계좌가 존재하지 않습니다." << endl;
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
	다형성 원칙에 근거해 자료형이 account인 요소만 제거할 경우 account의 destructor만 호출되는데
	derived class에서 heap of memory에 저장되는 요소가 없기 때문에 메모리 누수가 되지 않는다.
	하지만 추후 derived class가 늘어남에 따라 dynamic allocation 요소가 추가될 수 있으니 미리
	Account class destructor는 virtual 형태로 정의해놓았다.
	고로 현재 이 fucntion이 실행되면 Account의 최하단 derived class의 destructor부터 최상단 super class(Account)의 destructor
	까지 차근차근 수행된다.
	*/
}

void Account::deposit(int money) {
	this->inMoney += money;
}

void Account::withdraw(int money) {
	if (this->inMoney < money)
	{
		cout << endl << "-오류; 입력하신 금액은 현재 계좌에 존재하는 금액보다 큽니다." << endl << "확인 부탁드립니다." << endl;
		return;
	}

	this->inMoney -= money;
}

void Account::printAccount() const {
	cout << endl << "계좌ID: " << this->id << endl;
	cout << "이 름: " << this->name << endl;
	cout << "잔 액: " << this->inMoney << endl;
}

// Overriding
void NormalAccount::deposit(int money) {
	Account::deposit(money); // 금액 입금
	Account::deposit(money * getRate()); // 이자 추가
}
void NormalAccount::printAccount() const {
	Account::printAccount();
	cout << "이자율: " << getRate() << endl;
}

// Overriding
void HighCreditAccount::deposit(int money) {
	NormalAccount::deposit(money); // 입금&이자 추가
	Account::deposit(money * getCreditRate()); // 추가 이자 추가
}
void HighCreditAccount::printAccount() const {
	NormalAccount::printAccount();
	cout << "신용등급(1toA, 2toB, 3toC): " << getCreditRate() << endl;
}
