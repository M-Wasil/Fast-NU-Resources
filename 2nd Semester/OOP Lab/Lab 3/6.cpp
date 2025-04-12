#include <iostream>
#include <string>
using namespace std;

double calculateArea(double length,double width){
	return length*width;
}

int main(){
	double length,width;
	
	cout <<"Enter length: ";
	cin >> length;
	cout << "Enter width: ";
	cin >> width;
	double area=calculateArea(length,width);
	cout << "Area of rectangle: " << area << endl;
	
	return 0;
}
