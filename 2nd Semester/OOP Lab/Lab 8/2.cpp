#include <iostream>
using namespace std;

class BankAccount;
class Transaction{
public:
	void processTransaction(BankAccount& bA,double mon,string type);
};
class BankAccount{
	int accNum;
	double balance;
public:
	BankAccount(int a,double b):accNum(a),balance(b){}
	friend void Transaction::processTransaction(BankAccount& bA,double mon,string type);
};
void Transaction::processTransaction(BankAccount& ba,double mon,string type){
	if (type=="withdraw"){
		if (mon<=ba.balance){
			ba.balance-=mon;
			cout<<"Money withdrawn!"<<endl;
			cout<<"New balance: "<<ba.balance<<endl;
		}else{
			cout<<"Not enough balance!"<<endl;
		}
	}else if(type=="deposit"){
		ba.balance+=mon;
		cout<<"Money deposiited!"<<endl;
		cout<<"New balance: "<<ba.balance<<endl;
	}
}

int main(){
	BankAccount b(79024,2500);
	Transaction t;
	t.processTransaction(b,3500,"withdraw");
	t.processTransaction(b,5000,"deposit");
	t.processTransaction(b,4000,"withdraw");
	return 0;
}
