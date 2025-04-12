#include <iostream>
using namespace std;

class Product{
	static int count;
public:
	Product(){
		count++;
	}
	static void display(){
		cout <<"Count is: " << count<<endl;
	}
};
int Product::count=0;

int main(){
	Product p1,p2,p3;
	Product::display();
	return 0;
}
