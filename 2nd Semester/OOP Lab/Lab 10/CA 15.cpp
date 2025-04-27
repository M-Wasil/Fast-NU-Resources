#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ofstream out("output.txt",ios::binary);
	if (!out){
		cerr<<"File creation failed!"<<endl;
		return 1;
	}
	out.write("HELLO",5);
	streampos pos=out.tellp();
	cout<<"Position after writing: "<<pos<<endl;
	out.seekp(10,ios::beg);
	out.write("WORLD",5);
	out.close();

	return 0;
}
