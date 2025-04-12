#include <iostream>
using namespace std;

class Employee{
	string name;
	const int id;
	public:
		Employee (string empName,int empId):name(empName),id(empId){}
		void displayDetails()const{
			cout << "Employee Name: " << name<<endl;
			cout << "Employee ID: " << id<<endl;
		}
		void updateName(string n){
			name=n;
			cout << "Name updated to "<<name<<endl;
		}
};
int main(){
	Employee e("Wasil",790);
	cout << "Initial Employee Details: " << endl;
	e.displayDetails();
	e.updateName("Muhammad Wasil");
	cout << "Updated Employee name: "<<endl;
	e.displayDetails();
}