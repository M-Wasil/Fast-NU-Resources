#include <iostream>
using namespace std;

class Product{
    string name;
    double price;
    public:
        Product(){
            name="Unknown";
            price=0.0;
        }
        void addProduct(string prodName,double prodPrice){
            name=prodName;
            price=prodPrice;
            cout << "Product added: " << name << " - $" << price << endl;
        }
        void updatePrice(double newPrice){
            price=newPrice;
            cout << "Updated price of " << name << " - $" << price << endl;
        }
        void display(){
            cout << "Product: " << name << "Price:  $" << price << endl;
        }
};
int main(){
    Product p;
    p.display();
    p.addProduct("Laptop", 1200.0);
    p.updatePrice(1100.0);
    p.display();
}