#include <iostream>
using namespace std;

int main(){
	int *ptr=new int;
	*ptr=7;
	int *ptr2=new int(5);
	cout << ptr;
 delete ptr;
 delete[]ptr2;
}
