#include <iostream>
using namespace std;
class Movie{
	private :
	string name;
	int seats;
	double price;
	public :
		Movie(string m,int s,double p){
			name=m;
			seats=s;
			price=p;
			cout<<"movie: "<<name<<" is now available for booking!"<<endl;
		}
		void book(int s){
			seats-=s;
			cout<<s<<" tickets booked for "<<name<<" | remaining seats: "<<seats<<endl;
		}
		void dispaly(){
			cout<<"Movie: "<<name<<" | Available seats: "<<seats<<" | Ticket price: $"<<price<<endl;
		}
		~Movie(){
			cout<<"Movie booking closed: "<<name<<endl;
		}
};
int main(){
	Movie m1("Avengers",50,10);
	m1.book(5);	
    m1.dispaly();

}
