#include <iostream>
#include <string>
using namespace std;

struct Student{
	string name;
	int rollNumber;
	char grades[5];
};

int main(){
	Student s;
	cout << "Enter Students name: ";
	cin >> s.name;
	cout << "Enter Students roll number: ";
	cin >> s.rollNumber;
	cout << "Enter Students grade for 5 subjects: ";
	for (int i=0; i<5; i++){
		cin >> s.grades[i];
	}
	cout << "Student name: " << s.name << endl;
	cout << "Roll number: " << s.rollNumber << endl;
	cout << "Grades: " <<endl;
	for (int i=0; i<5; i++){
		cout << s.grades[i] << endl;
	}
	
}
