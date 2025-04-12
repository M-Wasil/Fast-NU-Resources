#include <iostream>
using namespace std;

class Teacher;
class Student{
	string name;
	double grades[3];
public:
	Student(string n,double g1,double g2,double g3):name(n){
		grades[0]=g1;
		grades[1]=g2;
		grades[2]=g3;
	}
	friend class Teacher;
	friend double calcAverageGrade(const Student& s);
};
double calcAverageGrade(const Student& s){
	double sum=0;
	for (int i=0;i<3;i++){
		sum+=s.grades[i];
	}
	return sum/3;
}
class Teacher{
public:
	void updateGrade(Student& s,int index,double newGrade){
		if(index>=0 && index<3){
			s.grades[index]=newGrade;
			cout<<"Grade Updated!"<<endl;
		}else{
			cout<<"Invalaid grade index!"<<endl;
		}
	}
	void view(const Student& s){
		cout<<"Grades for "<<s.name<<": "<<endl;
		for (int i=0;i<3;i++){
			cout<<"Grade "<<i+1<<" : "<<s.grades[i]<<endl;
		}
	}
};

int main(){
	Student s("Wasil",85.0,90.0,78.0);
	Teacher t;
	t.view(s);
	t.updateGrade(s,1,95.0);
	t.view(s);
	double avg=calcAverageGrade(s);
	cout<<"Average Grade: "<<avg<<endl;
	
	return 0;
}
