#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ifstream inF("readfileexample.txt");
	char ch;
	if (inF.is_open()){
		while (inF.get(ch)){
			cout<<ch;
		}
		inF.close();
	}else{
		cout<<"File not found!"<<endl;
	}
	return 0;
}
