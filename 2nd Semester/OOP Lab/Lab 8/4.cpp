#include <iostream>
using namespace std;

class HR;
class Manager;
class Employee{
	string name;
	double salary;
public:
	Employee(string n,double s):name(n),salary(s){}
	friend class HR;
};
class HR{
public:
	double updateSalary(Employee& e,double amount){
		e.salary=amount;
	}
	string getName(Employee& e)const{return e.name;}
	double getSal(Employee& e)const{return e.salary;}
	friend class Manager;
};
class Manager{
public:
	void viewSalary(HR& h,Employee& e){
		cout<<"Employe: "<<h.getName(e)<<" | Salary: "<<h.getSal(e)<<endl;
	}
};
int main(){
	Employee e("Wasil",100000);
	HR h;
	Manager m;
	m.viewSalary(h,e);
	h.updateSalary(e,150000);
	cout<<"After updating:"<<endl;
	m.viewSalary(h,e);
	return 0;
}
