#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

int main(){
	int choice;
	string msg;
	ofstream f;
	f.open("system_log.txt",ios::app);
	if (!f){
		cout<<"Couldnt open file!";
		return 1;
	}
	time_t ct=time(0);
	char* stTime=ctime(&ct);
	f<<"System started at: "<<stTime<<"\n";
	return 0;
}
