#include <iostream>
using namespace std;

class MyClass{
public:
    int num;
    MyClass(){
        num=0;
    }
    MyClass(int n){
        num=n;
    }
    void display(){
        cout <<"Number: " << num<< endl;
    }
};

int main(){
    const int size=5;
    MyClass arr[size]; 
    for (int i=0;i< size;i++){
        arr[i]=MyClass(i+1); 
    }
    for (int i=0;i<size;i++){
        arr[i].display();
    }
    return 0;
}