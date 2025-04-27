#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
	ifstream inF("example.txt");
	string line;
	if (inF.is_open()){
		while (getline(inF,line)){
			cout<<line<<endl;
		}
		inF.close();
	}else{
		cout<<"Unable to open File."<<endl;
	}
	return 0;
}
