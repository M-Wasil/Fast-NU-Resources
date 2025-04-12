#include <iostream>
using namespace std;

class Employee{
public:
	string name;
	int id;
	int salary;
	Employee(string n, int i, int s):name(n),id(i),salary(s) {}
	void display(){
		cout<<"Employee Name: "<<name<<endl;
		cout<<"Employee ID: "<<id<<endl;
		cout<<"Salary: $"<<salary<<endl;
	}
};
class Manager: public Employee{
	int bonus;
public:
	Manager(string n, int i, int s,int b):Employee(n,i,s),bonus(b) {}
	void displayDetails(){
		display();
		cout<<"Bonus: $"<<bonus<<endl;
		cout<<"Total Slalary: $"<<bonus+salary<<endl;
	}
};

int main(){
	Employee e("Wasil",790,80000);
	Manager m("Faraz",101,120000,50000);
	cout<<"Employee Details:"<<endl;
	e.display();
	cout<<"Manager Details:"<<endl;
	m.displayDetails();
}
