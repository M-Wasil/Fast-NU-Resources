#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ofstream outF("Example.txt");
	if(!outF){
		cout<<"Error! File couldnt be created..."<<endl;
		return 1;
	}
	outF<<"Hello, this file was created using construnctor method!\n";
	outF<<"File handling in C++ is fun and usefull!\n";
	outF.close();
	cout<<"Data successfully written to Example.txt"<<endl;
	return 0;
}
