#include <iostream>
using namespace std;

class Bank{
	string accountHolder;
	double balance;
	static double totalBalance;
	public:
		Bank(string name,double initialBalance):accountHolder(name),balance(initialBalance){
			totalBalance+=initialBalance;
		}
		void deposit(double amount){
			balance+=amount;
			totalBalance+=amount;
			cout << "Deposited " << amount<< " into "<< accountHolder<<"'s account" <<endl;
		}
		void withdraw(double amount){
			if (amount>balance){
				cout << "Insufficient balance in " << accountHolder<<"'s account" <<endl;
			}else{
				balance-=amount;
				totalBalance-=amount;
				cout << "Withdrawn " << amount<< " from "<< accountHolder<<"'s account" <<endl;
			}
		}
		static double getTotalBalance(){
			return totalBalance;
		}
		void displayAccount(){
			cout << "Account Holder: " <<accountHolder<<", Balance: "<<balance<<endl;
		}
};
double Bank::totalBalance=0;
int main(){
	Bank b1("Wasil",1000);
	Bank b2("Ahmed",2000);
	cout<<"Initial Total Balance: "<<Bank::getTotalBalance()<<endl;
	b1.deposit(500);
	b2.withdraw(1000);
	cout<<"Account Details: "<<endl;
	b1.displayAccount();
	b2.displayAccount();
	cout << "Updated Total Balance: "<<Bank::getTotalBalance()<<endl;
}