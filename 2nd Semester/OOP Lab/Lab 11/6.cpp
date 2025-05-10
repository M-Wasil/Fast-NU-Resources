#include <iostream>
using namespace std;

class InvalidAgeException{
public:
    const char* what() const{
        return "InvalidAgeException caught: Age must be between 1 and 119";
    }
};
class InvalidSalaryException{
public:
    const char* what() const{
        return "InvalidSalaryException caught: Salary must be positive";
    }
};

class InvalidHeightException{
public:
    const char* what() const{
        return "InvalidHeightException caught: Height must be positive";
    }
};
int main(){
    int age;
    double salary;
    double height;
    cout << "Enter age: ";
    cin >> age;
    try{
        if (age<=0 || age>=120){
            throw InvalidAgeException();
        }
    } catch (InvalidAgeException& e){
        cout << e.what() << endl;
    }
    cout << "Enter salary: ";
    cin >> salary;
    try{
        if (salary<=0){
            throw InvalidSalaryException();
        }
    } catch (InvalidSalaryException& e) {
        cout << e.what() << endl;
    }
    cout << "Enter height: ";
    cin >> height;
    try {
        if (height <= 0){
            throw InvalidHeightException();
        }
    } catch (InvalidHeightException& e) {
        cout << e.what() << endl;
    }
}

