#include <iostream>
using namespace std;

class Shape{
public:
	void draw(){
		cout<<"Drawing shape"<<endl;
	}
};

class Circle:public Shape{
public:
	void draw(){
		cout<<"Drawing circle"<<endl;
	}
};
int main(){
	Shape *s=new Circle;
	s->draw();
	delete s;
	return 0;
}
