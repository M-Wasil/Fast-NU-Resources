#include <iostream>
using namespace std;

int main(){
	int row=3;
	int col=4;
	int** mat=new int*[row];
	for (int i=0;i<row;i++){
		mat[i]=new int[col];
	}
	mat[0][0]=10;
	mat[1][2]=20;
	for (int i=0;i<row;i++){
		for (int j=0;j<col;j++){
			mat[i][j]=(i*j)+2;
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
	for (int i=0;i<row;i++){
		delete[] mat[i];
	}
	delete[] mat;
}
