#include "Calculator.h"  
#include <iostream>

using namespace std;
void Calculator::add(){
	cout<<"Addition: "<<a+b<<endl;
}

void Calculator::subtract(){
	cout<<"Subtract: "<<b-a<<endl;
}

void Calculator::divide(){
	cout<<"Divide: "<<a/b<<endl;
}

void Calculator::multiply(){
	cout<<"Multiply: "<<a*b<<endl;
}

Calculator::Calculator(int a,int b):a(a),b(b){}
