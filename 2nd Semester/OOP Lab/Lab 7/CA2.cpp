#include <iostream>
using namespace std;

int mul(int,int);
float mul(float,int);


int mul(int a,int b){
	return a*b;
}
float mul(double x, int y){
	return x*y;
}
int main(){
	int r1=mul(7,9);
	float r2=mul(0.2,5);
	cout<<"r1 is: "<<r1<<endl;
	cout<<"r2 is: "<<r2<<endl;
	return 0;
}
