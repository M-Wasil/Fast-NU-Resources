#include <iostream>
using namespace std;

class Runner{
	string name;
	float speed;
	static const int max=25;
	static const int dis=100;
public:
	Runner (string n,float s):name(n),speed(s) {}
	
	static void winner(Runner r[],int size){
		float t=100000000;
		string win="";
		for (int i=0;i<size;i++){
			if (r[i].speed<=max){
				float time=dis/r[i].speed;
				if (time<t){
					t= time;
                    win =r[i].name;
				}
			}
		}
		cout << "\nWinner of the Marathon: " << win<< endl;
	}
	void display() const{
		cout << "Runner :"<<name<<" | Speed: "<<speed<<endl;
		if (speed>max){
			cout << "(Disqualified: Exceeded Speed Limit)" <<endl;
		}
	}
};
int main(){
	cout << "Max Speed Limit for Marathon: "<<25<<" km/h"<<endl;
	Runner r[]={Runner ("Usain Bolt",27.8),Runner ("Eliud Kipchoge",21.5),Runner ("Mo Farah",24)};
	for (int i =0;i<3;i++){
        r[i].display();
    }
    Runner::winner(r,3);
    return 0;
}
