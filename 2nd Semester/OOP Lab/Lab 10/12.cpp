#include <iostream>
#include <fstream>
using namespace std;
int main(){
	string filename;
	cout << "Enter filename: ";
	cin >> filename;
	ifstream file(filename, ios::binary);
	if (!file){
		cout << "Error: Could not open file!" << endl;
		return 1;
	}
	while (true){
		long offset;
		cout << "\nEnter byte offset (or -1 to quit): ";
		cin >> offset;
		if (offset == -1) break;
		file.seekg(0, ios::end);
		long fileSize = file.tellg();

		if (offset < 0 || offset >= fileSize){
			cout << "Error: Offset out of range (0-" << fileSize-1 << ")\n";
			continue;
		}
		cout << "Pointer position before: " << file.tellg() << endl;
		file.seekg(offset);
		cout << "Pointer position after seek: " << file.tellg() << endl;
		char buffer[101] = {0};
		file.read(buffer, 100);
		
		cout << "\nNext 100 characters:\n";
		cout << "----------------------------------------\n";
		cout << buffer;
		cout << "\n----------------------------------------\n";
	}

	file.close();
	return 0;
}

