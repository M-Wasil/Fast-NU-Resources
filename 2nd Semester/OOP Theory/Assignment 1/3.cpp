#include <iostream>
using namespace std;

class Vehicle;
class User{
	string name;
	int age;
	string license;
	string conInfo;
	int id;
	Vehicle* v;
public:
	User() : name(""), age(0), license(""), conInfo(""), id(0) {}
	User(string n,int a,string l,string c,int i):name(n),age(a),license(l),conInfo(c),id(i) {}
	void registerUser(){
		cout<<"Enter your name: ";
    	getline(cin,name);
		cout<<"Enter your age: ";
		cin>>age;
		cout<<"Enter your ID: ";
		cin>>id;
		cin.ignore();
		cout<<"Enter your license type: ";
		getline(cin,license);
		cout<<"Enter your contact info: ";
		getline(cin,conInfo);
	}
	void updateName(string n){
		name=n;
	}
	void updateAge(int a){
		age=a;
	}void updateLic(string l){
		license=l;
	}
	void updateInfo(string c){
		conInfo=c;
	}
	void updateId(int i){
		id=i;
	}
	int getId() const{
		return id; 
	}
    string getName() const{ 
		return name; 
	}
    int getAge() const{ 
		return age; 
	}
    string getContact() const{
		return conInfo; 
	}
    string getLicense() const{ 
		return license; 
	}
};
class Vehicle{
public:
	string model;
	float ppd;
	string eligibility;
	void display(){
		cout << "Model: " <<model <<endl;
        cout << "Rent Price: $" <<ppd << " per day" <<endl;
        cout << "Eligibility: " << eligibility <<endl<<endl;
	}
    void check(User &u){
    	string userLicense =u.getLicense();
        string v=eligibility;
        if (userLicense == v){
            cout <<"The per day rent of car model " << model<< " is "<<ppd<<endl;
        } else{
            cout <<"You are not eligible for car model "<< model <<endl;
        }
	}
};
class RentalSystem{
	Vehicle *v;
    int num;
public:
    RentalSystem(){
        cout<<"Enter number of vehicles: ";
        cin>>num;
        cin.ignore();
        v=new Vehicle[num];
    }
    void setUp(){
    	cin.ignore();
        for (int i =0;i <num;i++){
            cout << "Enter model: ";
            getline(cin,v[i].model);
            cout << "Enter rental price: ";
            cin >> v[i].ppd;
            cin.ignore();
            cout << "Enter eligibility: ";
            getline(cin, v[i].eligibility);
        }
	}
    void rent(User &u){
    	int choice;
        cout << "Vehicle list: " << endl;
        for (int i =0; i<num;i++){
            cout <<i+1 << ": " <<v[i].model <<endl;
        }
        cout <<"Enter the car number to rent: ";
        cin >> choice;
        if (choice>0 &&choice <=num){
            v[choice-1].check(u);
        } else{
            cout << "Invalid selection!\n";
        }
    }
    void updateInfo(){
    	string name;
        cout << "Available Vehicles: " <<endl;
        for (int i =0;i <num;i++){
            cout <<i+1 << ": " <<v[i].model <<endl;
        }
        cout << "Enter name of vehicle to modify details: ";
        cin.ignore();
        getline(cin, name);
        for (int i =0;i <num;i++){
            if (name == v[i].model){
                cout <<"Enter rental price: ";
                cin >> v[i].ppd;
                cin.ignore();
                cout <<"Enter Eligibility criteria: ";
                getline(cin,v[i].eligibility);
                return;
            }
        }
        cout << "Vehicle not found!\n";
	}
        
    ~RentalSystem(){
        delete[] v;
    }
};
int main(){
    int choice;
    RentalSystem r;
    User u("", 0, "", "", 0);
    u.registerUser();
	cout<<"Select an option from below:"<<endl;
    cout << "1: Initialize Vehicles\n";
    cout << "2: Modify Vehicle Details\n";
    cout << "3: Update User Information\n";
    cout << "4: Rent a Car\n";
    cout << "5: Exit\n";
    do {
        cout << "Enter choice: ";
        cin >>choice;
        switch (choice){
            case 1:
                r.setUp();
                break;
            case 2:
                r.updateInfo();
                break;
            case 3:
            	cin.ignore();
                u.registerUser();
                break;
            case 4:
                r.rent(u);
                break;
        }
    } while (choice != 5);
    cout << "Exiting... Thank you for using the system!\n";
    return 0;
}

