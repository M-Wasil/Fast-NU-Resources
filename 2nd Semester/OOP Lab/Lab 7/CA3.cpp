#include <iostream>
using namespace std;

class Ruppee{
	long data;
public:
	Ruppee(int rup=0):data(rup){}
	Ruppee operator-() const{
		return Ruppee(-data);
	}
	Ruppee operator+(const Ruppee&obj) const{
		return Ruppee(data+obj.data);
	}
	Ruppee operator-(const Ruppee&obj) const{
		return Ruppee(data-obj.data);
	}
	Ruppee& operator+=(const Ruppee&obj){
		data+=obj.data;
		return *this;
	}
	Ruppee& operator-=(const Ruppee&obj){
		data-=obj.data;
		return *this;
	}
	long getdata() const{
		return data;
	}
};

ostream& operator<<(ostream& os, const Ruppee& e){
	os<<e.getdata();
	return os;
}

int main(){
	Ruppee wholesale(20),retail;
	retail=wholesale;
	cout<<"Wholesale price:"<<wholesale<<endl;
	cout<<"Retail price: "<<retail<<endl;
	
	Ruppee discount(2);
	retail-=discount;
	cout<<"Retail price with discount: "<<retail<<endl;
	wholesale=Ruppee(34);
	cout<<"New wholesale price: "<<wholesale<<endl;
	retail=wholesale+10;
	cout<<"New retail price: "<<retail<<endl;
	Ruppee profit(retail-wholesale);
	cout<<"The profit: "<<profit<<endl;
	profit=-profit;
	cout<<"The profit after unary minus: "<<profit<<endl;
	return 0;
}
