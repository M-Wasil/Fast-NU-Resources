#include <iostream>
using namespace std;

struct Vehicle{
	int regNum;
	string name;
	string model;
};

int main(){
	Vehicle v;
	v.regNum=790;
	v.name="Wasil";
	v.model="Santa Fe";
	cout << "Car Registration Number: " << v.regNum << endl;
	cout << "Owner: " << v.name << endl;
	cout << "Model: " << v.model << endl;
}
