#include <iostream>
using namespace std;
class A{
	public:
		int x;
		A() {
			x = 10;
		}};
class B : virtual public A{};
class C : virtual public A{};
class D : public B, public C {};
int main(){
	D d;
	cout << d.x;
	return 0 ;
}
