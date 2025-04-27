#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
	ifstream inF("readfileexample.txt");
	string word;
	if (inF.is_open()){
		while (inF>>word){
			cout<<word<<endl;
		}
		inF.close();
	}else{
		cout<<"File not found!"<<endl;
	}
	return 0;
}
