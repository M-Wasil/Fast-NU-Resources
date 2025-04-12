#include <iostream>
using namespace std;

class Animal{
public:
	virtual void makeSound(){
		cout<<"Animal is making sound"<<endl;
	}
};
class Dog: public Animal{
public:
	void makeSound() {
		cout<<"Dog: Woof!"<<endl;
	}
};
class Cat: public Animal{
public:
	void makeSound() {
		cout<<"Cat: Meow!"<<endl;
	}
};

int main(){
	Animal *a;
	Dog d;
	Cat c;
	a=&d;
	a->makeSound();
	a=&c;
	a->makeSound();
	return 0;
}
