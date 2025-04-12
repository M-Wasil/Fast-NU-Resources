#include <iostream>
using namespace std;

int main(){
	int* ptr =new int;
	*ptr=10;
	
	int* arr=new int[5];
	for (int i=0;i<5;i++){
		arr[i]=i*2;
	}
	cout << "Value of *ptr: " << *ptr << endl;
	cout << "Array values: ";
	for (int i=0;i<5;i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	
	delete ptr;
	delete[] arr;
}
