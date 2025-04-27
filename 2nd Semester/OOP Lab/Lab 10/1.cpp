#include <iostream>
#include <fstream>
using namespace std;

int main(){
	string name;
	string msg;
	ofstream f("greeting.txt");
	if (!f.is_open()){
		cout<<"Couldnt open file!";
		return 1;
	}
	cout<<"Enter recipient’s name: ";
	getline(cin,name);
	cout<<"Enter a message for recipient: ";
	getline(cin,msg);
	f<<"Dear "<<name<<",\n"<<msg<<"\nBest Regards!";
	f.close();
	cout<<"Task performed!"<<endl;
	return 0;
}
