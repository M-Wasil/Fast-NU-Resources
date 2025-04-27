#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){
	ifstream inFile("article.txt");
	if (!inFile){
		cout << "Error: Could not open article.txt" << endl;
		return 1;
	}

	int totalChars = 0, totalWords = 0, totalLines = 0, punctuationMarks = 0;
	string line;
	while (getline(inFile, line)){
		totalLines++;
		totalChars += line.length();
		bool inWord = false;
		for (char c : line){
			if (c == ' ' || c == '\t'){
				if (inWord){
					totalWords++;
					inWord = false;
				}
			}else{
				inWord = true;
				if (c == '.' || c == ',' || c == '!' || c == '?' || c == ';' || c == ':'){
					punctuationMarks++;
				}
			}
		}
		if (inWord){
			totalWords++;
		}
	}

	inFile.close();
	ofstream outFile("report.txt");
	if (!outFile){
		cout << "Error: Could not create report.txt" << endl;
		return 1;
	}
	outFile << "=== Article Stats ===" << endl;
	outFile << "Total characters: " << totalChars << endl;
	outFile << "Total words: " << totalWords << endl;
	outFile << "Total lines: " << totalLines << endl;
	outFile << "Punctuation marks: " << punctuationMarks << endl;

	outFile.close();

	cout << "Report generated successfully!" << endl;
	return 0;
}

