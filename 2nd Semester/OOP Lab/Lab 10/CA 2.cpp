#include <iostream>
#include <fstream>
using namespace std;

class FileHandler{
	ofstream outF;
	string filename;
public:
	FileHandler(string fn):filename(fn){
		outF.open(filename);
		if (!outF){
			cout<<"Error! File couldnt be created..."<<endl;
			exit(1);
		}
	}
	void writeData(string data){
		if(outF.is_open()){
			outF<<data;
		}
	}
	void closeFile(){
		if(outF.is_open()){
			outF.close();
			cout<<"Data successfully written to "<<filename<<endl;
		}
	}
};
int main(){
	FileHandler f("example.txt");
	f.writeData("Hello, this file was created using construnctor method!\n");
	f.closeFile();
	return 0;
}
