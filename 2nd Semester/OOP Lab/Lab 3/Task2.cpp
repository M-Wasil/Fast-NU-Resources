#include <iostream>
using namespace std;
#include <string>

class student{
	string name;
	int rollno;
	int age;
	public:
		student(string n,int r,int a): name(n),rollno(r),age(a){}
		void displaystudent(){
			cout<<name<<rollno<<age<<endl;
		}
		
};
int main(){
	student A("Wasil",70,90);
	A.displaystudent();
	return 0;
}
