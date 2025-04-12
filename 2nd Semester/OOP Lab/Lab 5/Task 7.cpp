#include <iostream>
using namespace std;

class Shop{
	string name;
	int iD;
	static int nextID;
public:
	Shop(string n):name(n){
		iD=nextID++;
	}
	void dis(){
		cout<<"Customer ID: "<<iD<<" | Name: "<<name<<endl;
	}
	static void display(){
		cout<<"Next ID: "<<nextID<<endl;
	}
};
int Shop::nextID=5000;

int main(){
	Shop s1("Alice"), s2("Bob"), s3("Charlie");
	s1.dis();
    s2.dis();
    s3.dis();
	Shop::display();
	return 0;
}
