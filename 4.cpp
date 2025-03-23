#include <iostream>
using namespace std;

int main(){
	int arr[]={1,3,2,5,3,7,6};
	int store[7]={0};
	int i;
	for(i=0;i<7;i++){
		if (i==0 && arr[i]>arr[i+1]){
			store[i]=arr[i];
		}else if(i==6 && arr[i]>arr[i-1]){
			store[i]=arr[i];
		}else if(i>0 && i<6 && arr[i]>arr[i-1] && arr[i]>arr[i+1]){
			store[i]=arr[i];
		}
	}
	cout << "Peak elements are: " << endl;
	for(i=0;i<7;i++){
		if (store[i]!=0){
			cout << store [i] << " ";	
		}
	}
}
