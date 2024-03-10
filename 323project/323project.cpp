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
	// these will be done in pairs, ex: <"[", "separator">
	vector<pair<string,string>> lexemes;

	// doesn't contain all keywords yet, just the more basic ones
	vector<string> keywords		{"char", "bool", "int", "float", "double", "void", "for",
								"while", "if", "return", "def"};
	vector<string> delimiters	{"(", ")", "{", "}", "[", "]", ";", "<", ">", ":"};
	vector<string> operators	{"+", "-", "++", "--", "*", "/", "%", "=", "=="};


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
		text = regex_replace(text, regex("\\s+"), " ");
		cout << text << endl;

		// separates and stores the strings into a vector by spaces (INCOMPLETE)
		vector<string> curr_line;
		stringstream curr(text);
		string temp;
		while (curr >> temp) {
			curr_line.push_back(temp);
		}
		cout << "Separated: ";
		for (int i = 0; i < curr_line.size(); i++) {
			cout << curr_line[i];
			if (i != curr_line.size()-1) 
				cout << " | ";
		}
		cout << endl << endl;

		// finds first word, finds if its a keyword from vector, stores in vector
		// this is more focused on 323example.txt
		if (find(keywords.begin(), keywords.end(), curr_line[0]) != keywords.end()) {
			lexemes.push_back(make_pair(curr_line[0], "keyword"));
			count++;
		}

		// check if last character of last element is separator
		string last = curr_line.back();
		last = last.back();
		if (find(delimiters.begin(), delimiters.end(), last) != delimiters.end()) {
			lexemes.push_back(make_pair(last, "delimiter"));
			count++;
		}

	}

	// Close File
	ReadFile.close();

	// Outputs - (need to delete duplicates)
	cout << "\nOutput 2 - Tokenized code:\n" << endl;
	cout << setw(13) << left << "Category" << setw(8) << left << "Tokens" << endl
		 << setw(13) << left << "Keywords";
	for (int i = 0; i < lexemes.size(); i++) {
		if (lexemes[i].second == "keyword") {
			cout << lexemes[i].first << " ";
		}
	}
	cout << endl << setw(13) << left << "Identifiers";
	for (int i = 0; i < lexemes.size(); i++) {
		if (lexemes[i].second == "identifier")
			cout << lexemes[i].first << " ";
	}
	cout << endl << setw(13) << left << "Operators";
	for (int i = 0; i < lexemes.size(); i++) {
		if (lexemes[i].second == "operator")
			cout << lexemes[i].first << " ";
	}
	cout << endl << setw(13) << left << "Delimiters";
	for (int i = 0; i < lexemes.size(); i++) {
		if (lexemes[i].second == "delimiter")
			cout << lexemes[i].first << " ";
	}
	cout << endl << setw(13) << left << "Literals";
	for (int i = 0; i < lexemes.size(); i++) {
		if (lexemes[i].second == "literals")
			cout << lexemes[i].first << " ";
	}

	cout << "\n\nTotal Token Count: " << count << endl;

	return 0;
}