#include <iostream>
#include <string>
using namespace std;

class ToyotaCars{
	string model;
	int year;
	string color;
	public:
		ToyotaCars(string model, int year, string color){
			this->model = model;
			this->year = year;
			this->color = color;
		}
		void displayinfo(){
			cout << "Model: " << model << endl;
			cout << "Year: " << year << endl;
			cout << "Color: " << color << endl;
		}
};

int main(){
	ToyotaCars c1("Corrola",2023,"Black");
	c1.displayinfo();
	return 0;
}
