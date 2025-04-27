#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ofstream f;
	f.open("data.txt",ios::app);
	if(!f){
		cout<<"Error! File couldnt be created..."<<endl;
		return 1;
	}
	f<<"This line is appended using open() method!\n";
	f.close();
	cout<<"Data successfully written"<<endl;
	return 0;
}
