#include<iostream>
using namespace std;
class Rectangle{
	private:
		int length;
		int width;
		
	public:
		Rectangle(int l , int w) : length (l), width(w) {
			cout << "Rectangle object created with " << length << " and width " << width << endl;
		}
		int area(){
			return length* width;
		}
		~Rectangle(){
			cout << "Object Destroyed";
		}
};
int main(){
	Rectangle rect(4,8);
	cout<<"Area of rectangle: " << rect.area() << endl;
}