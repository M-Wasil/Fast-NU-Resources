#include <iostream>
using namespace std;

class Student{
	string name;
	int rollNum;
	int marks[5];
	int totalMarks;
	float percentage;
	char grade;
	public:
		void inputDetails(string n,int r,int m[]){
			name=n;
			rollNum=r;
			for (int i=0;i<5;i++){
				marks[i]=m[i];
			}
		}
		void calculate(){
			totalMarks=0;
			for (int i=0;i<5;i++){
				totalMarks+=marks[i];
			}
			percentage=(totalMarks/500.0)*100;
			if (percentage>=90){
				grade='A';
			}else if(percentage>=70 && percentage<90){
				grade='B';
			}else if(percentage>=50 && percentage<70){
				grade='C';
			}
			else if(percentage<50){
				grade='F';
			}
		}
		void Report(){
			cout << "Name: " << name << endl;
			cout << "Roll number: " << rollNum << endl;
			cout << "Percentage: " << percentage << endl;
			cout << "Grade: " << grade << endl;
		}
};

int main(){
	Student s1;
	int marks[]={90,77,83,89,86};
	s1.inputDetails("Wasil",790,marks);
	s1.calculate();
	s1.Report();
}
