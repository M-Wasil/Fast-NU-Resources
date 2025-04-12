#include <iostream>
using namespace std;

class Room{
    string roomType;
public:
    Room(string type) : roomType(type) {}
    void displayRoom() const{
        cout << "Room Type: " << roomType << endl;
    }
};

class House{
private:
    string houseName;
    Room livingRoom;
    Room bedroom;
public:
    House(string name, string lrType, string brType)
        : houseName(name), livingRoom(lrType), bedroom(brType){}
    void displayHouse() const{
        cout << "House Name: " << houseName << endl;
        livingRoom.displayRoom();
        bedroom.displayRoom();
    }
};

int main(){
    House myHouse("Dream Villa", "Living Room", "Master Bedroom");
    myHouse.displayHouse();
    return 0;
}