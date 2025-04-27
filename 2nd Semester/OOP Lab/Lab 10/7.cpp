#include <iostream>
#include <fstream>
using namespace std;

struct Student{
	char name[50];
	int id;
	float gpa;
};

int main(){
	int count;
	cout<<"How many students are there? ";
	cin>>count;
	
	Student s[count];
	for (int i=0;i<count;i++){
		cout<<"Enter Student "<<i+1<<" name: ";
		cin>>s[i].name;
		cout<<"Enter Student "<<i+1<<" ID: ";
		cin>>s[i].id;
		cout<<"Enter Student "<<i+1<<" GPA: ";
		cin>>s[i].gpa;
	}
	ofstream outF("students.dat", ios::binary);
	for (int i=0;i<count;i++){
		outF.write((char*)&s[i], sizeof(s[i]));
	}
	outF.close();
	
	Student s1[count];
	ifstream f("students.dat", ios::binary);
	for (int i=0;i<count;i++){
		f.read((char*)&s1[i], sizeof(s1[i]));
	}
	f.close();
	
	for (int i=0;i<count;i++){
		cout<<"Student name: "<<s1[i].name<<endl;
		cout<<"Student ID: "<<s1[i].id<<endl;
		cout<<"Student GPA: "<<s1[i].gpa<<endl;
	}
	return 0;
}

