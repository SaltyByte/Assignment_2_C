#include<stdio.h>
#include"myBank.h"



int main() {
	int isActive = 1;
	while(isActive){
		char input;
		int account = 0;
		double amount = 0.0;	
		printf("\nTransaction type?: ");
		scanf(" %c", &input);
		if (getchar() != '\n') {
			while(getchar() != '\n');
			printf("Invalid Input!!");
			continue;
		}
		switch(input) {
			case 'O' :
				printf("\nInitial deposit?: ");
				if (scanf(" %lf", &amount) == 1){
					openAccount(amount);
					break;
				}
				else {
					getchar();
					printf("Please insert a valid amount!!");
					break;
				}

			case 'B' :
				printf("\nAccount number?: ");
				if (scanf("%d", &account) == 1) {
					balanceCheck(account);
					break;
				}
				else {
					getchar();
					printf("Please insert a valid account number!!");
					break;
				}

			case 'D' :
				printf("\nAccount number?: ");
				if (scanf("%d", &account) != 1) {
					getchar();
					printf("Please insert a valid account number!!");
					break;
				}
				printf("\nAmount?: ");
				if (scanf("%lf", &amount) == 1){
					deposit(account, amount);
					break;			
				}
				else {
					printf("Please insert a valid amount!!");
					getchar();
					break;
				}

			case 'W' : 
				printf("\nAccount number?: ");
				if (scanf("%d", &account) != 1) {
					getchar();
					printf("Please insert a valid account number!!");
					break;
				}
				printf("\nAmount?: ");
				if (scanf("%lf", &amount) == 1){
					withdrawal(account, amount);
					break;			
				}
				else {
					printf("Please insert a valid amount!!");
					getchar();
					break;
				}
				break;
		
			case 'C' :
				printf("\nAccount number?: ");
				if (scanf("%d", &account) != 1) {
					getchar();
					printf("Please insert a valid account number!!");
					break;
				}
				else {
					closeAccount(account);
					break;
				}
			
			case 'I' :
				printf("\nInterest rate?: ");
				if (scanf("%lf", &amount) == 1){
					interestRate(amount);
					break;
				}
				else {
					getchar();
					printf("Please insert a valid interest rate!");
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
				printf("\nPlease enter a valid Transaction type. ");
			}
		}
return 0;
}