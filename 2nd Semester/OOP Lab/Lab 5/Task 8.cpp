#include <iostream>
using namespace std;

class loanAccount{
	const int accNum;
	int loanBal;
public:
	loanAccount(int acc,double bal):accNum(acc),loanBal(bal) {}
	int getAccNum() const{
		return accNum;
	}
	int getLoanBal() const{
		return loanBal;
	}
	void applyPayment(double amount){
		loanBal-=amount;
	}
	void takeLoan(double amount){
		loanBal+=amount;
	}
	void display(){
		cout <<"Account No: "<<accNum<<" | Loan Balance: $"<<loanBal<<endl;
	}
};

int main(){
	loanAccount a1(1001,5000);
	a1.display();
	a1.applyPayment(1000);
	a1.display();
	a1.takeLoan(2000);
	a1.display();
	return 0;
}
