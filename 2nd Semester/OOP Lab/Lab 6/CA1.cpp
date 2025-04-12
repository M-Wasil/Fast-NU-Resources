#include <iostream>
using namespace std;

class base{
	public:
		int i;
		int b;
	
	base(int i, int b){
		this->i = i;
		this->b = b;
	}	
};

class derived : public base{
	
	public:
		derived(int i, int b) : base(i,b) {} // derived class ka constructor always with initializer list
		
		void showData(){
			cout << "i = " <<i <<endl << "b = " << b;
		}
};

int main(){
	derived d1(4, 5);
	d1.showData();
}
