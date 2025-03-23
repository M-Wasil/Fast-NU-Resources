#include <iostream>
using namespace std;

int main(){
	int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	int i,j,sum=0;
	for (i=0;i<3;i++){
		sum+=arr[0][i];
		sum+=arr[2][i];
	}
	for (i=1;i<2;i++){
		sum+=arr[i][0];
		sum+=arr[i][2];
	}
	cout << "Sum of border line elements is: " << sum << endl;
}
