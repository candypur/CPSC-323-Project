#include <iostream>
#include <fstream>
using namespace std;

int main() {
	string text;
	ifstream ReadFile("323example.txt");

	// vectors used to sort tokens into their categories
	vector<string> keywords, identifiers, literals, 
				 operators, delimiters, whitespace;


	/*
	 You can use "323example.txt" or "323example2.txt"

	 "323example2.txt" is the same as the one provided in
	 the project file, "323example.txt" is more complicated
	*/ 
	ifstream ReadFile("323example2.txt");

	if (!ReadFile) {
		cerr << "Unable to open file 323example.txt" << endl;
		return 1;
	}

	// receive text from file
	while (getline(ReadFile, text)) {
		cout << text << endl;
		}

		ReadFile.close();
		return 0;
	}