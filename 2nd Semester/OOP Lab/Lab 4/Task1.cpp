#include <iostream>
using namespace std;

class Clock{
    int hour;
    int min;

public:
    Clock(int h, int m) {
        hour = h;
        min = m;
        cout << "Digitial Clock created: " << hour << ":" << min << endl;
    }

    ~Clock() {
        cout << "Digital Clock Deleted!" << endl;
    }

    void display(){
        cout << "Current Time: " << hour << ":" << min << endl;
    }
};

int main(){
    Clock c(10, 15);
    c.display();
    return 0;
}