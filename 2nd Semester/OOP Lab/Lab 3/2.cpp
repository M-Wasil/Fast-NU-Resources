#include <iostream>
using namespace std;

class Shape{
	int height,width;
	public:
		void setHeight(int h){
			height=h;
		}
		void setWidth(int w){
			width=w;
		}
		int getHeight(){
			return height;
		}
		int getWidth(){
			return width;
		}
};

int main(){
	Shape s;
	s.setHeight(5);
	s.setWidth(2);
	
	cout << "The height is: " << s.getHeight() << endl;
	cout << "The width is: " << s.getWidth() << endl;
}
