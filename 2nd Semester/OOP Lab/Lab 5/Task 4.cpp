#include <iostream>
using namespace std;

class Warehouse{
	string location;
	int capacity;
	public:
		Warehouse (string l,int c):location(l),capacity(c) {}
		void display() const{
			cout << "Warehouse at " << location << " | Capacity: " << capacity <<" units" << endl;
		}
		string getLocation() const { return location; }
    	int getCapacity() const { return capacity; }
};
class DeliveryService{
	string id;
	Warehouse* start;
	Warehouse* dest;
	public:
		DeliveryService(string iD,Warehouse* s,Warehouse* d): id(iD),start(s),dest(d) {}
		void update(Warehouse* newDest){
			dest=newDest;
		}
		void display() const{
			cout << "Delivery Service: " << id<< endl;
			cout << "Starting Point: ";
			start->display();
			cout << "Current Destination: ";
			dest->display();
		}
};

int main(){
	Warehouse w1("New York", 1000);
    Warehouse w2("Los Angeles", 1500);
    Warehouse w3("Chicago", 1200);
	DeliveryService d("DS-001",&w1,&w2);
	d.display();
	cout << "After updating the destination:" << endl;
    d.update(&w3);
    d.display();
    return 0;
}
