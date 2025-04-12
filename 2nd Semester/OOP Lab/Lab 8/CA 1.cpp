#include <iostream>
using namespace std;

class Humidity;
class Temperature{
	float temp;
public:
	Temperature(float t):temp(t){}
	friend float calcHeatIndex(Temperature t,Humidity h);
};
class Humidity{
	float humidity;
public:
	Humidity(float h):humidity(h){}
	friend float calcHeatIndex(Temperature t,Humidity h);
};
float calcHeatIndex(Temperature t,Humidity h){
	float HI=-42.379+2.04901523*t.temp+10.14333127*h.humidity-0.22475541*t.temp*h.humidity;
	return HI;
}

int main(){
	Temperature temp(32.0);
	Humidity h(70.0);
	float heatIndex=calcHeatIndex(temp,h);
	cout<<"Heat Index is: "<<heatIndex<<" C"<<endl;
	return 0;
}
