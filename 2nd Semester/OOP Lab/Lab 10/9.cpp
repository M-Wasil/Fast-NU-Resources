#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    fstream file("draft.txt", ios::in | ios::out);
    if (!file) {
        cout << "Could not open file!" << endl;
        return 1;
    }

    string line;
    bool corrected = false;
    streampos line_start_pos = 0;
    while (getline(file, line) && !corrected) {
        size_t found = line.find("teh");
        if (found != string::npos) {
            file.clear();
            streampos typo_pos = line_start_pos + static_cast<streampos>(found);
            file.seekp(typo_pos);
            file << "the";
            corrected = true;
            file.flush();
        }
        line_start_pos = file.tellg();
    }
    
    file.close();
    
    if (corrected)
        cout << "First typo corrected!" << endl;
    else
        cout << "No typo found." << endl;
    
    return 0;
}
