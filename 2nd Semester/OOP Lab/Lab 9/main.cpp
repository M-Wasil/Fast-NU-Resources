#include <iostream>
#include "BankAccount.h"
using namespace std;

int main(){
	BankAccount acc(1500.0);
	acc.deposit(500.0);
	acc.withdraw(200.0);
	cout<<"Current Balance: $"<<acc.getBalance)()<<endl;
	return 0;
}
