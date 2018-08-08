#include <iostream>
using namespace std;
#include "account.h"

int main() {
	int menu, num = 0;
	while (1) {
		printMenu(&menu);
		switch (menu) {
		case 1:
			makeAccount(&num);
			break;
		case 2:
			deposit(num);
			break;
		case 3:
			withdraw(num);
			break;
		case 4:
			printAccout(num);
			break;
		case 5:
			return 0;
		}
		cout << endl;
	}
	return 0;
}