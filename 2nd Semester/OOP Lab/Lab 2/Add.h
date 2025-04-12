#ifndef ADD_H
#define ADD_H

#include <iostream>
using namespace std;

class Book{
	string title;
    string author;
    string ISBN;
    bool isAvailable;
	
	public:
	Book();
	void addBook(string t, string a, string i);
	void display();
	bool getAvailability();

};
Book* searchBook(Book library[], int bookCount, string query);

#endif
