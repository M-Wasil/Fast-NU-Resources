#include <iostream>
using namespace std;

class Person{
public:
	string name;
	int age;
	Person(string n,int a):name(n),age(a) {}
};
class Doctor:public Person{
public:
	string specialization;
	Doctor(string n,int a,string s):Person(n,a),specialization(s){}
	
};
class Surgeon:public Doctor{
public:
	int sCount;
	Surgeon(string n,int a,string s,int sc):Doctor(n,a,s),sCount(sc){}
	void display(){
		cout<<"Name: Dr."<<name<<endl;
		cout<<"Age: "<<age<<endl;
		cout<<"Specialization: "<<specialization<<endl;
		cout<<"Surgeries performed: "<<sCount<<endl;
	}
};
int main(){
	Surgeon s("Muhammad Wasil",18,"Neurosurgeon",73);
	cout<<"=== Surgeon Details ==="<<endl;
	s.display();
}

