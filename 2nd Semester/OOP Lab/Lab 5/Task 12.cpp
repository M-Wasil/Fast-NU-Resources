#include <iostream>
using namespace std;

class Student{
	string name;
	int iD;
	int grade;
public:
	Student() {}
	Student(string n,int ID,int g):name(n),iD(ID),grade(g){}
	string getName(){
		return name;
	}
	int getId(){
		return iD;
	}
	int getGrade(){
		return grade;
	}
	string setName(string c){
		name =c;
	}
	int setId(int i){
		iD =i;
	}
	int setGrade(int g){
		grade =g;
	}
};
class Course{
	string title;
	Student s[3];
public:
	Course() {}
	Course(string t):title(t){}
	void input(){
		for(int i=0;i<3;i++){
			string n;
            int id, g;
			cout<<"Enter student name: ";
			cin>>n;
			cout<<"Enter student ID: ";
			cin>>id;
			cout<<"Enter grade: ";
			cin>>g;
			s[i] = Student(n, id, g);
		}
		
	}
	void display(){
		cout<<"Course: "<<title<<" - Student List:"<<endl;
		for(int i=0;i<3;i++){
			cout<<"ID: "<<s[i].getId()<<" | Name: "<<s[i].getName()<<" | Grade: "<<s[i].getGrade()<<endl;
		}
	}
	void avg(){
		int calc=0;
		for (int i=0;i<3;i++){
			calc+=s[i].getGrade();
		}
		calc=calc/3;
		cout<<"Average Grade: "<<calc<<endl;
	}
	void top(){
		int max=s[0].getGrade(),j=0;
		for (int i=0;i<3;i++){
			if(s[i].getGrade() >max){
				max=s[i].getGrade();
				j=i;
			}
		}
		cout << "Top Student: "<<s[j].getName()<<" with "<<s[j].getGrade()<<" marks."<<endl;
	}
};

int main(){
	int x;
	cout <<"How many courses are there: ";
	cin>>x;
	Course* c =new Course[x];
	for (int i=0;i<x;i++){
		string title;
		cout << "Enter course title: ";
        cin.ignore();
        getline(cin, title);
        c[i] = Course(title);
		c[i].input();
	}
	for (int i = 0; i < x; i++) {
        c[i].display();
        c[i].avg();
        c[i].top();
    }
    delete[] c;
	return 0;
}
