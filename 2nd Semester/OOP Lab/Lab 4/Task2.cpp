#include <iostream>
using namespace std;

class Student{
    string name;
    int rollNum;
    double marks;

public:
    Student(string n,int r,double m){
        name=n;
        rollNum=r;
        marks=m;
        cout << "Student Registered: " << name << " \nRoll number " << rollNum << endl;
    }
    ~Student(){
        cout << "Student Profile Deleted: " << name << endl;
    }
    void display(){
        cout << "Name: " << name << " \nRoll Number: " << rollNum << " \nMarks: " << marks << "%" << endl;
    }
};

int main(){
    Student student("Muhammad Wasil", 88, 79);
    student.display();
    return 0;
}