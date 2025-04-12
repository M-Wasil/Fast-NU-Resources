#include <iostream>
using namespace std;
class Employee{
public:
	string name;
	int id;
	Employee(string empName, int empId) : name(empName), id(empId) {}
	void display() const {
		cout << "Emloyee id: " << id << ", Name: " << name << endl;
	}
};
class Department{
	string deptName;
	Employee* employees[10];
	int employeeCount = 0;
public:
	Department(string name) : deptName(name){}

	void addEmployee(Employee* e){
		employees[employeeCount++] = e;
	}
	void displayDepartment()const{
		cout << "Department:" << deptName << "\nEmployees:" << endl;
		for (int i = 0; i < employeeCount; i++) employees[i]->display();
	}
};
int main(){
	Employee e1("Babar Azan", 52), e2("Shaheen Shah Afridi", 78), e3("Rizwan", 36);
	Department d("Data Scientist");
	d.addEmployee(&e1);
	d.addEmployee(&e2);
	d.displayDepartment();
	cout << endl << "Independent Employee: " << endl;
	e3.display();
}