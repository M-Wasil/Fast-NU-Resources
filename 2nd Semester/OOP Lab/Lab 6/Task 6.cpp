#include <iostream>
using namespace std;

class Transport{
public:
	string type;
	int capacity;
	Transport(string t,int c):type(t),capacity(c){}
	
};
class RoadTransport:virtual public Transport{
public:
	string rType;
	RoadTransport(string t,int c,string r):Transport(t,c), rType(r) {}
	
};
class AirTransport:virtual public Transport{
public:
	int alt;
	AirTransport(string t,int c,int a):Transport(t,c), alt(a){}
	
};
class HybridVehicle:public AirTransport, RoadTransport{
public:
	float fuel;
	HybridVehicle(string t,int c,float f,int a,string r):Transport(t, c),AirTransport(t,c,a),RoadTransport(t,c,r),fuel(f) {}
	void display(){
		cout<<"=== Hybrid Vehicle Details ==="<<endl;
		cout<<"Vehicle type: "<<type<<endl;
		cout<<"Max Capacity: "<<capacity<<" passengers"<<endl;
		cout<<"Road Type:: "<<rType<<endl;
		cout<<"Max Altitude: "<<alt<<" feet"<<endl;
		cout<<"Fuel Efficiency: "<<fuel<<" km/l"<<endl;
	}
};
int main(){
	HybridVehicle v1("Sedan", 5,13.2,5000,"Highway");
	v1.display();
}
