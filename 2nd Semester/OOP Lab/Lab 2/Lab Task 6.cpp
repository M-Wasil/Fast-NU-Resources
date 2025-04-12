#include <iostream>
using namespace std;

struct Speaker{
	string name;
	string topic;
	int slot;
};

int main(){
	Speaker* s=new Speaker[4];
	cout << "Enter info for speakers: " << endl;
	for (int i=0;i<4;i++){
		cin >> s[i].name;
		cin >> s[i].topic;
		cin >> s[i].slot;
	}
	for (int i=0;i<4;i++){
		cout << s[i].name << " " << endl;
		cout << s[i].topic << " " << endl;
		cout << s[i].slot << " " << endl;
	}
	delete[] s;
}
