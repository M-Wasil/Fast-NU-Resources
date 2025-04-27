#include <iostream>
#include <fstream>
using namespace std;

class CharFileReader{
	ifstream file;
public:
	CharFileReader(const string& fn){
		file.open(fn);
		if(!file.is_open()){
			cerr<<"File not found!"<<endl;
			exit(1);
		}
	}
	void display(){
		char ch;
		while (file.get(ch)){
			cout<<ch;
		}
	}
	~CharFileReader(){
		if(file.is_open()){
			file.close();
		}
	}
};

int main(){
	CharFileReader reader("readfileexample.txt");
	reader.display();
	return 0;
}
