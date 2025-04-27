#include <iostream>
#include <fstream>
using namespace std;

class Student{
public:
	int id;
	char name[50];
};

int main(){
	Student s1={101,"Muhammad Wasil"};
	ofstream outF("student.dat",ios::binary);
	outF.write((char*)&s1, sizeof(s1));
	outF.close();
	
	Student s2;
	ifstream inF("student.dat",ios::binary);
	inF.read((char*)&s2, sizeof(s2));
	inF.close();
	
	cout<<"Student ID: "<<s2.id<<endl;
	cout<<"Student name: "<<s2.name<<endl;
	return 0;
}
