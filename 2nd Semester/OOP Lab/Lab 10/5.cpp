#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(){
	string para;
	string word;
	ifstream f("story.txt");
	if (f.is_open()){
		while (getline(f,para)){
			istringstream iss(para);
			while(iss>>word){
				cout<<word<<endl;
			}
		}
		f.close();
	}else{
		cout<<"File not found!"<<endl;
	}
	return 0;
}
