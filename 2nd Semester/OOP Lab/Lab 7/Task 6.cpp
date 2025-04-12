#include <iostream>
using namespace std;

class SmartDevice{
public:
	virtual void performAction(){
		cout<<"Performing Action!"<<endl;
	}
};
class SmartLight: public SmartDevice{
public:
	void performAction(){
		cout<<"Smart Light: Turning on the lights"<<endl;
	}
};
class SmartThermostat: public SmartDevice{
public:
	void performAction(){
		cout<<"Smart Thermostat: Setting temperature to 22°C"<<endl;
	}
};

int main(){
	SmartDevice* s;
	SmartLight l;
	SmartThermostat t;
	s=&l;
	s->performAction();
	s=&t;
	s->performAction();
	return 0;
}
