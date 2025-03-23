#include <iostream>
using namespace std;

void sum(int mat[][2],int mat2[][2]){
	int i,j,x[2][2];
	for (i=0;i<2;i++){
		for (j=0;j<2;j++){
			x[i][j]= mat[i][j]+mat2[i][j];
		}
	}
	cout << "Sum is: " << endl;
	for (i=0;i<2;i++){
		for (j=0;j<2;j++){
			cout << x[i][j] << " ";
		}
		cout << endl;
	}
}

void sub(int mat[][2],int mat2[][2]){
	int i,j,x[2][2];
	for (i=0;i<2;i++){
		for (j=0;j<2;j++){
			x[i][j]= mat[i][j]-mat2[i][j];
		}
	}
	cout << "Matrix subtraction is: " << endl;
	for (i=0;i<2;i++){
		for (j=0;j<2;j++){
			cout << x[i][j] << " ";
		}
		cout << endl;
	}
}

void prod(int mat[][2],int mat2[][2]){
	int i,j,k,x[2][2];
	for (i=0;i<2;i++){
		for (j=0;j<2;j++){
			x[i][j]=0;
            for (k=0;k<2;k++){
                x[i][j] +=mat[i][k]*mat2[k][j];
            }
		}
	}
	cout << "Matrix multiplication is: " << endl;
	for (i=0;i<2;i++){
		for (j=0;j<2;j++){
			cout << x[i][j] << " ";
		}
		cout << endl;
	}
}

int main(){
	int i,j;
	int mat[2][2],mat2[2][2];
	cout << "Enter elements for matrix A: " << endl;
	for (i=0;i<2;i++){
		for (j=0;j<2;j++){
			cin >> mat[i][j];
		}
	}
	cout << "Enter elements for matrix B: " << endl;
	for (i=0;i<2;i++){
		for (j=0;j<2;j++){
			cin >> mat2[i][j];
		}
	}
	cout << "Matrix A: " << endl;
	for (i=0;i<2;i++){
		for (j=0;j<2;j++){
			cout << mat[i][j];
		}
		cout << endl;
	}
	cout << "Matrix B: " << endl;
	for (i=0;i<2;i++){
		for (j=0;j<2;j++){
			cout << mat2[i][j];
		}
		cout << endl;
	}
	sum(mat,mat2);
	sub(mat,mat2);
	prod(mat,mat2);
}
