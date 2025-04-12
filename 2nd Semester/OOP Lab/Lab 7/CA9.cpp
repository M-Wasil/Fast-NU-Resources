#include <iostream>
using namespace std;

class A{
public:
	virtual void show(){
		cout<<"Base class"<<endl;
	}
};

class B:public A{
public:
	void show(){
		cout<<"Derived class"<<endl;
	}
};
int main(){
	A *a;
	B b;
	a=&b;
	a->show();
	return 0;
}
