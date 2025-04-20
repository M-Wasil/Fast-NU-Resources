#include<iostream>
using namespace std;

class Car{
	private:
		string engine;
		int currentSpeed;
		string fuel;
	public:
		Car(string eng,int speed,string fuel):fuel(fuel),engine(eng),currentSpeed(speed){
		}
		void startEngine(){
			engine="Start";
		}
		
		void stopEngine(){
			engine="Stop";
		}
		
		void setSpeed(int speed){
			currentSpeed=speed;
		}
		
		int getSpeed(){
			return currentSpeed;
		}
		void display(){
			cout<<"Engine: "<<engine<<" Current Speed: "<<currentSpeed<<" Fuel level :"<<fuel<<endl;
		}
};

int main(){
	Car c1("stop",24,"below average");
	c1.display();
	c1.setSpeed(120);
	c1.startEngine();
	c1.display();
	
}
