#include <iostream>
#include <string>
using namespace std;

class BusStop
{
private:
    string location;

public:
    BusStop() {}
    BusStop(string loc) : location(loc){}
    string getLocation() const{
		return location;
	}
    void displayStop() const{
		cout << "Location: " << location << "\n";
	}
};

class Route{
private:
    string routeID;
    BusStop stops[50];
    int stopCount;

public:
    Route() : routeID(""), stopCount(0) {}
    Route(string id) : routeID(id), stopCount(0) {}
    void addStop(BusStop stop){
        if (stopCount<50){
            stops[stopCount++] =stop;
        }
    }
    void displayStops() const{
        cout << "Route " << routeID << " has the following stops:\n";
        for (int i = 0; i < stopCount; i++){
            stops[i].displayStop();
        }
    }
    string getRouteID() const{
		return routeID;
	}


};

class Student{
private:
    string studentID, name;
    bool cardStatus;
    double balance;
    BusStop pickupStop,dropoffStop;
    string assignedRoute;

public:
    Student() : cardStatus(false),balance(0) {}
    Student(string id, string n) : studentID(id), name(n), cardStatus(false), balance(0) {}
    void payFees(double amount){
        balance += amount;
        if (balance >= 5000){
            cardStatus = true;
        }
    }
    void assignStops(BusStop pickup, BusStop dropoff, string route){
        pickupStop = pickup;
        dropoffStop = dropoff;
        assignedRoute = route;
    }
    void tapCard() const{
        if (cardStatus) {
        	cout << name << " checked in at stop " << pickupStop.getLocation() << " on route " << assignedRoute << " and will be dropped at " << dropoffStop.getLocation() << "\n";
		}
        else{
        	cout << "Card inactive or stops not assigned!\n";
		}
    }
    void displayStudent() const{
        cout << "ID: " << studentID << " Name: " << name << " Balance: " << balance << " Card Status: " << (cardStatus ? "Active" : "Inactive") << "\n";
    }
    string getID() const{
		return studentID;
	}
    double getBalance() const{
		return balance;
	}
};

class TransportSystem{
private:
    Student students[100];
    int studentCount;
    BusStop stops[50];
    int stopCount;
    Route routes[20];
    int routeCount;

public:
    TransportSystem() : studentCount(0), stopCount(0), routeCount(0) {}
    void registerStudent(string id){
        cin.ignore();
        string name;
        cout << "Enter Student Name: ";
        getline(cin, name);
        if (studentCount < 100){
            students[studentCount++] = Student(id, name);
            cout << "Student " << name << " registered successfully.\n";
        }
    }
    Route *getRoute(string id){
        for (int i = 0; i < routeCount; i++){
            if (routes[i].getRouteID() == id)
                return &routes[i];
        }
        return nullptr;
    }
    void assignRoute(string id, string routeID, string pickupName, string dropoffName){
        Student *student = getStudent(id);
        if (!student){
            cout << "Student not found.\n";
            return;
        }
        Route *route = getRoute(routeID);
        if (!route){
            cout << "Error: Route ID does not exist.\n";
            return;
        }

        BusStop *pickup = nullptr, *dropoff = nullptr;
        for (int i = 0; i < stopCount; i++){
            if (stops[i].getLocation() == pickupName){
            	pickup = &stops[i];
			}
            if (stops[i].getLocation() == dropoffName){
            	dropoff = &stops[i];
			}
        }
        if (!pickup){
            addBusStop(pickupName);
            pickup = &stops[stopCount-1];
        }
        if (!dropoff){
            addBusStop(dropoffName);
            dropoff = &stops[stopCount-1];
        }
        student->assignStops(*pickup, *dropoff,routeID);
        cout << "Route assigned successfully: Pickup at " << pickup->getLocation() << ", Dropoff at " << dropoff->getLocation() << ".\n";
    }
    void createRoute(string id){
    	if (routeCount < 20){
    	    routes[routeCount++] = Route(id);
    	    cout << "Route " << id << " added successfully!\n";
    	}
    	else{
    	    cout << "Maximum route limit reached!\n";
    	}
	}
    void recordAttendance(string id){
        Student *student = getStudent(id);
        if (student){
            student->tapCard();
        }
        else{
            cout << "Student not found.\n";
        }
    }

    void paySemesterFees(string id, double amount){
        Student *student = getStudent(id);
        if (student){
            student->payFees(amount);
            cout << "Payment successful. Current balance: " << student->getBalance() << "\n";
            if (student->getBalance() >= 5000)
                cout << "Card is now Active!\n";
        }
        else{
            cout << "Student not found.\n";
        }
    }
    void addBusStop(string location){
        if (stopCount <50){
            stops[stopCount++] = BusStop(location);
            cout << "Bus stop added: " << location << "\n";
        }
    }
    Student *getStudent(string id){
        for (int i = 0; i <studentCount;i++){
            if (students[i].getID() == id)
                return &students[i];
        }
        return nullptr;
    }
};

int main(){
    TransportSystem system;
    int choice;
    do{
        cout << "\nTransport System Menu:\n";
        cout << "1. Register Student\n2. Assign Route\n3. Pay Semester Fees\n4. Record Attendance\n5. Add Bus Stop\n6. Exit\n7. Add Route\nEnter choice: ";
        cin >> choice;
        string id, routeID, pickupName, dropoffName, location;
        double amount;
        switch (choice){
        case 1:
            cout << "Enter Student ID: ";
            cin >> id;
            system.registerStudent(id);
            break;
        case 2:
            cout << "Enter Student ID: ";
            cin >> id;
            cout << "Enter Route ID: ";
            cin >> routeID;
            cin.ignore();
            cout << "Enter Pickup Stop Name: ";
            getline(cin, pickupName);
            cout << "Enter Dropoff Stop Name: ";
            getline(cin, dropoffName);
            system.assignRoute(id, routeID, pickupName, dropoffName);
            break;
        case 3:
            cout << "Enter Student ID: ";
            cin >> id;
            cout << "Enter amount to pay: ";
            cin >> amount;
            system.paySemesterFees(id, amount);
            break;
        case 4:
            cout << "Enter Student ID to record attendance: ";
            cin >> id;
            system.recordAttendance(id);
            break;
        case 5:
            cin.ignore();
            cout << "Enter Stop Location: ";
            getline(cin, location);
            system.addBusStop(location);
            break;
        case 6:
            cout << "Exiting system...\n";
            break;
        case 7:
            cout << "Enter Route ID: ";
            cin >> routeID;
            system.createRoute(routeID);
            break;
        default:
            cout << "Invalid choice!\n";
        }
    }while (choice !=6);
    return 0;
}

