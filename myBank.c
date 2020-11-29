#include <stdio.h>
// Static matrix, initialized with zeroes.
static double bank[50][2] = {0};
// Bank account number range.
#define RANGE 901

// Opens new account with given deposit amount. Account number is picked by availability. Prints the new account with given amount.
void openAccount(double deposit) {
	for (int i = 0; i < 50; i++) {
		if (bank[i][0] == 0 && deposit >= 0) {
			// Stores the deposit amount with only 2 digits after the dot. 
			deposit *= 100;
			deposit = (int)(deposit);
			deposit /= 100;
			bank[i][0] = 1;
			bank[i][1] = deposit;
			int account = i + RANGE;
			printf("New account number is: %d\n", account);
			return;
		}
	}
	printf("No account available.\n");
}

// Prints balance with given account numnber.
void balanceCheck(int account) {
	if (account < 901 || account > 951) {
		printf("Invalid account number");
	}
	else if (bank[account - RANGE][0] == 1) {
		double balance = bank[account - RANGE][1];
		printf("The balance of account number %d is: %.2lf\n ", account,  balance);
	}
	else {
		printf("This account is closed\n");
	}
}

// Deposit amount with given account number.
void deposit(int account, double deposit) {
	if (account < 901 || account > 951) {
		printf("Invalid account number\n");
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

// Withdrawal amount with given account number.
void withdrawal(int account, double amount) {
	if (account < 901 || account > 951) {
		printf("Invalid account number\n");
	}
	else if (bank[account - RANGE][0] == 1 && amount >= 0) {
		if (bank[account - RANGE][1] - amount >= 0){
			bank[account - RANGE][1] -= amount;
			double balance = bank[account - RANGE][1];
			printf("The new balance is: %.2lf\n", balance);
		}
		else {
			printf("Cannot withdraw more than the balance.\n");
		}
	}
	else {
		printf("No open account with given account number.\n");
	}
}

// Closes account with given account number.
void closeAccount(int account) {
	if (account < 901 || account > 951) {
		printf("Invalid account number\n");
	}
	else if (bank[account - RANGE][0] == 1) {
		bank[account - RANGE][0] = 0;
		bank[account - RANGE][1] = 0;
	}
	else {
		printf("No open account with given account number.\n");
	}
}

// Takes the intrest rate and multiplies it with all the balances. NOTE: Negative interest rate lowers the balance.
void interestRate(double interestRate) {
	if (interestRate >= -100) {
		for (int i = 0; i < 50; i++) {
			if (bank[i][0] == 1 && interestRate >= -100) {
				bank[i][1] += (interestRate * bank[i][1]) / 100;
			}
		}
	}
	else {
		printf("Interest rate cannot be below -100%%\n");
	}
}

// Prints all the open accounts in the bank and the balances.
void printAccounts() {
	for (int i = 0; i < 50; i++) {
		if (bank[i][0] == 1) {
			double balance = bank[i][1];
			printf("The balance of account number %d is: %.2lf\n", i + RANGE,  balance);
		}
	}
}

// Closes all the open banks.
void emptyBank() {
	for (int i = 0; i < 50; i++) {
		if (bank[i][0] == 1) {
			bank[i][0] = 0;
		}
	}
}