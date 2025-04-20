#include<iostream>
using namespace std;

class bankAccount{
	private:
		double balance;
	public:
		void setBalance(double stat){
			balance=stat;
		}
		double getBalance(){
			return balance;
		}
		void deposit(double amount){
			balance+=amount;
		}
		void withdraw(double with){
			balance-=with;
		}
};

int main(){
	bankAccount b1;
	b1.setBalance(321.12);
	cout<<"Balance: "<<b1.getBalance()<<endl<<endl;
	b1.deposit(231.1);
	b1.withdraw(111);
	cout<<"Balance: "<<b1.getBalance()<<endl<<endl;
}
