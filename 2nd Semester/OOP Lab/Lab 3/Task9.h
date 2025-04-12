#ifndef TASK9_H
#define TASK9_H

#include <iostream>
using namespace std;

class Patient{
	public:
		string name;
		int age;
		string disease;
		int roomNum;
		Patient(): name(""),age(0),disease(""),roomNum(0){}
		Patient(string n,int a,string d, int r) : name(n),age(a), disease(d), roomNum(r){}
		void add(Patient arr[],int &count){
			if (count >=100){
				cout << "No rooms available" << endl;
				return;
			}
			Patient p;
			cout << "Enter patient's name: ";
			cin >> p.name;
			cout << "\nEnter age: ";
			cin >> p.age;
			cout << "\nEnter disease: ";
			cin >> p.disease;
			cout << "\nEnter room number of the patient: ";
			cin >> p.roomNum;
			arr[count]=p;
			cout << "Patient added successfully" <<endl;
			count++;
		}
		void update(){
			cout << "Enter patient's name: " ;
			cin >> name;
			cout << "\nEnter age: ";
			cin >> age;
			cout << "\nEnter disease: ";
			cin >> disease;
			cout << "\nEnter room number of the patient: ";
			cin >> roomNum;
			cout << "Record updated successfully" <<endl;
		}
		void display();
};
#endif
