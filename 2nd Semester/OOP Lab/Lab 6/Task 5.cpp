#include <iostream>
using namespace std;

class Person{
public:
	string name;
	string conInfo;
	Person(string n,string c):name(n),conInfo(c){}
};
class BankEmployee{
public:
	int empID;
	string position;
	BankEmployee(int e,string p):empID(e),position(p){}
};
class Customer{
public:
	double accNum;
	double balance;
	Customer(double a,double b):accNum(a),balance(b) {}
};
class BankManager:public BankEmployee,Customer,Person{
public:
	BankManager(string n,string c,int e,string p,double a,double b):Person(n,c),BankEmployee(e,p),Customer(a,b){}
	void display(){
		cout<<"=== Bank Manager Details ==="<<endl;
		cout<<"Name: "<<name<<endl;
		cout<<"Contact Info: "<<conInfo<<endl;
		cout<<"Employee ID: "<<empID<<endl;
		cout<<"Position: "<<position<<endl;
		cout<<"Account Number: "<<accNum<<endl;
		cout<<"Balance: "<<balance<<endl;
	}
	void deposit(int dep){
		cout<<"Depositted: $"<<dep<<" New Balance: $"<<dep+balance<<endl;
	}
	void withdraw(int amount){
		if (amount<balance){
			cout<<"Withdrawn: $"<<amount<<" New Balance: $"<<balance-amount<<endl;
		}else{
			cout<<"Not enough balance!"<<endl;
		}
	}
};
int main(){
	BankManager b1("Muhammad Wasil","k240790@nu.edu.pk",790,"General Manager",60025,15000);
	b1.display();
	cout<<"=== Transactions ==="<<endl;
	b1.deposit(5000);
	b1.withdraw(10000);
}
