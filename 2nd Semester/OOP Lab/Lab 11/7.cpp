#include<iostream>
#include<string>
using namespace std;

class OutOfBoundsException{
public:
    const char* what() const{
        return "OutOfBoundsException caught: Invalid index access attempted!";
    }
};

template<typename T>
class SmartArray{
private:
    T* data;
    int size;

public:
    SmartArray(int s){
        size=s;
        data=new T[size];
    }

    ~SmartArray(){
        delete[] data;
    }

    T& operator[](int index){
        if(index<0||index>=size){
            throw OutOfBoundsException();
        }
        return data[index];
    }
};

int main(){
    int size;
    cout<<"Array size: ";
    cin>>size;
    SmartArray<int> intArray(size);
    cout<<"Enter elements: ";
    for(int i=0;i<size;++i){
        cin>>intArray[i];
    }
    cout<<"Accessing index 2: ";
    try{
        cout<<intArray[2]<<endl;
    }catch(OutOfBoundsException& e){
        cout<<endl<<e.what()<<endl;
    }
    cout<<"Accessing index 5: ";
    try{
        cout<<intArray[5]<<endl;
    }catch(OutOfBoundsException& e){
        cout<<endl<<e.what()<<endl;
    }

    SmartArray<string> strArray(3);
    strArray[0]="Apple";
    strArray[1]="Banana";
    strArray[2]="Peach";
    cout<<"Accessing string index 1: ";
    try{
        cout<<strArray[1]<<endl;
    }catch(OutOfBoundsException& e){
        cout<<endl<<e.what()<<endl;
    }
    cout<<"Accessing string index 3: ";
    try{
        cout<<strArray[3]<<endl;
    }catch(OutOfBoundsException& e){
        cout<<endl<<e.what()<<endl;
    }

    return 0;
}
