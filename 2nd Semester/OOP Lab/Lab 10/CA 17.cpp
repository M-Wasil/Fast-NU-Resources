#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student{
public:
	int rollno;
	string name;
	float marks;
};

void writeF(){
	ofstream outF("Students.txt",ios::app);
	Student s;
	cout<<"Enter roll number: ";
	cin>>s.rollno;
	cin.ignore();
	cout<<"Enter name: ";
	getline(cin,s.name);
	cout<<"Enter marks: ";
	cin>>s.marks;
	
	if (outF.is_open()){
		outF<<s.rollno<<", "<< s.name<<", "<<s.marks<<endl;
		outF.close();
		cout<<"Student data saved successfully";
	}else{
		cout<<"Unable to open file for writing"<<endl;
	}
}
void readF(){
	ifstream inF("Students.txt");
	string line;
	
	cout<<"\n--- Student Records ---\n";
	if (inF.is_open()){
		while (getline(inF,line)){
			cout<<line<<endl;
		}
		inF.close();
	}else{
		cout<<"Unable to open file for reading!\n";
	}
}

int main(){
	int choice;
	do{
		cout<<"\n1. Add student record\n";
		cout<<"2. View All records\n";
		cout<<"3. Exit\n";
		cout<<"Enter your choice: ";
		cin>>choice;
		
		switch(choice){
			case 1:writeF();break;
			case 2:readF();break;
			case 3:cout<<"Exiting...\n";break;
			default:cout<<"Invalid choice!\n";
		}
	}while (choice !=3);
	return 0;
}
