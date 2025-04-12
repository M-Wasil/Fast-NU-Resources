#include <iostream>
using namespace std;

class LibraryItem{
public:
	string title;
	string author;
	LibraryItem(string t,string a):title(t),author(a){}
	void display(){
		cout<<"Title: "<<title<<endl;
		cout<<"Author: "<<author<<endl;
	}
};
class Book:public LibraryItem{
public:
	string isbn;
	Book(string t,string a,string i):LibraryItem(t,a),isbn(i){}
	void displayBook(){
		display();
		cout<<"ISBN: "<<isbn<<endl;
	}
};
class Magazine:public LibraryItem{
public:
	int issueNum;
	Magazine(string t,string a,int i):LibraryItem(t,a),issueNum(i){}
	void displayMag(){
		display();
		cout<<"Issue Number: "<<issueNum<<endl;
	}
};

int main(){
	Book b("The Metamorphosis","Franz Kafka","978-0743273565");
	Magazine m("National Geographic","Multiple Authors",404);
	cout<<"Book Details:"<<endl;
	b.displayBook();
	cout<<"Magazine Details:"<<endl;
	m.displayMag();
}
