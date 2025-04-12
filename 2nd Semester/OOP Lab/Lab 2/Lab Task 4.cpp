#include <iostream>
#include <string>
using namespace std;

int main(){
	int* com =new int[5];
	com[0]=84;
	com[1]=37;
	com[2]=55;
	com[3]=10;
	com[4]=29;
	cout << "Age of people in this community: " << endl;
	for (int i=0;i<5;i++){
		cout << com[i]<< " ";
	}
	cout << endl;
	
	delete com;
}
