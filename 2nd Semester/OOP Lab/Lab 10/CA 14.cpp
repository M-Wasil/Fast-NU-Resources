#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
	ifstream in("input.txt",ios::binary);
	if (!in){
		cerr<<"File not found"<<endl;
		return 1;
	}
	char buffer[6]={0};
	in.read(buffer,5);
	cout<<"First 5 bytes: "<<buffer<<endl;
	
	in.seekg(10,ios::beg);
	streampos pos=in.tellg();
	cout<<"Current position: "<<pos<<endl;
	
	in.read(buffer,5);
	cout<<"Bytes 10-14:";
	cout.write(buffer,5);
	cout<<endl;
	
	in.close();
	return 0;
}
