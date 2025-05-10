#include <iostream>
using namespace std;

class bankaccount{
	int balance;
	public:
		bankaccount(int a):balance(a){}
		void checkbal(){
			cout<<"new balance: "<<balance<<endl;
		}
		void withdraw(int b){
			if(b<0  ||  b>balance){
				throw "insufficient balance";
			}
			else{
				balance-=b;
				cout<<"amount has been withdrawn!"<<endl;
			}
		}
};

int main(){
	bankaccount b(25000);
	try{
		b.withdraw(130000);
	}catch(const char *c){
		cout<<"exception: "<<c<<endl;
	}
	try{
		b.withdraw(100);
	}catch(const char *c){
		cout<<"exception: "<<c<<endl;
	}
	b.checkbal();
}
