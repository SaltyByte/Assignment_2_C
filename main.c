#include<stdio.h>
#include"myBank.h"



int main() {
	int isActive = 1;
	while(isActive){
		char input;
		int account = 0;
		double amount = 0.0;	
		printf("\nPlease choose a transaction type: \n O-Open Account\n B-Balance Inquiry\n D-Deposit\n W-Withdrawal\n C-Close Account\n I-Interest\n P-Print\n E-Exit\n");	
		scanf(" %c", &input);
		// if (getchar() != '\n') {
		// 	while(getchar() != '\n');
		// 	printf("Invalid Input!!");
		// 	continue;
		// }
		switch(input) {
			case 'O' :
				printf("Please enter amount for deposit: ");
				if (scanf(" %lf", &amount) == 1){
					openAccount(amount);
					break;
				}
				else {
					//getchar();
					printf("Failed to read the amount");
					break;
				}

			case 'B' :
				printf("Please enter account number: ");
				if (scanf("%d", &account) == 1) {
					balanceCheck(account);
					break;
				}
				else {
					//getchar();
					printf("Failed to read the account number");
					break;
				}

			case 'D' :
				printf("Please enter account number: ");
				if (scanf("%d", &account) != 1) {
					//getchar();
					printf("Failed to read the account number");
					break;
				}
				printf("Please enter amount for deposit: ");
				if (scanf("%lf", &amount) == 1){
					deposit(account, amount);
					break;			
				}
				else {
					printf("Failed to read the amount");
					//getchar();
					break;
				}

			case 'W' : 
				printf("Please enter account number: ");
				if (scanf("%d", &account) != 1) {
					//getchar();
					printf("Failed to read the account number");
					break;
				}
				printf("Please enter the amount to withdraw: ");
				if (scanf("%lf", &amount) == 1){
					withdrawal(account, amount);
					break;			
				}
				else {
					printf("Failed to read the amount");
					//getchar();
					break;
				}
				break;
		
			case 'C' :
				printf("Please enter account number: ");
				if (scanf("%d", &account) != 1) {
					//getchar();
					printf("Failed to read the account number");
					break;
				}
				else {
					closeAccount(account);
					break;
				}
			
			case 'I' :
				printf("Please enter interest rate: ");
				if (scanf("%lf", &amount) == 1){
					interestRate(amount);
					break;
				}
				else {
					//getchar();
					printf("Failed to read the interest rate");
					break;
				}
			
			case 'P' :
				printAccounts();
				break;
			
			case 'E' :
				emptyBank();
				isActive = 0;
				break;
			
			default :
				printf("Invalid transaction type");
			}
		}
return 0;
}