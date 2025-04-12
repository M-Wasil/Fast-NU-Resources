#include <iostream>
using namespace std;

class Vehicle{
protected:
    int iD;
    static int total;
    double speed;
    double capacity;
    double efficiency;

public:
    Vehicle(int id, double spd, double cap, double eff):iD(id), speed(spd), capacity(cap), efficiency(eff){
        total++;
    }
    virtual void deliver(){
        cout << "Delivering..." << endl;
    }
    virtual void command(string cmd, int packageID){
        cout << "Executing basic delivery command" << endl;
    }
    virtual void command(string cmd, int packageID, string urgency){
        cout << "Executing urgent delivery command" << endl;
    }
    void route(){
        int r;
        cout << "\nHow many routes are there: ";
        cin >> r;
        int* dis = new int[r];
        cout << "Enter distance for each route: " << endl;
        for(int i = 0; i < r; i++){
            cout << "Route " << i+1 << " distance: ";
            cin >> dis[i];
        }
        int min = dis[0], m = 0;
        for(int i = 0; i < r; i++){
            if(dis[i] < min){
                min = dis[i];
                m = i+1;
            }
        }
        cout << "Optimal delivery route is: Route " << m << " (" << min << "km)" << endl;
        delete[] dis;
    }
    
    virtual void time(){
        string choice;
        int dis;
        cout << "\nEnter delivery distance (km): ";
        cin >> dis;
        cout << "Is there traffic? (yes/no): ";
        cin >> choice;
        
        if(choice == "yes"){
            if(dis < 15){
            	cout << "Estimated time: 25 mins\n";
			}
            else if(dis < 35){
            	cout << "Estimated time: 50 mins\n";
			}
            else{
            	cout << "Estimated time: 1 hour\n";
			}
        }
        else{
            if(dis < 15){
            	cout << "Estimated time: 20 mins\n";
			}
            else if(dis < 35){
            	cout << "Estimated time: 40 mins\n";
			}
            else{
            	cout << "Estimated time: 55 mins\n";
			}
        }
    }
    
    friend bool operator==(const Vehicle& v1, const Vehicle& v2);
    friend void compareEfficiency(Vehicle* v1, Vehicle* v2);
    static int getTotalDeliveries(){ return total; }
};

int Vehicle::total = 0;

bool operator==(const Vehicle& v1, const Vehicle& v2){
    return (v1.speed * v1.efficiency == v2.speed * v2.efficiency);
}

class Drone :public Vehicle{
public:
    Drone(int id, double spd, double cap, double eff): Vehicle(id, spd, cap, eff) {}
    
    void deliver() override{
        cout << "Drone " << iD << ": Delivering iftar meals by air\n";
    }
    
    void command(string cmd, int packageID, string urgency) override{
        cout << "Drone activating high-speed mode for ";
        cout << urgency << " delivery (Package " << packageID << ")\n";
    }
};

class Ship : public Vehicle{
public:
    Ship(int id, double spd, double cap, double eff): Vehicle(id, spd, cap, eff) {}
    
    void deliver() override{
        cout << "TimeShip " <<iD << ": Delivering across time periods\n";
    }
    
    void command(string cmd, int packageID, string urgency) override{
        cout << "TimeShip validating historical consistency for ";
        cout << urgency << " delivery (Package " << packageID << ")\n";
    }    
};

class Pod : public Vehicle{
public:
    Pod(int id, double spd, double cap, double eff): Vehicle(id, spd, cap, eff) {}
    void deliver() override{
        cout << "HyperPod " << iD << ": Bulk delivery through hyperloop\n";
    }
    void command(string cmd, int packageID) override{
        cout << "HyperPod maximum speed delivery (Package " << packageID << ")\n";
    }
};

class AiAssistant{
    string destination;
    string urgency;
    int weight;
    int distance;
    
public:
    AiAssistant(string dest, string urg, int w, int d): destination(dest), urgency(urg), weight(w), distance(d) {}
    void deliver(Vehicle* drone, Vehicle* ship, Vehicle* pod){
        cout << "\nAI Assistant Decision (" << destination << "):\n";
        if(weight < 10 && urgency == "Iftar"){
            drone->deliver();
            drone->command("Deliver", 1, urgency);
        }
        else if(distance > 100 || urgency == "Historical"){
            ship->deliver();
            ship->command("Deliver", 2, urgency);
        }
        else{
            pod->deliver();
            pod->command("Deliver", 3);
        }
    }
};

void compareEfficiency(Vehicle* v1, Vehicle* v2){
    double eff1 = v1->speed * v1->efficiency;
    double eff2 = v2->speed * v2->efficiency;
    
    cout << "\nEfficiency Comparison:\n";
    cout << "Vehicle 1 Efficiency: " << eff1 << endl;
    cout << "Vehicle 2 Efficiency: " << eff2 << endl;
    
    if(eff1 > eff2){
    	cout << "First vehicle is more efficient\n";
	}
    else if(eff1 < eff2){
    	cout << "Second vehicle is more efficient\n";
	}
    else{
    	cout << "Both vehicles have equal efficiency\n";
	}
}

int main(){
    int id;
    double spd, cap, eff;
    
    cout << "Enter Drone Details:\n";
    cout << "ID Speed Capacity Efficiency: ";
    cin >> id >> spd >> cap >> eff;
    Drone d(id, spd, cap, eff);
    
    cout << "\nEnter TimeShip Details:\n";
    cout << "ID Speed Capacity Efficiency: ";
    cin >> id >> spd >> cap >> eff;
    Ship s(id, spd, cap, eff);
    
    cout << "\nEnter HyperPod Details:\n";
    cout << "ID Speed Capacity Efficiency: ";
    cin >> id >> spd >> cap >> eff;
    Pod p(id, spd, cap, eff);
    
    string dest, urg;
    int weight, dist;
    cout << "\nEnter Delivery Request:\n";
    cout << "Destination Urgency(Sehri/Iftar/Historical) Weight Distance: ";
    cin >> dest >> urg >> weight >> dist;
    AiAssistant assistant(dest, urg, weight, dist);
    
    cout << "\nRoute Calculation";
    d.route();
    
    cout << "\nDelivery Time Estimation";
    d.time();
    
    cout << "\nDelivery Demonstrations" << endl;
    d.deliver();
    s.deliver();
    p.deliver();
    
    assistant.deliver(&d, &s, &p);
    
    compareEfficiency(&d, &s);
    compareEfficiency(&d, &p);
    
    cout << "\n=== Operator Comparisons ===" << endl;
    if(d == s){
    	cout << "Drone and Ship are equally efficient\n";
	}
    else{
    	cout << "Drone and Ship have different efficiency\n";
	}
    
    if(d == p){
    	cout << "Drone and Pod are equally efficient\n";
	}
    else{
    	cout << "Drone and Pod have different efficiency\n";
	}
    cout << "\nTotal deliveries: " << Vehicle::getTotalDeliveries() << endl;
    
    return 0;
}
