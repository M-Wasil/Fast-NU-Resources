#include<iostream>
using namespace std;

class deep{
	
	public:
	    int* data;
	    deep() {
    		data = new int(0);
		}

	    deep(int value){
	    	data  = new int(value);
		}
		
		deep(deep& obj){
			data = new int(*obj.data);
		}
		void display(){
			cout << "Data: " << *data << " Address: " << data <<endl;
		
	}
	~deep(){
		cout << "destructer called object destroyed"<<endl;
	}
};
	

int main(){
	
	deep obj1(10);
	deep obj2(obj1); //copy
	obj1.display();
	obj2.display();
	
}