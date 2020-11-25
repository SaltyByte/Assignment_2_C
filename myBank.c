#include<stdio.h>

static double bank[50][2] = {0};
#define RANGE 901

void openAccount(double deposit) {
	for (int i = 0; i < 50; i++) {
		if (bank[i][0] == 0 && deposit >= 0) {
			bank[i][0] = 1;
			bank[i][1] = deposit;
			int account = i + RANGE;
			printf("New bank account: %d with the balance of: %.2lf\n", account, deposit);
			return;
		}
	}
	printf("No account available.\n");
}
	
void balanceCheck(int account) {
	if (account < 901 || account > 951) {
		printf("Invalid account number");
	}
	else if (bank[account - RANGE][0] == 1) {
		double balance = bank[account - RANGE][1];
		printf("Account number: %d, Total balance: %.2lf\n ", account,  balance);
	}
	else {
		printf("No open account with given account number.\n");
	}
}

void deposit(int account, double deposit) {
	if (account < 901 || account > 951) {
		printf("Invalid account number");
	}
	else if (bank[account - RANGE][0] == 1 && deposit >= 0) {
		bank[account - RANGE][1] += deposit;
		double balance = bank[account - RANGE][1];
		printf("Account number: %d, Total balance after deposit: %.2lf\n", account,  balance);
	}
	else {
		printf("No open account with given account number.\n");
	}
}

void withdrawal(int account, double amount) {
	if (account < 901 || account > 951) {
		printf("Invalid account number");
	}
	else if (bank[account - RANGE][0] == 1 && amount >= 0) {
		if (bank[account - RANGE][1] - amount >= 0){
			bank[account - RANGE][1] -= amount;
			double balance = bank[account - RANGE][1];
			printf("Account number: %d, Total balance after withdrawal: %.2lf\n", account,  balance);
		}
		else {
			printf("Not enough balance available in the account.\n");
		}
	}
	else {
		printf("No open account with given account number.\n");
	}
}

void closeAccount(int account) {
	if (account < 901 || account > 951) {
		printf("Invalid account number");
	}
	else if (bank[account - RANGE][0] == 1) {
		bank[account - RANGE][0] = 0;
		bank[account - RANGE][1] = 0;
	}
	else {
		printf("No open account with given account number.\n");
	}
}

void interestRate(double interestRate) {
	if (interestRate >= -100) {
		for (int i = 0; i < 50; i++) {
			if (bank[i][0] == 1 && interestRate >= -100) {
				bank[i][1] += (interestRate * bank[i][1]) / 100;
			}
		}
	}
	else {
		printf("Interest rate cannot be below -100%%");
	}
}

void printAccounts() {
	for (int i = 0; i < 50; i++) {
		if (bank[i][0] == 1) {
			double balance = bank[i][1];
			printf("Account number: %d, Total balance is: %.2lf\n", i + RANGE,  balance);
		}
	}
}


void emptyBank() {
	for (int i = 0; i < 50; i++) {
		if (bank[i][0] == 1) {
			bank[i][0] = 0;
		}
	}
}