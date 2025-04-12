#include <iostream>
using namespace std;

class Shallow{
	public:
		int* data;
		Shallow(int value){
			data=new int(value);
		}
		Shallow(Shallow&obj){
			data=obj.data;
		}
		void display(){
			cout << "Data: " << *data << ", Address: " << data <<  endl;
		}
};

int main(){
	Shallow obj1(10);
	Shallow obj2(obj1);
	
	obj1.display();
	obj2.display();
}