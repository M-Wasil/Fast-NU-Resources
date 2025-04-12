#include <iostream>

using namespace std;

class Rectangle{
	private:
		int width, height;
	
	public:
	
	Rectangle(double h,double w){
		height=h;
		width=w;
	}
	double calculateArea(){
		return height*width;
	}
};

int main(){
	double h,w;

	cout << "Enter Height: ";
	cin >> h;
	cout << "Enter Width: ";
	cin >> w;
	
	Rectangle rectangle(h,w);
	
	cout << "Area: " << rectangle.calculateArea();
}
