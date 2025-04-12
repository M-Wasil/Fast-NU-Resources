#include <iostream>
using namespace std;
#include <string>
class calculater{
	int num1,num2;
	public:
		calculater(int a, int b){
			num1 =a;
			num2=b;
		}
		int add(){
			return num1+num2;
		}
		int sub(){
			return num1-num2;
		}int mul(){
			return num1*num2;
		}int div(){
			return num1/num2;
	}
};
int main(){
	cout<<"please enter two numbers"<<endl;
	int n,w;
	cin>>n>>w;
	calculater cal(n,w);
	cout<<"the sum is"<<cal.add()<<endl;
	cout<<"the minus is"<<cal.sub()<<endl;
	cout<<"the product is"<<cal.mul()<<endl;
	cout<<"the quotient is"<<cal.div()<<endl;
}
