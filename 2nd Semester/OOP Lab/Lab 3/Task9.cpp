#include "Task9.h"

void Patient::display(){
    cout << "Patient Name: " << name << endl;
	cout << "Age: " << age << "\nDisease: " << disease << "\nRoom Number: " << roomNum;
}
int main(){
	Patient arr[100];
	int count = 0, choice;	
	cout << "Welcome to Record Management System\nSelect an option from the menu below: " << endl;	
	do{
		cout << "\n1. Add new patient\n2. Display patient details\n3. Update record\n4. Exit" << endl;
		cin >> choice;
		switch (choice){
			case 1:
				arr[count].add(arr, count);
				break;
			case 2:
				if (count == 0){
					cout << "Record Empty" << endl;
					break;
				}
				for (int i = 0; i < count; i++){
					arr[i].display();
				}
				break;
			case 3:{
				string temp;
				cout << "Enter the name of the patient whose record you want to update: ";
				cin.ignore();
				getline(cin, temp);
				
				bool found = false;
				for (int i = 0; i < count; i++) {
					if (arr[i].name == temp) {
						arr[i].update();
						found = true;
						break;
					}
				}
				if (!found) {
					cout << "Patient not found!" << endl;
				}
				break;
			}
			case 4:
				cout << "Exiting..." << endl;
				break;
			default:
				cout << "Invalid choice" << endl;
				break;
		}
	} while (choice != 4);
	return 0;
}


