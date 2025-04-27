#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileReader{
	ifstream file;
	string filename;
public:
	FileReader(const string& fn):filename(fn){
		file.open(filename);
	}
	bool isOPen() const{
		return file.is_open();
	}
	void display(){
		string content;
		while (getline(file,content)){
			cout<<content<<endl;
		}
	}
	~FileReader(){
		if(file.is_open()){
			file.close();
		}
	}
};

int main(){
	FileReader reader("example.txt");
	if (reader.isOPen()){
		reader.display();
	}else{
		cout<<"Unable to open file"<<endl;
	}
	return 0;
}
