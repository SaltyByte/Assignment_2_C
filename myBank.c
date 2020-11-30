#include <stdio.h>

// Declare inner function.
double roundToTwoDigits(double amount);

// matrix, initialized with zeroes.
double bank[50][2] = {0};
// Bank account number range.
#define RANGE 901

// Opens new account with given deposit amount. Account number is picked by availability. Prints the new account with given amount.
void openAccount(double deposit) {
	if(deposit <= 0){
		printf("Invalid Amount\n");
		return;
	}
	for (int i = 0; i < 50; i++) {
		if (bank[i][0] == 0) {
			// Stores the deposit amount with only 2 digits after the dot. 
			bank[i][0] = 1;
			bank[i][1] = roundToTwoDigits(deposit);
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
		printf("Invalid account number\n");
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
	if(deposit <= 0){
		printf("Cannot deposit a negative amount\n");
	}
	else if (bank[account - RANGE][0] == 1) {
		bank[account - RANGE][1] += roundToTwoDigits(deposit);
		double balance = bank[account - RANGE][1];
		printf("The new balance is: %.2lf\n", balance);
	}
	else {
		printf("This account is closed\n");
	}
}

// Withdrawal amount with given account number.
void withdrawal(int account, double amount) {
	if (bank[account - RANGE][0] == 1) {
		if (bank[account - RANGE][1] - roundToTwoDigits(amount) >= 0){
			bank[account - RANGE][1] -= roundToTwoDigits(amount);
			double balance = bank[account - RANGE][1];
			printf("The new balance is: %.2lf\n", balance);
		}
		else {
			printf("Cannot withdraw more than the balance.\n");
		}
	}
	else {
		printf("This account is closed\n");
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
		printf("Closed account number %d\n", account);
	}
	else {
		printf("This account is already closed\n");
	}
}

// Takes the intrest rate and multiplies it with all the balances. NOTE: Negative interest rate lowers the balance.
void interestRate(int interestRate) {
	for (int i = 0; i < 50; i++) {
		if (bank[i][0] == 1 && interestRate >= -100) {
			int update = (interestRate * bank[i][1]) / 100;
			update = roundToTwoDigits(update);
			bank[i][1] += update;
		}
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
// Helping function, round to two digits after the dot.
double roundToTwoDigits(double amount){
	amount *= 100;
	amount = (int)(amount);
	return amount /= 100;
}
