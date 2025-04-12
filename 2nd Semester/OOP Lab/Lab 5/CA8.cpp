#include <iostream>
#include <cstring>
using namespace std;

class Employee{
    int id;
    char name[30];
public:
    void take_data(int id, char name[]){
        this->id =id;
        strcpy(this->name,name);
    }

    void display_data(){
        cout << id << " " << name << " " << endl;
    }
};

int main(){
    Employee emp[30];
    int n, i;
    cout << "Enter number of employees: ";
    cin >> n;
    for (int i=0;i<n;i++){
        int id;
        char name[30];
        cout << "Enter Id: ";
        cin >> id;
        cout << "Enter Name: ";
        cin >> name;
        emp[i].take_data(id, name);
    }
    cout << "Employee Data" << endl;
    for (int i=0;i<n;i++){
        emp[i].display_data();
    }
}