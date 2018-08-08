const int NAME_LENGTH = 100;

typedef struct Account {
	int id;
	char name[NAME_LENGTH];
	int inMoney;
}account;


void printMenu(int*);
void makeAccount(int*);
void deposit(int );
void withdraw(int);
int searchAccout(int , int );
void printAccout(int );