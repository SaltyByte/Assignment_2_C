#ifndef MY_BANK
#define MY_BANK

// Function signatures.
double bank[50][2];
void openAccount(double deposit);
void balanceCheck(int account);
void deposit(int account, double deposit);
void withdrawal(int account, double amount);
void closeAccount(int account);
void interestRate(double interestRate);
void printAccounts();
void emptyBank();

#endif