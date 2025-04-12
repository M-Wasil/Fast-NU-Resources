#include <iostream>
#include <string>
using namespace std;

struct Product{
	string name;
	int id;
	double price;
	int quantity;
};

int main(){
	Product p;
	p.name="Ramen";
	p.id=183006;
	p.price=480;
	p.quantity=120;
	cout << "Product name: " << p.name << endl;
	cout << "ID: " << p.id << endl;
	cout << "Price: " << p.price << endl;
	cout << "Quantity: " << p.quantity << endl;
}
