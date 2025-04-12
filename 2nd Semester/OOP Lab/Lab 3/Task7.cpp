#include <iostream>
using namespace std;

class ATM{
	string name;
	int accNum;
	float bal;
	public:
		void setter(string n,int a,float b){
			name=n;
			accNum=a;
			bal=b;
		}
		string get1(){
			return name;
		}
		int get2(){
			return accNum;
		}
		float get3(){
			return bal;
		}
		float checkBal(){
			return bal;
		}
		void deposit(){
			float mon;
			cout << "Enter amount to be depositted: " ;
			cin >> mon;
			bal+=mon;
			cout << "Deposit succesfull";
		}
		void withdraw(){
			float mon;
			cout << "Enter amount to withdraw: " ;
			cin >> mon;
			if (bal>=mon){
				bal-=mon;
				cout << "Transaction succesfull";
			}else{
				cout << "Insufficient balance";
			}
		}
		void display(){
			int choice;
			cout << "Welcome to ATM simulator\nSelect an option from the menu below: " << endl;
			do{
				cout << "1.Check Balance\n2.Deposit Money\n3.Withdraw Money\n4.Exit" << endl;
				cin >> choice;
				switch(choice){
					case 1:
						cout << "Balance: " << checkBal() << endl;
						break;
					case 2:
						deposit();
						break;
					case 3:
						withdraw();
						break;
					case 4:
						cout << "Thank you for using the ATM" << endl;
						break;
					default:
						cout << "Invalid choice";
						break;
				}
			}while (choice!=4);
		}
};

int main(){
	ATM a;
	a.setter("Wasil",230448001,350.95);
	cout << "Welcome Mr." << a.get1() << endl;
	cout << "Account Number: " << a.get2() << endl;
	a.display();
}
