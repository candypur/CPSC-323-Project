#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>
#include <iomanip>
using namespace std;

int main() {
	string text;
	int count = 0;
	// vectors used to sort tokens into their categories
	// these will be done in pairs, ex: <'[', separator>
	vector<pair<string,string>> lexemes;

	// doesn't contain all keywords yet, just the more basic ones
	vector<string> keywords{"char", "bool", "int", "float", "double", "void", "for",
							"while", "if", "return"};


	/*
	 You can use "323example.txt" or "323example2.txt"

	 "323example2.txt" is the same as the one provided in
	 the project file, "323example.txt" is more complicated
	*/
	ifstream ReadFile("323example.txt");

	if (!ReadFile) {
		cerr << "Unable to open file 323example.txt" << endl;
		return 1;
	}

	cout << "Output 1 - Code after removing excess space & comments:\n" << endl;

	// receive text from file
	while (getline(ReadFile, text)) {
		// Skip comment lines
		if (text[0] == '#' || (text[0] == '/')) continue;
		// Used regex to remove whitespaces
		text = std::regex_replace(text, std::regex("\\s+"), " ");
		cout << text << endl;

		// finds first word, finds if its a keyword from vector, stores in vector
		// this is more focused on 323example.txt
		string word = text.substr(0, text.find(" "));
		if (find(keywords.begin(), keywords.end(), word) != keywords.end()) {
			lexemes.push_back(make_pair(word, "keyword"));
			count++;
		}

		
		// Find certain strings and sort them into the lexeme
		// vector, matching them with what token they are

		// Regular expressions ? (regex)


	}

	// Close File
	ReadFile.close();


	cout << "\nOutput 2 - Tokenized code:\n" << endl;

	for (int i = 0; i < lexemes.size(); i++) {
		cout << std::setw(8) << lexemes[i].first << std::setw(8) 
			 << lexemes[i].second << std::setw(5) << i+1 << endl;
	}
	cout << "\nTotal Token Count: " << count << endl;

	return 0;

}