#include <iostream>
using namespace std;

struct Customer{
	string name;
	int amount;
	Customer* c;
};

Customer* lists(){
	Customer* first= new Customer{"Saad",1200,nullptr};
	Customer* second= new Customer{"Akbar",180,nullptr};
	Customer* third= new Customer{"Ali",2590,nullptr};
	
	first->c=second;
	second->c=third;
	return first;
}

void display(Customer* c){
	Customer* temp=c;
    while (temp !=nullptr){
        cout << "Name: " << temp->name << ", Purchase Amount: $" << temp->amount << endl;
        temp = temp->c;
    }
}

int main(){
	Customer* c=lists();
	cout << "Customers: " << endl;
	display(c);
	Customer* temp;
    while (c !=nullptr){
        temp=c;
        c =c->c;
        delete temp;
    }
}

