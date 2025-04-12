#include<iostream>
#include<string>
using namespace std;
class MusicSession{
	private:
		string title;
		string artist;
		int duration;
		static int totalSongsPlayed;
	public:
		MusicSession(string titl,string artis,int durat):title(titl),artist(artis),duration(durat){
			totalSongsPlayed++;
		}
		static void displaySongs(){
			cout<<"Total songs played "<<totalSongsPlayed;
		}
		void display(){
			cout<<"Playing: "<<title<<" by "<<artist<<" ["<<duration<<"s]"<<endl;
		}

};

int MusicSession::totalSongsPlayed=0;

int main(){
	MusicSession m1("Shape of You","ED Sheeran",210);
	MusicSession m2("Blinding Lights","The Weeknd",200);
	MusicSession m3("Shape of You","Ed Sheeran",210);
	m1.display();
	m2.display();
	m3.display();
	MusicSession::displaySongs();
	
}