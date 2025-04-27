#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ofstream f;
	f.open("output.txt");
	if(!f){
		cout<<"Error! File couldnt be created..."<<endl;
		return 1;
	}
	f<< "This is a basic example of writing to a file in C++.\n";
	f<< "File handling makes data storage easier.\n";
	f.close();
	cout<<"Data successfully written"<<endl;
	return 0;
}
