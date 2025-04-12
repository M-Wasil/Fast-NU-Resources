#include <iostream>
#include <cstring>
using namespace std;

class String{
	char *array;
public:
	String(const char *a=""){
		array=new char [strlen(a)+1];
		strcpy(array,a);
	}
	String(const String& obj){
		array=new char [strlen(obj.array)+1];
		strcpy(array,obj.array);
	}
	~String(){
		delete[] array;
	}
	String operator+(const String& obj) const{
		char* temp = new char[strlen(array) +strlen(obj.array)+1];
        strcpy(temp,array);
        strcat(temp,obj.array);
        String result(temp);
        delete[] temp;
        return result;
	}
	bool operator==(const String& obj){
        return strcmp(array,obj.array)==0;
    }
    void display(){
        cout << array<< endl;
    }
};

int main(){
	String s1("Muhammad"),s2("Wasil");
	String concat=s1+s2;
	cout << "Concatenated String: "; concat.display();
	if (s1 ==s2){
        cout << "Strings are Equal: Yes"<<endl;
    }else{
        cout << "Strings are Equal: No"<<endl;
    }
    return 0;
}
