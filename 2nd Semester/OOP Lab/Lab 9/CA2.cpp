#include <iostream>
using namespace std;

class RemoteControl {
public:
    virtual void changeChannel(int channel)=0;
    virtual void adjustVolume(int volume)=0;
};

class ConcreteRemoteControl :public RemoteControl{
private:
    int currentChannel;
    int currentVolume;
public:
    ConcreteRemoteControl():currentChannel(1),currentVolume(50){}
    void changeChannel(int channel){
        currentChannel=channel;
        cout << "Changed to channel " <<currentChannel<<endl;
    }
    void adjustVolume(int volume){
        currentVolume=volume;
        cout << "Adjusted volume to "<<currentVolume <<endl;
    }
};
int main(){
    ConcreteRemoteControl remote;
    remote.changeChannel(9);
    remote.adjustVolume(40);
    return 0;
}
