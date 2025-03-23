#include <iostream>
#include <string>
using namespace std;

int main(){
	string arr,arr2="";
	cout << "Enter a string: ";
	getline(cin,arr);
	int len,count=0,i;
	len=arr.length();
	for (i=0;i<len;i++){
		if (arr[i]=='a' || arr[i]=='e' || arr[i]=='i' || arr[i]=='o' || arr[i]=='u'){
			count++;
		}else if(arr[i]=='A' || arr[i]=='E' || arr[i]=='I' || arr[i]=='O' || arr[i]=='U'){
			count++;
		}
	}
	cout << "There are total " << count << " vowels in this string." << endl;
	cout << "String without spaces: ";
	for (i=0;i<len;i++){
		if (arr[i]==' '){
			i++;
		}
		cout << arr[i];
	}
	cout <<endl << "String converted to upper case: ";
	for (i=0;i<len;i++){
		arr2+= toupper (arr[i]);
	}
	cout << arr2;
}
