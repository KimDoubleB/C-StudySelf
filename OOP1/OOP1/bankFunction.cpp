#include <iostream>
#include "account.h"
using namespace std;
account Kbank[100];

void printMenu(int* menu) {
	cout << "-----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << "선택: ";
	cin >> (*menu);
}

void makeAccount(int* num) {
	cout << "[계좌개설]" << endl;

	cout << "계좌ID: ";
	cin >> Kbank[*num].id;

	cout << "이 름: ";
	cin >> Kbank[*num].name;

	cout << "입금액: ";
	cin >> Kbank[*num].inMoney;

	(*num)++;
}

void deposit(int num) {
	int de_id, de_money, numAccount;
	cout << "[ 입 금 ]" << endl;

	cout << "계좌ID: ";
	cin >> de_id;

	numAccount = searchAccout(de_id, num);
	if (numAccount == -1)
	{
		cout << "입력하신 계좌ID는 존재하지 않습니다." << endl << "확인 부탁드립니다." << endl;
		return;
	}

	cout << "입금액: ";
	cin >> de_money;

	Kbank[numAccount].inMoney += de_money;
	cout << "입금완료" << endl;
}

void withdraw(int num) {
	int wi_id, wi_money, numAccount;
	cout << "[ 출 금 ]" << endl;

	cout << "계좌ID: ";
	cin >> wi_id;

	numAccount = searchAccout(wi_id, num);
	if (numAccount == -1)
	{
		cout << "입력하신 계좌ID는 존재하지 않습니다." << endl << "확인 부탁드립니다." << endl;
		return;
	}

	cout << "출금액: ";
	cin >> wi_money;

	if (Kbank[numAccount].inMoney < wi_money)
	{
		cout << "입력하신 금액은 현재 계좌에 존재하는 금액보다 큽니다." << endl << "확인 부탁드립니다." << endl;
		return;
	}

	Kbank[numAccount].inMoney -= wi_money;
	cout << "출금완료" << endl;
}

int searchAccout(int id, int num) {
	for (int i = 0; i < num; i++) {
		if (id == Kbank[i].id)
			return i;
	}

	return -1;
}

void printAccout(int num) {

	for (int i = 0; i < num; i++) {
		cout << endl << "계좌ID: " << Kbank[i].id << endl;
		cout << "이 름: " << Kbank[i].name << endl;
		cout << "잔 액: " << Kbank[i].inMoney << endl;
	}
}