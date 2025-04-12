#include <iostream>
using namespace std;

class Rectangle;
class AreaCalculator{
public:
	void display(Rectangle r);
};
class Rectangle{
	float len;
	float width;
public:
	Rectangle(float l,float w):len(l),width(w){}
	friend float calculateArea(Rectangle r);
	friend void AreaCalculator::display(Rectangle r);
};
float calculateArea(Rectangle r){
	float Area=r.len*r.width;
	return Area;
}
void AreaCalculator::display(Rectangle r){
	cout<<"Area is: "<<calculateArea(r)<<" m^2"<<endl;
}
int main(){
	Rectangle r(2.0,4.0);
	AreaCalculator a;
	a.display(r);
	return 0;
}
