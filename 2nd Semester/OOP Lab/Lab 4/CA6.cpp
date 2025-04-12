#include <iostream>
using namespace std;

class MyClass{
	public:
		MyClass(){
			cout << "Constructor called!Object created ." <<  endl;
		}
		~MyClass(){
			cout << "Destructor called! Obkect destroyed. " <<  endl;
		}
		void display(){
			cout << "Hello World!" << endl;
		}
};

int main(){
	MyClass obj;
	obj.display();
	cout << "Object is now out of scope." <<  endl;
}