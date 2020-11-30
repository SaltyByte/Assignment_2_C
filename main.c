#include <stdio.h>
#include "myBank.h"
#define RANGE 901


int main() {
	int isActive = 1;
	// While loop, over all inputs. ends when input is E
	while(isActive){
		// Init the vars.
		char input;
		int account = 0;
		double amount = 0.0;
		int interest = 0;
		printf("\nPlease choose a transaction type: \n O-Open Account\n B-Balance Inquiry\n D-Deposit\n W-Withdrawal\n C-Close Account\n I-Interest\n P-Print\n E-Exit\n");	
		scanf(" %c", &input);
		switch(input) {
			// Case O, Open new account, account number given by free space.
			case 'O' :
				printf("Please enter amount for deposit: ");
				if (scanf(" %lf", &amount) == 1){
					openAccount(amount);
					break;
				}
				else {
					printf("Failed to read the amount\n");
					break;
				}

			// Case B, Print balance of given account number.
			case 'B' :
				printf("Please enter account number: ");
				if (scanf("%d", &account) == 1) {
					balanceCheck(account);
					break;
				}
				else {
					printf("Failed to read the account number\n");
					break;
				}

			// Case D, Deposit amount with given account number, cannot be negative.
			case 'D' :
				printf("Please enter account number: ");
				if (scanf("%d", &account) != 1) {
					printf("Failed to read the account number\n");
					break;
				}
				if (account > 950 || account < 901) {
					printf("Invalid account number\n");
					break;
				}
				if (bank[account - RANGE][0] == 0) {
					printf("This account is closed\n");
					break;
				}
				printf("Please enter the amount to deposit: ");
				if (scanf("%lf", &amount) == 1){
					deposit(account, amount);
					break;			
				}
				else {
					printf("Failed to read the amount\n");
					break;
				}

			// Case W, Withdrawal amount with given account number, cant be negative and cannot withdrawal more than you got.
			case 'W' : 
				printf("Please enter account number: ");
				if (scanf("%d", &account) != 1) {
					printf("Failed to read the account number\n");
					break;
				}
				if (account > 950 || account < 901) {
					printf("Invalid account number\n");
					break;
				}
				if (bank[account - RANGE][0] == 0){
					printf("This account is closed\n");
					break;
				}
				printf("Please enter the amount to withdraw: ");
				if (scanf("%lf", &amount) == 1){
					withdrawal(account, amount);
					break;			
				}
				else {
					printf("Failed to read the amount\n");
					break;
				}
				break;

			// Case C, Close account with given account number.
			case 'C' :
				printf("Please enter account number: ");
				if (scanf("%d", &account) != 1) {
					printf("Failed to read the account number\n");
					break;
				}
				else {
					closeAccount(account);
					break;
				}
			
			// Case I, Input interest rate and update all the accounts.
			case 'I' :
				printf("Please enter interest rate: ");
				if (scanf("%d", &interest) == 1){
					if (interest < 0){
						printf("Invalid interest rate\n");
						break;
					}
					interestRate(interest);
					break;
				}
				else {
					printf("Failed to read the interest rate\n");
					break;
				}
			
			// Case P, Prints all accounts numbers and all balances.
			case 'P' :
				printAccounts();
				break;
			
			// Case E, Close all bank accounts and end while loop.
			case 'E' :
				emptyBank();
				isActive = 0;
				break;
			
			// Default case, if input neither one of the cases then error.
			default :
				printf("Invalid transaction type\n");
			}
		}
return 0;
}