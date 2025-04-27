#include <iostream>
#include <fstream>
using namespace std;

class FileWriter{
	ofstream file;
public:
	FileWriter(string filename){
		file.open(filename);
		if (!file){
			cerr << "Error opening file!" << endl; exit(1);
		}
	}
	void write(string content){
		file << content;
	}
	~FileWriter(){
		file.close();
		cout<<"Data written to file successfully." << endl;
	}
};

int main(){
	FileWriter writer ("output.txt");
	writer.write("This is a basic example of writing to a file in C++.\n");
	writer.write("File handling makes data storage easier.\n");
	return 0;
}
