#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(){
	int count;
	char ch;
	ifstream f("secret.txt");
	if (f.is_open()){
		while (f.get(ch)){
			if (ch>=65&&ch<=90){
				count++;
			}
		}
		f.close();
	}else{
		cout<<"File not found!"<<endl;
	}
	cout<<"Total uppercase letters: "<<count;
	return 0;
}
