#include <iostream>
#include <string>
using namespace std;

class Car{
	public:
	string model;
	int year;
	
	Car(string m,int y) : model(m), year(y) {}
	
	void display(){
		cout << "Car Model: " << model << "Year: " << year << endl;
	}
};

int main(){
	Car c1("Toyota ",2020);
	c1.display();
	return 0;
}
