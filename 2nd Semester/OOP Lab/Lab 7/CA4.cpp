#include <iostream>
using namespace std;

class Base{
public:
	void disp(){
		cout<<"Function of parent class"<<endl;
	}
};

class Derived:public Base{
public:
	void disp(){
		cout<<"Function of child class"<<endl;
	}
};
int main(){
	Derived obj=Derived();
	obj.disp();
	return 0;
}
