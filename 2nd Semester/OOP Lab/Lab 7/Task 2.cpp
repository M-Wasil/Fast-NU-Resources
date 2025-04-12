#include <iostream>
using namespace std;

class Matrix{
	int mat[2][2];
public:
	Matrix(int m[2][2]){
		for (int i =0;i <2;i++){
            for (int j =0;j <2;j++){
                mat[i][j] = m[i][j];
            }
        }
	}
	Matrix operator+(const Matrix& obj) const{
		int sum[2][2];
		for (int i =0;i <2;i++){
            for (int j =0;j <2;j++){
                sum[i][j]= mat[i][j] +obj.mat[i][j];
            }
        }
        return Matrix(sum);
	}
	void display(){
		for (int i =0;i <2;i++){
            for (int j =0;j <2;j++){
                cout << mat[i][j] << " ";
            }
            cout<<endl;
        }
	}
};

int main(){
	int m1[][2]={{0,7},{9,0}};
	int m2[][2]={{0,5},{6,5}};
	Matrix a1(m1),a2(m2);
	Matrix mSum=a1+a2;
	cout << "Matrix 1:" << endl;
    a1.display();
    cout << "Matrix 2:" << endl;
    a2.display();
    cout << "Sum:" << endl;
    mSum.display();
    return 0;
}
