#include "bank.h"

int main() {
	int menu, num = 0;
	while (1) {
		printMenu(menu);
		switch (menu) {
		case BANK_REQUEST::MAKE:
			makeAccount(num);
			break;
		case BANK_REQUEST::DEPOSIT:
			deposit(num);
			break;
		case BANK_REQUEST::WITHDRAW:
			withdraw(num);
			break;
		case BANK_REQUEST::INQUIRE:
			printAccout(num);
			break;
		case BANK_REQUEST::EXIT:
			return 0;
		}
		cout << endl;
	}
	return 0;
}