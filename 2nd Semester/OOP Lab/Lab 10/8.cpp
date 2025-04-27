#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ifstream file("article.txt");
    if (!file){
        cout << "Could not open file!" << endl;
        return 1;
    }

    file.seekg(0, ios::end);
    int size = file.tellg();
    file.seekg(size/2, ios::beg);

    string dummy;
    getline(file, dummy);
    string line;
    int lineCount = 0;
    while (getline(file, line) && lineCount < 10){
        cout << line << endl;
        lineCount++;
    }

    file.close();
    return 0;
}

