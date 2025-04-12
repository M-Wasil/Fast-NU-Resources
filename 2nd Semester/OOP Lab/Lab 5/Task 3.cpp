#include <iostream>
using namespace std;

class Patient{
    string name;
    int age;
    string condition;
public:
    Patient(string n = "", int a = 0, string m = "") : name(n), age(a), condition(m) {}
    void display() const{
        cout << "Name: " << name << ", Age: " << age << ", Condition: " << condition << endl;
    }
};
class Hospital{
    Patient patients[5];
    int count;
public:
    Hospital() : count(0) {}
    void addPatient(string name, int age, string condition){
        if (count < 5){
            patients[count] = Patient(name, age, condition);
            count++;
        } else{
            cout << "Hospital is full, cannot add more patients." << endl;
        }
    }
    void displayPatients() const{
        cout << "Hospital Patient Records:" << endl;
        for (int i = 0; i < count; i++) {
            patients[i].display();
        }
    }
};

int main(){
    Hospital h;
    h.addPatient("Alice", 30, "Flu");
    h.addPatient("Bob", 45, "Diabetes");
    h.addPatient("Charlie", 50, "High Blood Pressure");
    h.displayPatients();
    return 0;
}

