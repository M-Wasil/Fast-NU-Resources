#include <iostream>
using namespace std;

class Payment{
public:
	virtual void processPayment(){
		cout<<"Processing Payment!"<<endl;
	}
};
class CreditCard: public Payment{
public:
	void processPayment(){
		cout<<"Processing Credit Card Payment..."<<endl;
	}
};
class PayPal: public Payment{
public:
	void processPayment(){
		cout<<"Processing PayPal Payment..."<<endl;
	}
};

int main(){
	Payment* p;
	PayPal a;
	CreditCard c;
	p=&a;
	p->processPayment();
	p=&c;
	p->processPayment();
	return 0;
}
