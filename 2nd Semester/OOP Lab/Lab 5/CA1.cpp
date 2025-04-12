#include <iostream>
using namespace std;

class Account{
	public:
		int accNo;
		string name;
		static float rateOfInterest;
		Account (int accNo,string name){
			this->accNo=accNo;
			this->name=name;
		}
		void display(){
			cout << accNo<<" "<<name<<" "<< rateOfInterest<<endl;
		}
};
float Account::rateOfInterest=6.5;
int main(){
	Account a1=Account(7840,"Wasil");
	Account a2=Account(7841,"Ahmed");
	a1.display();
	a2.display();
	return 0;
}
