#include <iostream>
#include <string>
using namespace std;

template <typename T1, typename T2>
class Pair{
public:
    T1 a;
    T2 b;

    Pair(T1 x, T2 y){
    	a=x;
	    b=y;
	}
    void display(){
        cout << "Pair: <" << a << ", " << b << ">" << endl;
    }
};
int main() {
    Pair<int, string> p(140, "Wasil"); 
    p.display();
}

