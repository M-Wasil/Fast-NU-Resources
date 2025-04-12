#include <iostream>
using namespace std;

class Deep{
	public:
	int* data;
		Deep(int value){
			data=new int(value);
		}
		Deep(Deep&obj){
			data=new int(*obj.data);
		}
		void display(){
			cout << "Data: " << *data << ", Address: " << data <<  endl;
		}
};

int main(){
	Deep obj1(20);
	Deep obj2(obj1);
	
	obj1.display();
	obj2.display();
}