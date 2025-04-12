#include <iostream>
using namespace std;

int main(){
	int arr[5],i,j;
	cout << "Enter elements for matrix: " << endl;
	for (i=0;i<5;i++){
		cin >> arr[i];
	}
	int temp;
	for (i=0;i<5;i++){
		for (j=0;j<5;j++){
			if (arr[j]<arr[j+1]){
				temp=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=temp;
			}
		}
	}
	cout << "Reversed array is: " << endl;
	for (i=0;i<5;i++){
		cout << arr[i] << " ";
	}	
}
