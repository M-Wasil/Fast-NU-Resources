#include <iostream>
using namespace std;

struct Book{
	string title;
	string author;
	int isbn;
	int availability;
};

int main(){
	Book* b=new Book[3];
	cout << "Enter info for books: " << endl;
	for (int i=0;i<3;i++){
		cout << "Book title: ";
		cin >> b[i].title;
		cout << "Author: ";
		cin >> b[i].author;
		cout << "ISBN: ";
		cin >> b[i].isbn;
		cout << "Availibility (1 for available/ 0 for unavailable): ";
		cin >> b[i].availability;
	}
	for (int i=0;i<3;i++){
		cout << b[i].title << " " << endl;
		cout << b[i].author << " " << endl;
		cout << b[i].isbn << " " << endl;
		if (b[i].availability==1){
			cout << "Available " << endl;
		}else if(b[i].availability==0){
			cout << "Unavailable " << endl;
		}
	}
	delete[] b;
}
