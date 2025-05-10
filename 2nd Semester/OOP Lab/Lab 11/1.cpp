#include <iostream>
using namespace std;

template <typename T>

void swapp(T &a,T &b){
	T temp;
	temp=a;
	a=b;
	b=temp;
}
int main(){
	int a=7,b=900;
	cout<<a<<" "<<b<<endl;
	swapp(a,b);
	cout<<a<<" "<<b<<endl;
	float x=3.69,y=12.3;
	cout<<x<<" "<<y<<endl;
	swapp(x,y);
	cout<<x<<" "<<y<<endl;
	char q='A',r='b';
	cout<<q<<" "<<r<<endl;
	swapp(q,r);
	cout<<q<<" "<<r<<endl;
}
