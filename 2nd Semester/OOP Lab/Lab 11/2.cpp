#include <iostream>
using namespace std;

int division(int &a,int &b){
	if(b==0){
		throw "division with zero is not possible!";
	}
	else{
		return a/b;
	}
}

int main(){
	int a=12, b=0;
	try{
		int x=division(a,b);
		cout<<"division: "<<x<<endl;
	}
	catch(const char *e){
		cout<<"exception: "<<e<<endl;
	}
}
