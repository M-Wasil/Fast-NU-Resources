#include <iostream>
using namespace std;

class Product{
	string name;
	string brand;
	int price;
public:
	Product(string n, string b, int p):name(n),brand(b),price(p) {}
	void display(){
		cout<<"Product Name: "<<name<<endl;
		cout<<"Brand: "<<brand<<endl;
		cout<<"Price: $"<<price<<endl;
	}
};
class ElectronicProduct: public Product{
	int period;
public:
	ElectronicProduct(string n, string b, int p,int w):Product(n,b,p),period(w){}
	void displayDetails(){
		display();
		cout<<"Warranty period: "<<period<<" months"<<endl;
	}
};

int main(){
	Product p("Dairy Milk","Cadburry",250);
	ElectronicProduct p1("S25 Ultra","Samsung",600000,18);
	cout<<"General Products:"<<endl;
	p.display();
	cout<<"Electronic Products:"<<endl;
	p1.displayDetails();
}
