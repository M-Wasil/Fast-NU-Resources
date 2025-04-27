#include <iostream>
#include <fstream>
using namespace std;

class FileHandler{
	ofstream outF;
public:
	FileHandler(string fn){
		outF.open(fn,ios::app);
		if (!outF){
			cout<<"Error! File couldnt be created..."<<endl;
			exit(1);
		}
	}
	void append(string data){
		outF<<data;
	}
	~FileHandler(){
		outF.close();
		cout<<"Data successfully written"<<endl;
	}
};
int main(){
	FileHandler f("Data.txt");
	f.append("This line is appended using open() method!\n");
	return 0;
}
