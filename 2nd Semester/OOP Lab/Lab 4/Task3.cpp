#include <iostream>
using namespace std;

class Temperature{
private:
    double celsius;
public:
    Temperature(double tempC){
        celsius=tempC;
        cout << "Temperature object: " << celsius << "C" << endl;
    }
    ~Temperature(){
        cout << "Temperature object deleted" << endl;
    }
    double far(){
        return (celsius * 9 / 5) + 32;
    }
    double kel(){
        return celsius + 273.15;
    }
    void display(){
        cout << "Celsius: " << celsius << " C \nFahrenheit: " << far() << " F \nKelvin: " << kel() << " K" << endl;
    }
};

int main(){
    Temperature temp(32);
    temp.display();
    return 0;
}