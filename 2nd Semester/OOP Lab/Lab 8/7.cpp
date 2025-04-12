#include <iostream>
using namespace std;

class InventoryManager;
class Product{
    string productName;
    double price;
    int stockQuantity;
public:
    Product(string p,double pr,int s):productName(p),price(pr),stockQuantity(s){}
    friend class InventoryManager;
    friend void applyDiscount(Product& p,double discountPercent);
};
class InventoryManager{
public:
    void displayStock(Product& p){
        cout<<"Product: "<<p.productName<<endl;
        cout<<"Price: $"<<p.price<<endl;
        cout<<"Stock: "<<p.stockQuantity<<endl;
    }
    void updateStock(Product& p,int newStock){
        p.stockQuantity=newStock;
    }
};
void applyDiscount(Product& p,double discountPercent){
    p.price-=p.price*(discountPercent/100);
    cout<<"Discount applied! New price: $"<<p.price<<endl;
}

int main(){
    Product prod("Laptop",1200,50);
    InventoryManager manager;
    manager.displayStock(prod);
    applyDiscount(prod,15);
    manager.updateStock(prod,45);
    manager.displayStock(prod);
    
    return 0;
}
