#include <iostream>
using namespace std;

class BankAccount{
public:
	virtual void withdraw(){
		cout<<"Withdrawing..."<<endl;
	}
};
class SavingsAccount: public BankAccount{
public:
	void withdraw(){
		cout<<"Savings Account Withdrawal: $500"<<endl;
	}
};
class CurrentAccount: public BankAccount{
public:
	void withdraw(){
		cout<<"Current Account Withdrawal: $1000"<<endl;
	}
};

int main(){
	BankAccount* b;
	SavingsAccount s;
	CurrentAccount c;
	b=&s;
	b->withdraw();
	b=&c;
	b->withdraw();
	return 0;
}
