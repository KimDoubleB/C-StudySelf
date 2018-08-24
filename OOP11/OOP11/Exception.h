#include <iostream>
#include "String.h"

#ifndef __EXCEPTION__H__
#define __EXCEPTION__H__
using namespace std;

class Exception {
public:
	virtual void showException() {
		cout << endl << "-����;" << endl;
	}
};
class MenuException : public Exception
{
public:
	//overriding
	void showException() {
		cout << endl << "-����; �߸��� �޴� �����Դϴ�." << endl << "Ȯ�� ��Ź�帳�ϴ�." << endl << endl;
	}
};
class SpecialException : public Exception {
private:
	String str;
public:
	SpecialException(String str) : str(str) {}
	void showException() {
		cout << endl << "-����; " << str << endl << "Ȯ�� ��Ź�帳�ϴ�." << endl << endl;

	}
};

class WithdrawException : public Exception
{
private:
	int withdrawMoney;
public:
	WithdrawException(int money) : withdrawMoney(money) {}
	//overriding
	void showException() {
		cout << endl << "-����; �Է��Ͻ� �ݾ�(" << withdrawMoney << ")�� ���ݵ� �ݾ׺��� �����ϴ�." << endl << "Ȯ�� ��Ź�帳�ϴ�." << endl << endl;
	}
};

class NegativeException : public Exception
{
private:
	int integer;
public:
	NegativeException(int integer) : integer(integer) {}
	//overriding
	void showException() {
		cout << endl << "-����; �Է��Ͻ� �ݾ�(" << integer << ")�� 0���� �۽��ϴ�." << endl << "Ȯ�� ��Ź�帳�ϴ�." << endl << endl;
	}
};

class IdException : public Exception
{
public:
	//overriding
	void showException() {
		cout << endl << "-����; �Է��Ͻ� ����ID�� �������� �ʽ��ϴ�." << endl << "Ȯ�� ��Ź�帳�ϴ�." << endl << endl;
	}
};

class NothingException : public Exception
{

public:
	//overriding
	void showException() {
		cout << endl << "-����; ������� ���°� �����ϴ�." << endl << "���� ���¸� ������ּ���." << endl << endl;
	}
};


class RateException : public Exception
{
private:
	double rate;
public:
	RateException(double rate) : rate(rate) {}
	//overriding
	void showException() {
		cout << endl << "-����; �Է��Ͻ� ������(" << rate << ")�� �߸��� ���Դϴ�." << endl << "�������� ������ 0~100�Դϴ�. Ȯ�� ��Ź�帳�ϴ�." << endl << endl;
	}
};


#endif