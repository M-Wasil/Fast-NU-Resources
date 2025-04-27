#include <iostream>
#include <fstream>
using namespace std;

int main(){
	int choice;
	string msg;
	ofstream f;
	f.open("diary.txt",ios::app);
	if (!f){
		cout<<"Couldnt open file!";
		return 1;
	}
	do{
		cout<<"1. Enter message for the diary"<<endl;
		cout<<"2. Exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>choice;
		cin.ignore();
		switch(choice){
			case 1:{
				cout<<"Enter your text: ";
				getline(cin,msg);
				f<<msg<<"\n";
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
