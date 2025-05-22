#include<iostream>
#include<fstream>
#include<string>
#include<exception>
using namespace std;

class InputHandler{
public:
    static int getInt(const string& prompt){
        int val;
        cout<<prompt;
        while(!(cin>>val)){
            cin.clear();
            cin.ignore(1000,'\n');
            cout<<"Invalid input! "<<prompt;
        }
        cin.ignore(1000,'\n');
        return val;
    }

    static string getString(const string& prompt){
        string s;
        cout<<prompt;
        getline(cin,s);
        while(s.empty()){
            cout<<"Input cannot be empty! "<<prompt;
            getline(cin,s);
        }
        return s;
    }
};

class PaymentException:public exception{
public:
    const char* what()const noexcept override{
        return "Payment not completed!";
    }
};
class SeatException:public exception{
public:
    const char* what()const noexcept override{
        return "Seat unavailable!";
    }
};
class RoleException:public exception{
public:
    const char* what()const noexcept override{
        return "Seat role violation!";
    }
};
class EntityException:public exception{
public:
    const char* what()const noexcept override{
        return "Entity not found!";
    }
};
class TransporterException:public exception{
public:
    const char* what()const noexcept override{
        return "Only Nadeem/Zulfiqar transporters allowed!";
    }
};

template<typename T>
class GenericListManager{
    T** items;
    int capacity;
    int count;
public:
    GenericListManager():capacity(100),count(0){
        items = new T*[capacity];
    }
    ~GenericListManager(){
        for(int i=0;i<count;i++) delete items[i];
        delete[] items;
    }
    void add(T* item){
        if(count<capacity){
        	items[count++]=item;
		}
    }
    T* find(int id) const{
        for(int i=0;i<count;i++){
            if(items[i]->getId()==id){
            	return items[i];
			}
        }
        throw EntityException();
    }
    int getCount() const{
		return count;
	}
    T* getAt(int idx) const{
        if(idx<0||idx>=count){
        	return nullptr;
		}
        return items[idx];
    }
    void saveToFile(const string& filename){
        ofstream f(filename,ios::binary);
        for(int i=0;i<count;i++){
        	items[i]->saveToFile(f);
		}
    }
    void loadFromFile(const string& filename){
        ifstream f(filename,ios::binary);
        while(f){
            T* obj=T::loadFromFile(f);
            if(obj){
            	add(obj);
			}
        }
    }
};
class Student;
class Faculty;

class User{
protected:
    int id;
    string name,email,role;
    bool paymentStatus,monthlyBooking;
public:
    User(int i,const string& n,const string& e,const string& r):id(i),name(n),email(e),role(r),paymentStatus(false),monthlyBooking(false){}
    virtual void pay()=0;
    bool isEligible() const{
		return paymentStatus&&!monthlyBooking;
	}
    int getId() const{
		return id;
	}
    string getRole() const{
		return role;
	}
    void markBooked(){
		monthlyBooking=true;
	}
    void resetMonthlyBooking(){
		monthlyBooking=false;
	}
    virtual void saveToFile(ofstream& f) const{
        f.write((const char*)&id,sizeof(id));
        size_t len=name.size();
        f.write((const char*)&len,sizeof(len));
        f.write(name.c_str(),len);
        len=email.size();
        f.write((const char*)&len,sizeof(len));
        f.write(email.c_str(),len);
        len=role.size();
        f.write((const char*)&len,sizeof(len));
        f.write(role.c_str(),len);
        f.write((const char*)&paymentStatus,sizeof(paymentStatus));
        f.write((const char*)&monthlyBooking,sizeof(monthlyBooking));
    }

    void setPaymentStatus(bool p){
		paymentStatus=p;
	}
    void setMonthlyBooking(bool m){
		monthlyBooking=m;
	}
    static User* loadFromFile(ifstream& f);
    virtual ~User(){}
};

class Student:public User{
public:
    Student(int i,const string& n,const string& e):User(i,n,e,"student"){}
    void pay() override{
        if(!paymentStatus){
            paymentStatus=true;
            cout<<"Student "<<name<<" paid\n";
        }
    }
};
class Faculty:public User{
public:
    Faculty(int i,const string& n,const string& e):User(i,n,e,"faculty"){}
    void pay() override{
        if(!paymentStatus){
            paymentStatus=true;
            cout<<"Faculty "<<name<<" paid\n";
        }
    }
};
User* User::loadFromFile(ifstream& f){
    int i;
    size_t len;
    string n,e,r;
    bool p,m;
    if(!f.read(reinterpret_cast<char*>(&i),sizeof(i))){
    	return nullptr;
	}

    f.read((char*)&len,sizeof(len));
    n.resize(len);
    f.read(&n[0],len);
    f.read((char*)&len,sizeof(len));
    e.resize(len);
    f.read(&e[0],len);
    f.read((char*)&len,sizeof(len));
    r.resize(len);
    f.read(&r[0],len);
    f.read((char*)&p,sizeof(p));
    f.read((char*)&m,sizeof(m));

    User* u;
	if(r=="student"){
    	u=static_cast<User*>(new Student(i, n, e));
	}else{
    	u=static_cast<User*>(new Faculty(i, n, e));
	}
    u->setPaymentStatus(p);
    u->setMonthlyBooking(m);
    return u;
}
class Driver{
    int id;
    string name,license;
    bool assigned;
public:
    Driver(int i,const string& n,const string& l):id(i),name(n),license(l),assigned(false){}
    int getId() const{
		return id;
	}
    void assign(){
		assigned=true;
	}
    void unassign(){
		assigned=false;
	}
    void saveToFile(ofstream& f) const{
        f.write((const char*)&id,sizeof(id));
        size_t len=name.size();
        f.write((const char*)&len,sizeof(len));
        f.write(name.c_str(),len);
        len=license.size();
        f.write((const char*)&len,sizeof(len));
        f.write(license.c_str(),len);
        f.write((const char*)&assigned,sizeof(assigned));
    }

    static Driver* loadFromFile(ifstream& f){
        int i; string n,l; bool a;
        size_t len;
        if(!f.read((char*)&i,sizeof(i))){
        	return nullptr;
		}
        f.read((char*)&len,sizeof(len));
        n.resize(len);
        f.read(&n[0],len);
        f.read((char*)&len,sizeof(len));
        l.resize(len);
        f.read(&l[0],len);
        f.read((char*)&a,sizeof(a));

        Driver* d=new Driver(i,n,l);
        if(a){
        	d->assign();
		}
        return d;
    }
    string getName() const{
		return name;
	}
    bool isAssigned() const{
		return assigned;
	}
};

class Route{
    int id;
    string start,end;
    double dist;
public:
    Route(int i,const string& s,const string& e,double d):id(i),start(s),end(e),dist(d){}
    int getId() const{
		return id;
	}
    void saveToFile(ofstream& f) const{
        f.write((const char*)&id,sizeof(id));
        size_t len=start.size();
        f.write((const char*)&len,sizeof(len));
        f.write(start.c_str(),len);
        len=end.size();
        f.write((const char*)&len,sizeof(len));
        f.write(end.c_str(),len);
        f.write((const char*)&dist,sizeof(dist));
    }
    static Route* loadFromFile(ifstream& f){
        int i; string s,e; double d;
        size_t len;
        if(!f.read((char*)&i,sizeof(i))){
        	return nullptr;
		}
        f.read((char*)&len,sizeof(len));
        s.resize(len);
        f.read(&s[0],len);
        f.read((char*)&len,sizeof(len));
        e.resize(len);
        f.read(&e[0],len);
        f.read((char*)&d,sizeof(d));

        return new Route(i,s,e,d);
    }
    bool isLongRoute(double t=20.0) const{
		return dist>t;
	}
    string getStart() const{
		return start;
	}
    string getEnd() const{
		return end;
	}
    int getDistance() const{
		return dist;
	}
};
class Seat{
    int number;
    string role;
    bool booked;
public:
    Seat(int n,const string& r):number(n),role(r),booked(false){}
    int getNumber() const{
		return number;
	}
    string getRole() const{
		return role;
	}
    bool isAvailable() const{
		return !booked;
	}
    void book(){
        if(booked) throw SeatException();
        booked=true;
    }
};
class Vehicle{
protected:
    int id;
    string transporter;
    bool ac;
    int cap;
    Driver* drv;
    Route* rte;
    Seat** seats;
public:
    Vehicle(int i,const string& t,bool a,Driver* d,Route* r,int c):id(i),transporter(t),ac(a),cap(c),drv(d),rte(r){
        if(t!="Nadeem"&&t!="Zulfiqar"){
        	throw TransporterException();
		}
        seats=new Seat*[cap];
        for(int k=0;k<cap;k++){
            if(k%2==0){
                seats[k]=new Seat(k+1,"student");
            }else{
                seats[k]=new Seat(k+1,"faculty");
            }
        }
        drv->assign();
    }
    virtual ~Vehicle(){
        for(int k=0;k<cap;k++){
        	delete seats[k];
		}
        delete[] seats;
        drv->unassign();
    }
    int getId() const{
		return id;
	}
    int getCapacity() const{
		return cap;
	}
    Seat* getSeat(int idx) const{
        if(idx<0||idx>=cap){
        	return nullptr;
		}
        return seats[idx];
    }
    Route* getRoute() const{
		return rte;
	}
    int calculateFare(const User* u) const{
        int f=(u->getRole()=="student"?39000:35000)+(ac?2000:0)+(rte->isLongRoute()?1000:0);
        return f;
    }
    Seat* findAvailableSeat(const string& role) const{
        for(int k=0;k<cap;k++)
            if(seats[k]->isAvailable()&&seats[k]->getRole()==role){
            	return seats[k];
			}
        return nullptr;
    }
    virtual string getType() const=0;
    void saveToFile(ofstream& f) const{
        f.write(reinterpret_cast<const char*>(&id),sizeof(id));
        size_t len=transporter.size();
        f.write(reinterpret_cast<const char*>(&len),sizeof(len));
        f.write(transporter.c_str(),len);
        f.write(reinterpret_cast<const char*>(&ac),sizeof(ac));
        f.write(reinterpret_cast<const char*>(&cap),sizeof(cap));
        int drvId=drv->getId();
        f.write(reinterpret_cast<const char*>(&drvId),sizeof(drvId));
        int rteId=rte->getId();
        f.write(reinterpret_cast<const char*>(&rteId),sizeof(rteId));
    }
    static Vehicle* loadFromFile(ifstream& f,GenericListManager<Driver>& dm,GenericListManager<Route>& rm);
};

class Bus:public Vehicle{
public:
    Bus(int i,const string& t,bool a,Driver* d,Route* r):Vehicle(i,t,a,d,r,52){}
    string getType() const override{
		return "Bus";
	}
};

class Coaster:public Vehicle{
public:
    Coaster(int i,const string& t,bool a,Driver* d,Route* r):Vehicle(i,t,a,d,r,32){}
    string getType() const override{
		return "Coaster";
	}
};

Vehicle* Vehicle::loadFromFile(ifstream& f,GenericListManager<Driver>& dm,GenericListManager<Route>& rm){
    int i,cap,did,rid;
    bool a;
    string t;
    if(!f.read(reinterpret_cast<char*>(&i),sizeof(i))){
    	return nullptr;
	}
    size_t len;
    f.read((char*)&len,sizeof(len));
    t.resize(len);
    f.read(&t[0],len);
    f.read((char*)&a,sizeof(a));
    f.read((char*)&cap,sizeof(cap));
    f.read((char*)&did,sizeof(did));
    f.read((char*)&rid,sizeof(rid));
    Driver* d=dm.find(did);
    Route* r=rm.find(rid);
	if(cap==52){
    	return (Vehicle*)new Bus(i,t,a,d,r);
	}else{
	    return (Vehicle*)new Coaster(i,t,a,d,r);
	}
}
class Booking{
    int id; User* u; Vehicle* v; Seat* s; int fare;
public:
    Booking(int i,User* uu,Vehicle* vv,Seat* ss):id(i),u(uu),v(vv),s(ss),fare(vv->calculateFare(uu)){}
    int getId() const{return id;}
    int getFare() const{return fare;}
    void saveToFile(ofstream& f) const{
        f.write((const char*)&id,sizeof(id));
        int uId=u->getId();
        f.write((const char*)&uId,sizeof(uId));
        int vId=v->getId();
        f.write((const char*)&vId,sizeof(vId));
        int sNo=s->getNumber();
        f.write((const char*)&sNo,sizeof(sNo));
        f.write((const char*)&fare,sizeof(fare));
    }
    static Booking* loadFromFile(ifstream& f,GenericListManager<User>& um,GenericListManager<Vehicle>& vm){
        int i,uId,vId,sNo,fare;
        if(!f.read(reinterpret_cast<char*>(&i),sizeof(i))){
        	return nullptr;
		}
        if(!f.read(reinterpret_cast<char*>(&uId),sizeof(uId))){
        	return nullptr;
		}
        if(!f.read(reinterpret_cast<char*>(&vId),sizeof(vId))){
        	return nullptr;
		}
        if(!f.read(reinterpret_cast<char*>(&sNo),sizeof(sNo))){
        	return nullptr;
		}
        if(!f.read(reinterpret_cast<char*>(&fare),sizeof(fare))){
        	return nullptr;
		}

        try{
            User* u=um.find(uId);
            Vehicle* v=vm.find(vId);
            Seat* s=v->getSeat(sNo-1);
            s->book();
            u->markBooked();
            return new Booking(i,u,v,s);
        }catch(...){
            return nullptr;
        }
    }
};
class TransportSystem{
    GenericListManager<User> users;
    GenericListManager<Driver> drivers;
    GenericListManager<Route> routes;
    GenericListManager<Vehicle> vehicles;
    GenericListManager<Booking> bookings;
    int nextBookingId=1;

public:
    void loadData(){
        users.loadFromFile("users.bin");
        drivers.loadFromFile("drivers.bin");
        routes.loadFromFile("routes.bin");
        ifstream vf("vehicles.bin",ios::binary);
        while(vf){
            Vehicle* v=Vehicle::loadFromFile(vf,drivers,routes);
            if(v) vehicles.add(v);
        }
        ifstream bf("bookings.bin",ios::binary);
        while(bf){
            Booking* b=Booking::loadFromFile(bf,users,vehicles);
            if(b) bookings.add(b);
        }
        ifstream idf("booking_id.bin",ios::binary);
        if(idf) idf.read((char*)&nextBookingId,sizeof(nextBookingId));
    }
    void saveData(){
        users.saveToFile("users.bin");
        drivers.saveToFile("drivers.bin");
        routes.saveToFile("routes.bin");
        vehicles.saveToFile("vehicles.bin");
        bookings.saveToFile("bookings.bin");
        ofstream idf("booking_id.bin",ios::binary);
        idf.write((const char*)&nextBookingId,sizeof(nextBookingId));
        cout<<"Data saved\n";
    }
    void bookSeat(int uid,int vid){
        try{
            User* u=users.find(uid);
            Vehicle* v=vehicles.find(vid);
            if(!u->isEligible()){
            	throw PaymentException();
			}
            Seat* s=v->findAvailableSeat(u->getRole());
            if(!s){
            	throw SeatException();
			}
            if(s->getRole()!=u->getRole()){
            	throw RoleException();
			}
            s->book(); u->markBooked();
            bookings.add(new Booking(nextBookingId++,u,v,s));
            cout<<"Booked! Fare="<<v->calculateFare(u)<<"\n";
        }
        catch(exception& e){cerr<<"Booking error: "<<e.what()<<"\n";}
    }
    void resetMonthly(){
        for(int i=0;i<users.getCount();i++)
            users.getAt(i)->resetMonthlyBooking();
        cout<<"Monthly reset\n";
    }
    void registerUser(bool isFaculty){
        int id=InputHandler::getInt("Enter user ID: ");
        string name=InputHandler::getString("Enter name: ");
        string email=InputHandler::getString("Enter email: ");
        User* u;
		if(isFaculty){
    		u = static_cast<User*>(new Faculty(id,name,email));
		}else{
    		u = static_cast<User*>(new Student(id,name,email));
		}
        users.add(u);
        cout<<"User registered!\n";
    }
    void addDriver(){
        int id=InputHandler::getInt("Enter driver ID: ");
        string name=InputHandler::getString("Enter driver name: ");
        string lic=InputHandler::getString("Enter license no.: ");
        drivers.add(new Driver(id,name,lic));
        cout<<"Driver added!\n";
    }
    void addRoute(){
        int id=InputHandler::getInt("Enter route ID: ");
        string startLoc=InputHandler::getString("Enter start location: ");
        string endLoc=InputHandler::getString("Enter end location: ");
        int dist=InputHandler::getInt("Enter distance (km): ");
        routes.add(new Route(id,startLoc,endLoc,dist));
        cout<<"Route added!\n";
    }
    void addVehicle(){
        if(drivers.getCount()==0||routes.getCount()==0){
            cerr<<"Please add drivers and routes first!\n";
            return;
        }
        int id=InputHandler::getInt("Enter vehicle ID: ");
        string trName=InputHandler::getString("Enter transporter (Nadeem/Zulfiqar): ");
        int hasAC=InputHandler::getInt("AC? (1=yes, 0=no): ");
        int type=InputHandler::getInt("Type? (52=Bus, 32=Coaster): ");
        cout<<"\nAvailable drivers:\n";
        
        for(int i=0;i<drivers.getCount();i++){
            Driver* d=drivers.getAt(i);
            cout<<"ID: "<<d->getId()<<" - "<<d->getName()<<"\n";
        }
        int drvId=InputHandler::getInt("Enter driver ID to assign: ");
        int rteId=InputHandler::getInt("Enter route ID to assign: ");
        Driver* d=drivers.find(drvId);
        Route* r=routes.find(rteId);
        if(d->isAssigned()){
            cerr<<"Error: Driver is already assigned to another vehicle!\n";
            return;
        }

        try{
            Vehicle* v;
			if(type == 52){
    			v=static_cast<Vehicle*>(new Bus(id,trName,hasAC,d,r));
			}else{
    			v = static_cast<Vehicle*>(new Coaster(id,trName,hasAC,d,r));
			}
            vehicles.add(v);
            cout<<"Vehicle added!\n";
        }catch(exception& e){
            cerr<<"Error: "<<e.what()<<"\n";
        }
    }
    void processPayment(){
        int uid=InputHandler::getInt("Enter user ID: ");
        try{
            users.find(uid)->pay();
            cout<<"Payment processed!\n";
        }catch(...){
            cerr<<"User not found!\n";
        }
    }
    void showAllBookings(){
        cout<<"\n--- All Bookings ---\n";
        for(int i=0;i<bookings.getCount();i++){
            auto* b=bookings.getAt(i);
            cout<<"Booking#"<<b->getId()
               <<" | Fare: Rs."<<b->getFare()<<"\n";
        }
    }
    void showMenu(){
        while(true){
            cout<<"\n===== TRANSPORT MENU =====\n"
                <<"1.Register Student  2.Register Faculty\n"
                <<"3.Add Driver        4.Add Route\n"
                <<"5.Add Vehicle       6.Process Payment\n"
                <<"7.Book Seat         8.Show Bookings\n"
                <<"9.Reset Monthly     10.Save Data\n"
                <<"11.Exit\n";

            int choice=InputHandler::getInt("Choice: ");
            switch(choice){
                case 1: registerUser(false); break;
                case 2: registerUser(true); break;
                case 3: addDriver(); break;
                case 4: addRoute(); break;
                case 5: addVehicle(); break;
                case 6: processPayment(); break;
                case 7:{
                    int u=InputHandler::getInt("User ID: ");
                    int v=InputHandler::getInt("Vehicle ID: ");
                    bookSeat(u,v);
                    break;
                }
                case 8: showAllBookings(); break;
                case 9: resetMonthly(); break;
                case 10: saveData(); break;
                case 11:{
                    char c=InputHandler::getString("Save before exit? (y/n): ")[0];
                    if(c=='y'||c=='Y'){
                        saveData();
                    }
                    cout<<"Goodbye!\n";
                    return;
                }
                default:
                    cout<<"Invalid choice\n";
            }
        }
    }
};

int main(){
    TransportSystem sys;
    sys.loadData();
    sys.showMenu();
    return 0;
}
