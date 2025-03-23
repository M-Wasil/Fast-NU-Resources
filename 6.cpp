#include <iostream>
using namespace std;

int main(){
	int n,sum=0;
	cout << "Enter number: ";
	cin >> n;
	int i,x[100]={0};
	for (i=1;i<n;i++){
		if (n%i==0){
			x[i]=i;
		}
	}
	for (i=0;i<n;i++){
		sum+=x[i];
	}
	if (sum==n){
		cout << n << " is a perfect number."<< endl;
	}else{
		cout << n << " is not a perfect number."<< endl;
	}
}

