#include <iostream>
#include <vector>
using namespace std;

class Animal{
    string name;
public:
    Animal(string n):name(n){}
    virtual void makeSound()=0;
};
class Cat:public Animal{
public:
    Cat(string n):Animal(n){}
    void makeSound(){
        cout<<"Meow..."<<endl;
    }
};
class Dog:public Animal{
public:
    Dog(string n):Animal(n){}
    void makeSound(){
        cout<<"Barking..."<<endl;
    }
};
class Cow:public Animal{
public:
    Cow(string n):Animal(n){}
    void makeSound(){
        cout<<"Mooo..."<<endl;
    }
};

int main(){
    vector<Animal*> a;
    a.push_back(new Cat("Tom"));
    a.push_back(new Dog("Dog1"));
    a.push_back(new Cow("Cow1"));
    a.push_back(new Dog("Dog2"));

    for(Animal* animal:a){
        animal->makeSound();
    }
    for(Animal* animal:a){
        delete animal;
    }
    return 0;
}
