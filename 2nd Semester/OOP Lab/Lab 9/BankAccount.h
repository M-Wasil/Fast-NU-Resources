#ifndef BANKACCOUNT
#define BANKACCOUNT

class BankAccount{
	double balance;
public:
	BankAccount(double initial_bal);
	void deposit(double amount);
	bool withdraw(double amount);
	double getBalance();
};
#endif
