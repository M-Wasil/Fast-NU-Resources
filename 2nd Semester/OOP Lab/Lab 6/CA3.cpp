#include <iostream>
using namespace std;
class base1 {
public:
	int i, b;
	base1(int i, int b) {
	this->i = i;
	this->b= b;
	}
};
class base2 {
	public:
	int j, c;
	base2(int j, int c) {
	this->j=j;
	this->c = c;
	}
};
class derived :public base1, public base2 { 
public:
	derived(int i, int b, int j, int c):base1(i, b), base2(j, c) {}
	void showData1() {
		cout << "i = " << i <<endl<< "b= " << b << endl;
	}
	void showData2() {
		cout << "j =  " << j <<endl<< "c = " << c << endl;
	}
};
int main() {
	derived d1(4, 5, 6, 7);
	d1.showData1();
	d1.showData2();
	return 0;
}
