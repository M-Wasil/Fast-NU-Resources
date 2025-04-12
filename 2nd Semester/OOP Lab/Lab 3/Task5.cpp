#include "Add.h"
Book::Book(){
    title = "";
    author = "";
    ISBN = "";
    isAvailable = true;
}
void Book::addBook(string t, string a, string i){
    title = t;
    author = a;
    ISBN = i;
    isAvailable = true;
}
void Book::display(){
    cout << "Title: " << title << "\nAuthor: " << author << "\nISBN: " << ISBN << "\nStatus: " << (isAvailable ? "Available" : "Issued") << "\n\n";
}
bool Book::matches(string query){
    return (title == query || ISBN == query);
}
Book* searchBook(Book library[], int count, string query){
    for (int i = 0; i < count; i++){
        if (library[i].matches(query)){
            return &library[i];
        }
    }
    return nullptr;
}
int main(){
    Book library[100];
    int count = 0;
    int choice;
    string title, author, ISBN;
    Book* foundBook = nullptr;

    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n2. Search Book\n3. Display Books\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                if (count < 100){
                    cout << "Enter Title: ";
                    getline(cin, title);
                    cout << "Enter Author: ";
                    getline(cin, author);
                    cout << "Enter ISBN: ";
                    getline(cin, ISBN);
                    library[count].addBook(title, author, ISBN);
                    count++;
                    cout << "Book added successfully!\n";
                } else {
                    cout << "Library is full! Cannot add more books.\n";
                }
                break;

            case 2:
                cout << "Enter Title or ISBN to search: ";
                getline(cin, title);
                foundBook = searchBook(library, count, title);
                if (foundBook){
                    cout << "Book Found!\n";
                    foundBook->display();
                } else{
                    cout << "Book not found!\n";
                }
                break;

            case 3:
                if (count == 0){
                    cout << "No books in the library.\n";
                } else{
                    cout << "Library Books:\n";
                    for (int i=0; i<count;i++){
                        library[i].display();
                    }
                }
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);
    return 0;
}

