#include <iostream>
using namespace std;

class Battery{
	double capacity;
	string type;
public:
	Battery (double c,string t):capacity(c),type(t){}
	double getCap(){
		return capacity;
	}
	string getType(){
		return type;
	}
};
class Smartphone{
	string brand;
	Battery b;
public:
	Smartphone(string br,double cap,string type):brand(br),b(cap, type){}
	void display(){
		cout <<"Smartphone Brand: "<<brand<<endl;
		cout << "Battery: "<<b.getCap()<<" mAh | Type: "<<b.getType()<<endl;
	}
};

int main(){
	Smartphone s("Oneplus",6000,"Li-Ion");
	s.display();
	return 0;
}
