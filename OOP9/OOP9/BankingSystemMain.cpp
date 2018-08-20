#include "AccountHandler.h"

int main() {
	int menu;
	AccountHandler ah;

	while (1) {
		ah.printMenu(menu);
		switch (menu) {
		case BANK_REQUEST::MAKE:
			ah.makeAccount();
			break;
		case BANK_REQUEST::DEPOSIT:
			ah.deposit();
			break;
		case BANK_REQUEST::WITHDRAW:
			ah.withdraw();
			break;
		case BANK_REQUEST::INQUIRE:
			ah.printAccout();
			break;
		case BANK_REQUEST::EXIT:
			return 0;
		default:
			cout << endl << "-����; �߸��� �޴��Դϴ�." << endl << "Ȯ�� ��Ź�帳�ϴ�." << endl;
		}
		cout << endl;
	}
	return 0;
}