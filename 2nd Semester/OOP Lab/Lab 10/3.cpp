#include <iostream>
#include <fstream>
using namespace std;

int main(){
	int choice;
	string msg;
	string email;
	ofstream f;
	f.open("signup.txt",ios::app);
	if (!f){
		cout<<"Couldnt open file!";
		return 1;
	}
	do{
		cout<<"1. Enter user name and email address:"<<endl;
		cout<<"2. Exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>choice;
		cin.ignore();
		switch(choice){
			case 1:{
				cout<<"Name: ";
				getline(cin,msg);
				f<<"\nName: "<<msg;
				cout<<"Email: ";
				getline(cin,email);
				f<<", Email: "<<email;
				break;
			}
			case 2:{
				cout<<"Exiting...";
				f.close();
				break;
			}
			default:cout<<"Invalid choice!"<<endl;
		}
	}while(choice!=2);
	return 0;
}
