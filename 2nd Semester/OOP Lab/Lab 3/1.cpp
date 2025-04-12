#include <iostream>
using namespace std;

class Student{
	int rollno;
	public:
		int getrollno(){
			return rollno;
		}
		void setrollno(int i){
			rollno=i;
		}
};

int  main(){
	Student A;
	A.setrollno(1);
	cout << A.getrollno();
	return 0;
}
