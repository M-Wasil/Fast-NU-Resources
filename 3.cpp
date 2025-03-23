#include <iostream>
using namespace std;

int main(){
	int arr[]={1,2,3,4,5};
	int x,i;
	cout << "How many steps to rotate? ";
	cin >> x;
	if (x>=0 && x<=5){
		for (i=(5-x);i<5;i++){
			cout << arr[i] << " ";
		}
		for (int i=0;i<(5-x);i++){
			cout << arr[i] << " ";
		}
	}else{
		cout << "Invalid steps!" << endl;
	}
}
