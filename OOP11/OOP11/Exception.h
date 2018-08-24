#include <iostream>
#include "String.h"

#ifndef __EXCEPTION__H__
#define __EXCEPTION__H__
using namespace std;

class Exception {
public:
	virtual void showException() {
		cout << endl << "-오류;" << endl;
	}
};
class MenuException : public Exception
{
public:
	//overriding
	void showException() {
		cout << endl << "-오류; 잘못된 메뉴 선택입니다." << endl << "확인 부탁드립니다." << endl << endl;
	}
};
class SpecialException : public Exception {
private:
	String str;
public:
	SpecialException(String str) : str(str) {}
	void showException() {
		cout << endl << "-오류; " << str << endl << "확인 부탁드립니다." << endl << endl;

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
		cout << endl << "-오류; 입력하신 금액(" << withdrawMoney << ")은 예금된 금액보다 많습니다." << endl << "확인 부탁드립니다." << endl << endl;
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
		cout << endl << "-오류; 입력하신 금액(" << integer << ")은 0보다 작습니다." << endl << "확인 부탁드립니다." << endl << endl;
	}
};

class IdException : public Exception
{
public:
	//overriding
	void showException() {
		cout << endl << "-오류; 입력하신 계좌ID는 존재하지 않습니다." << endl << "확인 부탁드립니다." << endl << endl;
	}
};

class NothingException : public Exception
{

public:
	//overriding
	void showException() {
		cout << endl << "-오류; 만들어진 계좌가 없습니다." << endl << "먼저 계좌를 만들어주세요." << endl << endl;
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
		cout << endl << "-오류; 입력하신 이자율(" << rate << ")이 잘못된 값입니다." << endl << "이자율의 범위는 0~100입니다. 확인 부탁드립니다." << endl << endl;
	}
};


#endif