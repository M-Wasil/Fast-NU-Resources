#include <iostream>
using namespace std;

class Device{
public:
	string name;
	string status;
	Device(string n,string s):name(n),status(s){}
	virtual void turnOn(){
        status = "On";
        cout <<name << " is ON." << endl;
    }

    virtual void turnOff(){
        status = "Off";
        cout << name << " is OFF." << endl;
    }
};
class SmartLight:virtual public Device{
public:
	string brightness;
	SmartLight(string s,string b) :Device("Smart Light",s),brightness(b) {}
	void turnOn() override {
        status = "On";
        cout <<"Smart Light is ON with " << brightness << " brightness." << endl;
    }
    ~SmartLight(){
        status = "Off";
        cout <<"Smart Light is now OFF." << endl;
    }
};
class SmartFan:virtual public Device{
public:
	string speed;
	SmartFan(string s,string v) :Device("Smart Fan",s),speed(v) {}
	void turnOn() override{
        status = "On";
        cout <<"Smart Fan is ON at " << speed << " speed." << endl;
    }
    ~SmartFan(){
        status = "Off";
        cout << "Smart Fan is now OFF." << endl;
    }
};
class SmartRoom:public SmartFan,public SmartLight{
public:
	SmartRoom(string s,string b,string v):Device("Smart Room",s),SmartLight(s,b),SmartFan(s,v){}
	void turnOn() override{
        SmartLight::turnOn();
        SmartFan::turnOn();
        cout << "Smart Room is now fully activated!" << endl;
    }
};
int main(){
	SmartRoom r1("Off","adjustable","medium");
	r1.turnOn();
}

