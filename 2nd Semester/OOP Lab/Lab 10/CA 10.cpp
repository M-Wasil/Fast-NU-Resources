#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileReader{
	ifstream file;
public:
	FileReader(const string& fn){
		file.open(fn);
		if(!file.is_open()){
			cerr<<"File not found!"<<endl;
			exit(1);
		}
	}
	void display(){
		string word;
		while (file>>word){
			cout<<word<<endl;
		}
	}
	~FileReader(){
		if(file.is_open()){
			file.close();
		}
	}
};

int main(){
	FileReader reader("readfileexample.txt");
	reader.display();
	return 0;
}
