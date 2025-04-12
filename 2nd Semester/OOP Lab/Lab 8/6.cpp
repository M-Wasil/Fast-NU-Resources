#include <iostream>
using namespace std;

class HR;
class Payroll;
class Employee{
    string name;
    double salary;
    int workHours;
public:
    Employee(string n,double s,int w):name(n),salary(s),workHours(w){}
    friend class HR;
    friend void computeFinalSalary(Employee& e);
};
class HR{
public:
    void updateSalary(Employee& e,double newSalary){
        e.salary=newSalary;
    }
    void updateWorkHours(Employee& e,int newHours){
        e.workHours=newHours;
    }
};
void computeFinalSalary(Employee& e){
    double finalSalary=e.salary;
    if(e.workHours>40){
        finalSalary+=5000;
    }
    else if(e.workHours<30){
        finalSalary-=3000;
    }
    cout<<"Final salary for "<<e.name<<": $"<<finalSalary<<endl;
}

int main(){
    Employee emp("Wasil",50000,35);
    HR hr;
    
    hr.updateSalary(emp,55000);
    hr.updateWorkHours(emp,45);
    
    computeFinalSalary(emp);
    
    return 0;
}
