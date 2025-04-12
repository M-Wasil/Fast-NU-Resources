#include <iostream>
using namespace std;
class Subject{
	string subjName;
public:
	Subject(string n=""):subjName(n){}
	string getName() const{
        return subjName;
    }
};
class Professor{
	string name;
	Subject* s[3];
	int count;
public:
	Professor(string n):name(n),count(0) {}
	void assign(Subject* sub){
		if (count<3){
            s[count]=sub;
            count++;
        }else{
            cout <<"Cannot assign more subjects. Limit reached." << endl;
        }
	}
	void display() const{
		cout <<"Mr. "<<name<<" teaches: "<<endl;
		for (int i =0;i <count;i++){
            cout << "- " << s[i]->getName() << endl;
        }
	}
	
};
int main(){
	Professor p1("Wasil");
	Subject s1("DLD");
	Subject s2("Maths");
	Subject s3("Physics");
	p1.assign(&s1);
	p1.assign(&s2);
	p1.assign(&s3);
	p1.display();
	return 0;
}
