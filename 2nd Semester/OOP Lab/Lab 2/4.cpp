#include <iostream>
#include <string>
using namespace std;

struct Person{
	string name;
	int citno;
	double salary;
};

int main(){
	Person p;
	p.name="Wasil";
	p.citno=790;
	p.salary=150000;
	cout << "Name: " << p.name << endl;
	cout << "Citizenship number: " << p.citno << endl;
	cout << "Salary: " << p.salary << endl;
}
