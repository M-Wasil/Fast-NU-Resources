#ifndef TASK8_H
#define TASK8_H

#include <iostream>
using namespace std;

class Product{
	string name;
	float price;
	float discount;
	int stock;
	public:
		Product(): name(""),price(0),discount(0),stock(0){}
		Product(string n,float p,float d, int s) : name(n),price(p), stock(s), discount(d){}
		void dis(){
			price-=price*(discount/100);
		}
		void update(){
			int temp;
			cout << "how many stock to reduce? ";
			cin >> temp;
			if (stock>0 && stock>=temp){
				stock-=temp;
			}else{
				cout << "Not enough stock" << endl;
			}
		}
		void display();
};
#endif
