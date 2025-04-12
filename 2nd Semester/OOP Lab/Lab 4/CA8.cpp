#include <iostream>
#include <string>
using namespace std;
	class Product{
		private:
			string name;
			double price;
			
		public:
				Product(){
					name ="Unknown";
					price = 0.0;
				}
				Product(string name, double price){
					this->name = name;
					this->price = price;
					cout<< "Product added" <<name <<"-$"<<price<<endl;
				}
				void updateprice(double newprice){
					price = newprice;
					cout << "Updated price of " << name << "to $" << price <<endl;
					
				}
				void display(){
					cout << "Product:" << name << ", price: $" <<price<<endl;
					
				}
	};
	int main(){
		Product defaultproduct;
		defaultproduct.display();
		Product laptop("Chocolate ",100.0);
		laptop.updateprice(99.9);
		laptop.display();
	
	return 0;

}