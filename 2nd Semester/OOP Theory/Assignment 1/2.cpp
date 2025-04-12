#include<iostream>
#include<string>
using namespace std;

class Robot{
    string name;
    int hits;
public:
    Robot(string n):name(n),hits(0) {}
    void hitBall(int &ballX, int &ballY,const string &direction){
        if (direction=="up"){
			ballY++;
		}else if(direction=="down"){
			ballY--;
		}else if(direction=="right"){
			ballX++;
		}else if(direction=="left"){
			ballX--;
		}
        hits++;
    }
    int getHits()const{
        return hits;
    }
    string getName()const{
        return name;
    }
};
class Ball{
    int x,y;
public:
    Ball(int x=0,int y=0):x(x),y(y) {}
    void move(int dx,int dy){
        x +=dx;
        y +=dy;
    }
    int getX()const{
        return x;
    }
    int getY()const{
        return y;
    }
};
class Goal{
    int x,y;
public:
    Goal(int x=3,int y=3):x(x),y(y){}
    bool isGoalReached(int ballX, int ballY)const{
        return ballX==x && ballY==y;
    }
};
class Team{
    string name;
    Robot* player;
public:
    Team(string n,Robot* p) : name(n),player(p){}
    string getTeam()const{
        return name;
    }
    Robot* getPlayer()const{
        return player;
    }
};
class Game{
    Team* team1;
    Team* team2;
    Ball ball;
    Goal goal;
public:
    Game(Team* t1,Team* t2) :team1(t1),team2(t2),ball(),goal(){}
    void play(Team* team){
        ball=Ball(0,0);
        Robot* robot=team->getPlayer();
        string direction;
        cout<<"\nTeam "<<team->getTeam()<<"'s turn.Ball is at position (0, 0)."<<endl;
        while(!goal.isGoalReached(ball.getX(),ball.getY())){
            cout<<"Current ball position: ("<<ball.getX()<<", "<<ball.getY()<<"). Enter direction (up/down/right/left): ";
            cin>>direction;
            int ballX=ball.getX(), ballY=ball.getY();
            robot->hitBall(ballX,ballY,direction);
            ball=Ball(ballX,ballY);
        }
        cout<<"Goal reached by team "<<team->getTeam()<<" with "<<robot->getHits()<<" hits!"<<endl;
    }
    void startGame(){
        cout<<"Game started! Both teams begin with the ball at (0, 0)."<<endl;
        play(team1);
        play(team2);
    }
    void declareWinner()const{
        int hits1=team1->getPlayer()->getHits();
        int hits2=team2->getPlayer()->getHits();
        cout<<"\nResults:"<<endl;
        cout<<"Team "<<team1->getTeam()<<" hits: "<<hits1<<endl;
        cout<<"Team "<<team2->getTeam()<<" hits: "<<hits2<<endl;
        
        if(hits1<hits2){
        	cout<<"Team "<<team1->getTeam()<<" wins!"<<endl;
		}else if(hits2<hits1){
			cout<<"Team "<<team2->getTeam()<<" wins!"<<endl;
		}else{
			cout<<"It's a tie!"<<endl;
		}
    }
};

int main(){
    string player1,player2,team1Name,team2Name;
    cout<<"Enter Player 1 name: ";cin>>player1;
    cout<<"Enter Player 2 name: ";cin>>player2;
    cout<<"Enter Team 1 name: ";cin>>team1Name;
    cout<<"Enter Team 2 name: ";cin>>team2Name;
    
    Robot r1(player1),r2(player2);
    Team t1(team1Name,&r1),t2(team2Name,&r2);
    
    Game game(&t1,&t2);
    game.startGame();
    game.declareWinner();
    return 0;
}
