#include <iostream>
#include <string>
using namespace std;

struct Student{
	string name;
	int rollNumber;
	int grades[5];
	int year;
};

void total(Student* s) {
    int total =0,max=0;
    for (int i =0; i<5;i++){
        int totalMarks =0;
        for (int j =0; j<5;j++){
            totalMarks += s[i].grades[j];
        }
        cout << "Total for student " << s[i].name << " (Roll No: " << s[i].rollNumber << ") is: " << totalMarks << endl;
        if (totalMarks > total){
            total = totalMarks;
            max =i;
        }
    }
    cout << "Student with highest total marks:" << endl;
    cout << "Name: " << s[max].name << "\nRoll Number: " << s[max].rollNumber
         << "\nYear: " << s[max].year << "\nTotal Marks: " << total << endl;
}
	
int main(){
	Student* s= new Student[5];
	for (int i=0; i<5; i++){
		cout << "Enter details for student " << i+1 <<":" << endl;
		cout << "Enter Students name: ";
		cin.ignore();
		getline(cin, s[i].name);
		cout << "Enter Students roll number: ";
		cin >> s[i].rollNumber;
		cout << "Enter year: ";
		cin >> s[i].year;
		cout << "Enter Students grade for 5 subjects(on a scale of 1 to 9): ";
		for (int j=0; j<5; j++){
            cin >> s[i].grades[j];
        }
	}
	total(s);
	delete[] s;
}
