#include <iostream>
using namespace std;

class Librarian;
class Book{
	string title;
	double price;
public:
	Book(string t,double p):title(t),price(p){}
	friend class Librarian;
};
class Librarian{
public:
	void display(const Book& b){
		cout<<"Book title: "<<b.title<<endl;
		cout<<"Book price: $"<<b.price<<endl;
	}
	void discount(Book& b,double dis){
		b.price-=dis;
		cout<<"Discounted price: $"<<b.price<<endl;
	}
};

int main(){
	Book b("C++ Programming",45.99);
	Librarian l;
	l.display(b);
	l.discount(b,10.0);
	
	return 0;
}
