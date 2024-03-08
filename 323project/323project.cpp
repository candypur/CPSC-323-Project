#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>
using namespace std;

int main() {
	string text;

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
		// Skip comment lines
		if (text[0] == '#' || (text[0] == '/' && text[1] == '/')) continue;
		cout << text << endl;
		
		// Used regex to remove whitespaces
		text = std::regex_replace(text, std::regex("\\s+"), "");
		cout << text << endl;

		// Find certain strings and sort them into the
		// corresponding vectors

		// Regular expressions ? (regex)


	}

	// Close File
	ReadFile.close();



	// Output - unfinished
	cout << "\nOutput 1 - Code after removing excess space & comments:" << endl;


	cout << "Output 2 - Tokenized code:" << endl;

	return 0;

}