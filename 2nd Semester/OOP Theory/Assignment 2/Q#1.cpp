#include <iostream>
#include <string>
using namespace std;

class BusStop{
private:
    string location;
public:
    BusStop():BusStop(""){}
    BusStop(string loc):location(loc){}
    
    string getLocation() const{
        return location;
    }
    
    void displayStop() const{
        cout<<"Bus Stop: "<<location<<"\n";
    }
    
    bool operator==(const BusStop& other) const{
        return location==other.location;
    }
};

class Route{
private:
    string routeID;
    BusStop stops[50];
    int totalStops;
public:
    Route():Route(""){}
    Route(string id):routeID(id),totalStops(0){}
    
    void addStop(const BusStop &stop){
        if(totalStops<50)
            stops[totalStops++]=stop;
    }
    
    BusStop getFirstStop() const{
        if(totalStops>0)
            return stops[0];
        return BusStop();
    }
    
    BusStop getLastStop() const{
        if(totalStops>0)
            return stops[totalStops-1];
        return BusStop();
    }
    
    string getRouteID() const{
        return routeID;
    }
    
    void displayRoute() const{
        cout<<"Route "<<routeID<<" with "<<totalStops<<" stops:\n";
        for(int i=0;i<totalStops;i++){
            stops[i].displayStop();
        }
    }
    
    bool operator==(const Route& other) const{
        if(routeID!=other.routeID||totalStops!=other.totalStops)
            return false;
        for(int i=0;i<totalStops;i++){
            if(!(stops[i]==other.stops[i]))
                return false;
        }
        return true;
    }
};

class User{
protected:
    string userID;
    string name;
    bool cardActive;
    double balance;
    BusStop pickup,dropoff;
    string assignedRoute;
public:
    User(string id):User(id,"Anonymous"){}
    User(string id,string n):userID(id),name(n),cardActive(false),balance(0),pickup(""),dropoff(""),assignedRoute(""){}
    
    virtual ~User(){}
    
    void assignStops(BusStop p,BusStop d){
        pickup=p;
        dropoff=d;
    }
    void assignStops(string p,string d,string route){
        pickup=BusStop(p);
        dropoff=BusStop(d);
        assignedRoute=route;
    }
    
    virtual void payFees(double amount)=0;
    
    void tapCard() const{
        if(cardActive)
            cout<<name<<" checked in at "<<pickup.getLocation()<<" on route "<<assignedRoute<<". Dropoff: "<<dropoff.getLocation()<<"\n";
        else
            cout<<"Card inactive or stops not assigned for "<<name<<"!\n";
    }
    
    void showUser() const{
        cout<<"ID: "<<userID<<" | Name: "<<name<<" | Balance: $"<<balance<<" | Card: "<<(cardActive?"Active":"Inactive")<<"\n";
    }
    
    string getID() const{
        return userID;
    }
    
    double getBalance() const{
        return balance;
    }
    
    bool operator==(const User& other) const{
        return userID==other.userID;
    }
    
    void updateBalance(double amt){
        balance+=amt;
    }
    
    void updateCardStatus(double threshold){
        cardActive=(balance>=threshold);
    }
};

class Student:public User{
public:
    Student(string id,string name):User(id,name){}
    
    void payFees(double amount) override{
        updateBalance(amount);
        updateCardStatus(5000);
        cout<<"Student "<<name<<" paid fees. New balance: $"<<balance<<"\n";
    }
};

class Teacher:public User{
public:
    Teacher(string id,string name):User(id,name){}
    
    void payFees(double amount) override{
        updateBalance(amount);
        updateCardStatus(1000);
        cout<<"Teacher "<<name<<" paid fees. New balance: $"<<balance<<"\n";
    }
};

class Staff:public User{
public:
    Staff(string id,string name):User(id,name){}
    
    void payFees(double amount) override{
        updateBalance(amount);
        updateCardStatus(800);
        cout<<"Staff "<<name<<" paid fees. New balance: $"<<balance<<"\n";
    }
};

class TransportSystem{
private:
    static const int MAX_USERS=200;
    static const int MAX_ROUTES=20;
    
    User* users[MAX_USERS];
    int totalUsers;
    
    Route routes[MAX_ROUTES];
    int totalRoutes;
public:
    TransportSystem():totalUsers(0),totalRoutes(0){}
    
    ~TransportSystem(){
        for(int i=0;i<totalUsers;i++){
            delete users[i];
        }
    }
    
    void registerUser(int userType,string id,string name){
        if(totalUsers>=MAX_USERS){
            cout<<"Maximum users reached!\n";
            return;
        }
        switch(userType){
            case 1: 
                users[totalUsers++]=new Student(id,name);
                break;
            case 2: 
                users[totalUsers++]=new Teacher(id,name);
                break;
            case 3: 
                users[totalUsers++]=new Staff(id,name);
                break;
            default:
                cout<<"Invalid user type!\n";
                return;
        }
        cout<<"User registered: "<<id<<"\n";
    }
    
    User* findUser(string id){
        for(int i=0;i<totalUsers;i++){
            if(users[i]->getID()==id)
                return users[i];
        }
        return nullptr;
    }
    
    void addRoute(const Route &route){
        if(totalRoutes<MAX_ROUTES){
            routes[totalRoutes++]=route;
            cout<<"Route "<<route.getRouteID()<<" added.\n";
        }else{
            cout<<"Maximum routes reached!\n";
        }
    }
    
    void assignRoute(string userID,const Route &route){
        User* user=findUser(userID);
        if(user){
            user->assignStops(route.getFirstStop(),route.getLastStop());
            cout<<"Route "<<route.getRouteID()<<" assigned to user "<<userID<<".\n";
        }else{
            cout<<"User "<<userID<<" not found!\n";
        }
    }
    
    void assignRoute(string userID,string routeID,string pickup,string dropoff){
        User* user=findUser(userID);
        if(user){
            user->assignStops(pickup,dropoff,routeID);
            cout<<"Route "<<routeID<<" assigned to user "<<userID<<".\n";
        }else{
            cout<<"User "<<userID<<" not found!\n";
        }
    }
    
    void processPayment(string userID,double amount){
        User* user=findUser(userID);
        if(user){
            user->payFees(amount);
        }else{
            cout<<"User "<<userID<<" not found!\n";
        }
    }
    
    void markAttendance(string userID){
        User* user=findUser(userID);
        if(user)
            user->tapCard();
        else
            cout<<"User "<<userID<<" not found!\n";
    }
    
    void displayUsers() const{
        for(int i=0;i<totalUsers;i++){
            users[i]->showUser();
        }
    }
    
    void displayRoutes() const{
        for(int i=0;i<totalRoutes;i++){
            routes[i].displayRoute();
        }
    }
};

int main(){
    TransportSystem system;
    
    Route r1("R1");
    r1.addStop(BusStop("FAST NUCES"));
    r1.addStop(BusStop("Gulshan"));
    r1.addStop(BusStop("Jauhar"));
    
    Route r2("R2");
    r2.addStop(BusStop("Nazimabad"));
    r2.addStop(BusStop("Clifton"));
    
    system.addRoute(r1);
    system.addRoute(r2);
    
    int choice;
    do{
        cout<<"\nTransport System Menu:\n"
            <<"1. Register Student\n"
            <<"2. Register Teacher\n"
            <<"3. Register Staff\n"
            <<"4. Assign Route (using Route object)\n"
            <<"5. Assign Route (using strings)\n"
            <<"6. Pay Fees\n"
            <<"7. Mark Attendance\n"
            <<"8. Display Users\n"
            <<"9. Display Routes\n"
            <<"10. Exit\n"
            <<"Enter your choice: ";
        cin>>choice;
        cin.ignore();
        
        string id,name,routeID,pickup,dropoff;
        double amount;
        
        switch(choice){
            case 1:
                cout<<"Enter Student ID: ";
                cin>>id;
                cin.ignore();
                cout<<"Enter Student Name: ";
                getline(cin,name);
                system.registerUser(1,id,name);
                break;
            case 2:
                cout<<"Enter Teacher ID: ";
                cin>>id;
                cin.ignore();
                cout<<"Enter Teacher Name: ";
                getline(cin,name);
                system.registerUser(2,id,name);
                break;
            case 3:
                cout<<"Enter Staff ID: ";
                cin>>id;
                cin.ignore();
                cout<<"Enter Staff Name: ";
                getline(cin,name);
                system.registerUser(3,id,name);
                break;
            case 4:
                cout<<"Enter User ID: ";
                cin>>id;
                system.assignRoute(id,r1);
                break;
            case 5:
                cout<<"Enter User ID: ";
                cin>>id;
                cout<<"Enter Route ID: ";
                cin>>routeID;
                cin.ignore();
                cout<<"Enter Pickup Stop: ";
                getline(cin,pickup);
                cout<<"Enter Dropoff Stop: ";
                getline(cin,dropoff);
                system.assignRoute(id,routeID,pickup,dropoff);
                break;
            case 6:
                cout<<"Enter User ID: ";
                cin>>id;
                cout<<"Enter Amount: ";
                cin>>amount;
                system.processPayment(id,amount);
                break;
            case 7:
                cout<<"Enter User ID: ";
                cin>>id;
                system.markAttendance(id);
                break;
            case 8:
                system.displayUsers();
                break;
            case 9:
                system.displayRoutes();
                break;
            case 10:
                cout<<"Exiting...\n";
                break;
            default:
                cout<<"Invalid choice!\n";
        }
    }while(choice!=10);
    
    return 0;
}
