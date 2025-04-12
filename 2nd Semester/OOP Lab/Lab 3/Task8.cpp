#include "Task8.h"

void Product::display(){
    cout << "Product Name: " << name << endl;
	cout << "Price: " << price << "\nDiscount: " << discount << "\nStock Available: " << stock;
}
int main(){
	Product p("Watch",1999,25,50);
	p.dis();
	p.update();
	p.display();
	return 0;
}
