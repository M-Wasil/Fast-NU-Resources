#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
	fstream file("data.txt", ios::in | ios::out | ios::trunc | ios::binary);
	if (!file) {
		cerr << "File error!";
		return 1;
	}

	string quote="In the middle of difficulty lies opportunity. ~Albert Einstein ";
	file.write(quote.c_str(), quote.size());
	file.seekg(0);
	char buffer[6] = {0};
	file.read(buffer, 5);
	cout<<"First 5 bytes: " << buffer << endl;
	file.seekp(7);
	file.write("MIDDLE", 6);

	file.seekg(0);
	string content;
	getline(file, content, '\0');
	cout<<"Final content:"<< content << endl;
	file.close();
	return 0;
}
