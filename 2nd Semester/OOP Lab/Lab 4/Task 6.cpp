#include <iostream>
using namespace std;

class Devices{
	private:
		string name;
		string type;
		double rating;
		double usage;
	public:
		Devices(string n,string t,double r,double u){
			name=n;
			type=t;
			rating=r;
			usage=u;
			cout<<name<<"("<<type<<")"<<" is active!"<<endl;
		}
		void use(double u){
			usage+=u;
		}
		int energy(){
			return rating*usage/1000;
		}
		void display(){
			cout<<name<<" | "<<"type: "<<type<<" | power: "<<rating<<"W | hours used: "<<usage<<" | energy consumed: "<<energy()<<"kW"<<endl;
			
		}
		~Devices(){
			 cout<<name<<"("<<type<<")"<<" has been removed from tracking!"<<endl;
		}
};
int main(){
	Devices x("Smart Heater","Heater",2000,5);
	Devices y("Smart AC","AC",1500,8);
	x.display();
	y.display();
}
