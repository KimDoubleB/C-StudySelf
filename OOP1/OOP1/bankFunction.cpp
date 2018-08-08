#include <iostream>
#include "account.h"
using namespace std;
account Kbank[100];

void printMenu(int* menu) {
	cout << "-----Menu-----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
	cout << "����: ";
	cin >> (*menu);
}

void makeAccount(int* num) {
	cout << "[���°���]" << endl;

	cout << "����ID: ";
	cin >> Kbank[*num].id;

	cout << "�� ��: ";
	cin >> Kbank[*num].name;

	cout << "�Աݾ�: ";
	cin >> Kbank[*num].inMoney;

	(*num)++;
}

void deposit(int num) {
	int de_id, de_money, numAccount;
	cout << "[ �� �� ]" << endl;

	cout << "����ID: ";
	cin >> de_id;

	numAccount = searchAccout(de_id, num);
	if (numAccount == -1)
	{
		cout << "�Է��Ͻ� ����ID�� �������� �ʽ��ϴ�." << endl << "Ȯ�� ��Ź�帳�ϴ�." << endl;
		return;
	}

	cout << "�Աݾ�: ";
	cin >> de_money;

	Kbank[numAccount].inMoney += de_money;
	cout << "�ԱݿϷ�" << endl;
}

void withdraw(int num) {
	int wi_id, wi_money, numAccount;
	cout << "[ �� �� ]" << endl;

	cout << "����ID: ";
	cin >> wi_id;

	numAccount = searchAccout(wi_id, num);
	if (numAccount == -1)
	{
		cout << "�Է��Ͻ� ����ID�� �������� �ʽ��ϴ�." << endl << "Ȯ�� ��Ź�帳�ϴ�." << endl;
		return;
	}

	cout << "��ݾ�: ";
	cin >> wi_money;

	if (Kbank[numAccount].inMoney < wi_money)
	{
		cout << "�Է��Ͻ� �ݾ��� ���� ���¿� �����ϴ� �ݾ׺��� Ů�ϴ�." << endl << "Ȯ�� ��Ź�帳�ϴ�." << endl;
		return;
	}

	Kbank[numAccount].inMoney -= wi_money;
	cout << "��ݿϷ�" << endl;
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
		cout << endl << "����ID: " << Kbank[i].id << endl;
		cout << "�� ��: " << Kbank[i].name << endl;
		cout << "�� ��: " << Kbank[i].inMoney << endl;
	}
}