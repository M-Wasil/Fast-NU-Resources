#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ofstream file("backup_log.txt", ios::app);
    if (!file){
        cout << "Could not open file!" << endl;
        return 1;
    }
    string logMessage;
    while (true){
        cout << "Enter log message (or 'exit' to stop): ";
        getline(cin, logMessage);
        if (logMessage == "exit")
            break;
        file << logMessage << endl;
        streampos currentSize = file.tellp();
        cout << "Current file size: " << currentSize << " bytes" << endl;
    }
    file.close();
    return 0;
}

