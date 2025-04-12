#include <iostream>
using namespace std;

class Complex{
	int real;
	int imag;
public:
	Complex(int r=0,int i=0):real(r),imag(i){}
	Complex operator+(const Complex&obj){
		return Complex(real+obj.real,imag+obj.imag);
	}
	Complex operator*(const Complex& obj){
		return Complex(real*obj.real-imag*obj.imag,real*obj.imag+imag*obj.real);
	}
	void display(){
        cout << real << " + " << imag << "i" <<endl;
    }
};
int main(){
	Complex c1(2,3),c2(3,4);
	Complex sum=c1+c2;
	Complex product=c1*c2;
	cout<<"Sum: ";
	sum.display();
	cout<<"Product: ";
	product.display();
	return 0;
}
