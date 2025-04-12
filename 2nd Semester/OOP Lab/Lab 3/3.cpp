#include <iostream>
using namespace std;

class Car{
	int num;
	char model[10];
	public:
		void getdata();
		void showdata();
};

void Car::getdata(){
	cout << "Enter car number: ";
	cin >> num;
	cout << "Enter car model: ";
	cin >> model;
}

void Car::showdata(){
	cout << "Car number is: " << num << endl;
	cout << "Car model is: " << model;
}

int main(){
	Car c1;
	c1.getdata();
	c1.showdata();
	return 0;
}
