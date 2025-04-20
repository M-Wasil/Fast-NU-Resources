#include <iostream>
using namespace std;

class Book{
    string title;
    string author;
    bool available;
public:
    Book():title(""),author(""),available(false){}
    Book(string t,string a):title(t),author(a),available(true){}

    string getTitle() const{
		return title;
	}
    string getAuthor() const{
		return author;
	}
    bool isAvailable() const{
		return available;
	}
    void borrowBook(){
		available=false;
	}
    void returnBook(){
		available=true;
	}
    bool isEmpty() const{
		return title=="";
	}
};
class ILibraryUser{
public:
    virtual void searchBook(const string& title)=0;
    virtual void borrowBook(const string& title)=0;
    virtual void returnBook(const string& title)=0;
};
class ILibrarian{
public:
    virtual void addBook(const string& title,const string& author)=0;
    virtual void removeBook(const string& title)=0;
};
class LibrarySystem:public ILibraryUser,public ILibrarian{
    Book books[100];
    int findBookIndex(const string& title){
        for(int i=0;i<100;i++){
            if(!books[i].isEmpty() && books[i].getTitle()==title){
                return i;
            }
        }
        return -1;
    }
public:
    void addBook(const string& title,const string& author){
        for(int i=0;i<100;i++){
            if(books[i].isEmpty()){
                books[i]=Book(title,author);
                cout<<"Book added: "<<title<<endl;
                return;
            }
        }
        cout<<"Library is full!"<<endl;
    }
    void removeBook(const string& title){
        int index=findBookIndex(title);
        if(index!=-1){
            books[index]=Book();
            cout<<"Book removed: "<<title<<endl;
        }else{
            cout<<"Book not found."<<endl;
        }
    }
    void searchBook(const string& title){
        int index=findBookIndex(title);
        if(index!=-1){
            cout<<"Found: "<<books[index].getTitle()<<" by "<<books[index].getAuthor()<<" | "<<(books[index].isAvailable()?"Available":"Borrowed")<<endl;
        }else{
            cout<<"Book not found."<<endl;
        }
    }
    void borrowBook(const string& title){
        int index=findBookIndex(title);
        if(index!=-1 && books[index].isAvailable()){
            books[index].borrowBook();
            cout<<"Book borrowed: "<<title<<endl;
        }else{
            cout<<"Book not available."<<endl;
        }
    }
    void returnBook(const string& title){
        int index=findBookIndex(title);
        if(index!=-1 && !books[index].isAvailable()){
            books[index].returnBook();
            cout<<"Book returned: "<<title<<endl;
        }else{
            cout<<"Cannot return book."<<endl;
        }
    }
};

int main(){
    LibrarySystem library;
    library.addBook("Harry Potter","J.K. Rowling");
    library.addBook("The Metamorphosis","Franz Kafka");
    library.searchBook("The Metamorphosis");
    library.borrowBook("The Metamorphosis");
    library.searchBook("The Metamorphosis");
    library.returnBook("The Metamorphosis");
    library.searchBook("The Metamorphosis");
    library.removeBook("Harry Potter");
    library.searchBook("Harry Potter");
    return 0;
}

