#include <iostream>
using namespace std;

class Car{
private:
    string name;
    double cap;
    double rate;
    double distance;
	double fl;
public:
    Car(string n, double c, double r){
        name= n;
        cap =c;
        rate = r;
        distance = 0;
        fl=c;
        cout << "Car " << name << " is ready to drive" << endl;
    }
    ~Car() {
        cout << "Car " << name << " is removed from tracking" << endl;
    }
    void drive(double d){
        double fuel = (d /100) * rate;
        if (fuel <= fl) {
            distance += d;
            fl -= fuel;
            cout << "Drove " << d << " km, Remaining fuel: " << fl << " liters" << endl;
        } else {
            cout << "Insufficient fuel for this drive." << endl;
        }
    }

    void refuel(double liters){
        if (fl + liters <= cap){
            fl += liters;
            cout << "Refueled " << liters << " liters. Current fuel level: " << fl << " liters" << endl;
        } else{
            cout << "Fuel exceeds tank capacity." << endl;
        }
    }
    void displayCarStatus(){
        cout << "Car: " << name << "\nDistance Driven: " << distance << " km \nFuel Remaining: " << fl << " liters" << endl;
    }
};

int main(){
    Car car("Suzuki Wagon-R", 44, 10);
    car.drive(200);
    car.refuel(10);
    car.displayCarStatus();
    return 0;
}
