#include <iostream>
using namespace std;
class Movie{
	string title;
	int duration;
public:
	Movie(string t,int d):title(t),duration(d){}
	string getTitle(){
		return title;
	}
	int getDur(){
		return duration;
	}
};
class Cinema{
	Movie* m[3];
	int count;
public:
	Cinema ():count(0){}
	void assign(Movie* mov){
		if (count<3){
            m[count]=mov;
            count++;
        }else{
            cout <<"Cannot assign more movies. Limit reached." << endl;
        }
	}
	void display(){
		cout <<"Currently showing Movies:"<<endl;
		for (int i=0;i<count;i++){
			cout <<"Movie: "<<m[i]->getTitle()<<" | Duration: "<<m[i]->getDur()<<" minutes"<<endl;
		}
	}
};
int main(){
	Cinema c1;
	Movie m1("Inception",148);
	Movie m2("Titanic",195);
	Movie m3("The Dark Knight",152);
	c1.assign(&m1);
	c1.assign(&m2);
	c1.assign(&m3);
	c1.display();
	return 0;
}
