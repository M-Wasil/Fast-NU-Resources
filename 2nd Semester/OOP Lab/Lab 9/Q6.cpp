#include <iostream>
using namespace std;

class Shape{
	string name;
public:
	Shape(string n):name(n){}
	virtual void area()=0;
};
class Triangle:public Shape{
public:
	Triangle(string n):Shape(n){}
	void area(){
		int l,h;
		cout<<"Enter base and height: ";
		cin>>l>>h;
		cout<<"Area of Triangle: "<<0.5*l*h<<endl;
	}
};
class Circle:public Shape{
public:
	Circle(string n):Shape(n){}
	void area(){
		int r;
		cout<<"Enter radius: ";
		cin>>r;
		cout<<"Area of Circle: "<<3.1416*r*r<<endl;
	}
};
class Rectangle:public Shape{
public:
	Rectangle(string n):Shape(n){}
	void area(){
		int l,h;
		cout<<"Enter length and breadth: ";
		cin>>l>>h;
		cout<<"Area of Rectangle: "<<l*h<<endl;
	}
};
int main(){
	Shape* s[5];
	Circle c1("Circle 1"); Rectangle r1("Rectangle 1"); Triangle t1("Triangle 1");Circle c2("Circle 2"); Rectangle r2("Rectangle 2");
	s[0]=&c1;
	s[1]=&r1;
	s[2]=&t1;
	s[3]=&r2;
	s[4]=&c2;
	for (int i=0;i<5;i++){
		s[i]->area();
	}
	return 0;
}
