#include <iostream>
using namespace std;

class Ghost{
protected:
    string workerName;
    int scareLevel;
public:
    Ghost(string n, int s) : workerName(n), scareLevel(s) {}
    virtual ~Ghost() {}
    virtual void scare(){
        cout << "Ghost is haunting..." << endl;
    }
    string getName(){
        return workerName;
    }
    int getScare(){
        return scareLevel;
    }
    friend ostream& operator<<(ostream& os, const Ghost& obj);
    Ghost operator+(const Ghost& obj) const{
        return Ghost(workerName + " & "+obj.workerName,scareLevel +obj.scareLevel);
    }
};

class Poltergeists :public virtual Ghost{
public:
    Poltergeists(string n, int s) :Ghost(n, s){}
    void scare(){
        cout << "Moving Objects..." <<endl;
    }
};

class Banshees :public Ghost{
public:
    Banshees(string n, int s) : Ghost(n, s){}
    void scare(){
        cout << "Screaming loudly..." <<endl;
    }
};

class ShadowGhosts :public virtual Ghost{
public:
    ShadowGhosts(string n, int s) :Ghost(n, s){}
    void scare(){
        cout << "Whispering creepily..." <<endl;
    }
};
class ShadowPoltergeist :public Poltergeists,public ShadowGhosts{
public:
    ShadowPoltergeist(string n, int s):Ghost(n, s), Poltergeists(n, s),ShadowGhosts(n, s){}
    void scare(){
        cout << "Moving Objects and Whispering creepily..." <<endl;
    }
};
ostream& operator<<(ostream& os, const Ghost& obj){
    os << "Name: " <<obj.workerName << ", Scare Level: " <<obj.scareLevel;
    return os;
}
class HauntedHouse{
    string name;
    Ghost** ghosts;
    int ghostCount;
    int ghostCapacity;
public:
    HauntedHouse(string n) :name(n), ghostCount(0), ghostCapacity(10){
        ghosts = new Ghost*[ghostCapacity];
    }
    
    void addGhost(Ghost* ghost){
        if (ghostCount == ghostCapacity){
            int newCapacity = ghostCapacity * 2;
            Ghost** newGhosts = new Ghost*[newCapacity];
            for (int i =0;i <ghostCount; i++){
                newGhosts[i] =ghosts[i];
            }
            delete[] ghosts;
            ghosts =newGhosts;
            ghostCapacity =newCapacity;
        }
        ghosts[ghostCount++] =ghost;
    }
    
    void showGhosts(){
        cout << "Ghosts in " << name << ":" << endl;
        for (int i = 0; i < ghostCount; i++){
            cout << *ghosts[i] << endl;
        }
    }
    
    friend void visit(HauntedHouse &house,class Visitor visitors[],int numVisitors);
    Ghost** getGhosts() { return ghosts; }
    int getGhostCount() { return ghostCount; }
    ~HauntedHouse() {
        for (int i =0;i <ghostCount;i++){
            delete ghosts[i];
        }
        delete[] ghosts;
    }
};

class Visitor{
    string vName;
    int bravery;
public:
    Visitor(string name, int b) :vName(name), bravery(b) {}
    string getName(){
        return vName; 
    }
    int getBravery(){
        return bravery;
    }
};

void visit(HauntedHouse &house, Visitor visitors[], int numVisitors){
    int low, high;
    cout << "Visitors arriving at " <<house.name << "..." <<endl;
    for (int i =0; i<numVisitors;i++){
        cout << visitors[i].getName()<< " enters " << house.name <<"..." <<endl;
        for (int j= 0; j <house.ghostCount; j++){
            house.ghosts[j]->scare();
        }
        int bravery =visitors[i].getBravery();
        if (bravery <5){
            low=1;
            high=4;
        }else if (bravery <8){
            low=5;
            high=7;
        }else{
            low=8;
            high=10;
        }

        cout << visitors[i].getName() << "'s reactions:" <<endl;
        for (int j = 0; j <house.ghostCount; j++){
            int ghostScare = house.ghosts[j]->getScare();
            if (ghostScare < low)
                cout <<visitors[i].getName()<<" laughs at " <<house.ghosts[j]->getName() <<endl;
            else if (ghostScare > high)
                cout <<visitors[i].getName()<<" screams at " <<house.ghosts[j]->getName() <<endl;
            else
                cout <<visitors[i].getName()<<" gets a shaky voice at " <<house.ghosts[j]->getName() <<endl;
        }
        cout << endl;
    }
}

int main() {
    HauntedHouse h1("Haunted House 1");
    HauntedHouse h2("Haunted House 2");
    h1.addGhost(new Poltergeists("Poltergeist", 3));
    h1.addGhost(new Banshees("Banshee", 6));
    h1.addGhost(new ShadowGhosts("Shadow", 8));
    h1.addGhost(new ShadowPoltergeist("ShadowPoltergeist", 7));
    h2.addGhost(new Poltergeists("Poltergeist", 4));
    h2.addGhost(new Banshees("Banshee", 5));
    h2.addGhost(new ShadowGhosts("Shadow", 9));

    h1.showGhosts();
    h2.showGhosts();

    Ghost* upgradedGhost = new Ghost(*h2.getGhosts()[0] + *h2.getGhosts()[1]);
    cout << "Upgraded Ghost Created: " << *upgradedGhost << endl;
    h2.addGhost(upgradedGhost);
    
    Visitor visitors[]={
        Visitor("Wasil", 8),
        Visitor("Hussnain", 5),
        Visitor("Saad", 4)
    };
    int num=sizeof(visitors) / sizeof(visitors[0]);
    
    visit(h1,visitors,num);
    visit(h2,visitors,num);

    return 0;
}
