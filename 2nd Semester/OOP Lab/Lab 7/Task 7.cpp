#include <iostream>
using namespace std;

class Ticket{
public:
	virtual void calculateFare(){
		cout<<"Calculating fare!"<<endl;
	}
};
class EconomyTicket: public Ticket{
public:
	void calculateFare(){
		cout<<"Economy Ticket Fare: $300"<<endl;
	}
};
class BusinessTicket: public Ticket{
public:
	void calculateFare(){
		cout<<"Business Ticket Fare: $1200"<<endl;
	}
};

int main(){
	Ticket* t;
	EconomyTicket e;
	BusinessTicket b;
	t=&e;
	t->calculateFare();
	t=&b;
	t->calculateFare();
	return 0;
}
