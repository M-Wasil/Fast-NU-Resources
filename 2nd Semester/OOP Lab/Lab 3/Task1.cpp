#include <iostream>
#include <string>
using namespace std;

class Car{
	public:
	string brand;
	string model;
	int year;
	
	Car(string n,string m,int y) : brand(n), model(m), year(y) {}
	
	void display(){
		cout << "Car Model: " << model << " Brand: " << brand << " Year: " << year << endl;
	}
};

int main(){
	Car c1("Toyota ","Corolla",2020);
	c1.display();
	return 0;
}
