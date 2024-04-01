#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>
#include <iomanip>
#include <sstream>
#include <set>
using namespace std;

int main() {
	string text;
	int count = 0;
	// vectors used to sort tokens into their categories
	// these will be done in pairs, ex: <"[", "separator">
	// vector<pair<string, string>> lexemes;

	// doesn't contain all keywords yet, just the more basic ones
	vector<string> keywords{ "char", "bool", "int", "float", "double", "void", "for",
								"while", "if", "return", "def" };
	// vector<string> delimiters{ "(", ")", "{", "}", "[", "]", ";", "<", ">", ":" };
	vector<string> operators{ "+", "-", "++", "--", "*", "/", "%", "=", "==", "<<"};
	vector<string> identifier{ "calculate_sum", "a", "b", "num1", "num2", "cout", "endl", "main", "result" };

	//Creating empty sets to hold tokens
	set<string> keywordsSet;
	set<string> identifiersSet;
	set<string> operatorsSet;
	set<string> delimitersSet;
	set<string> literalsSet;


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

		//Regex object that matches strings with 10, 20, or 0
		std::regex number_regex("10|20|0");
		//Regex object that matches strings with "Sum:"
		std::regex string_regex("Sum: ");
		//Regex object that matches delimiters
		std::regex delimiter_regex("\\(|\\)|\\{|\\}|\\[|\\]|;|<|>|,|");

		//Adds a space if any of these characters are found so they can be tokenized also separates from other lexemes
		text = regex_replace(text, regex(";"), " ; ");
		text = regex_replace(text, regex("\\("), " ( ");
		text = regex_replace(text, regex("\\)"), " ) ");
		text = regex_replace(text, regex("\\,"), " ,");

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
            if (i != curr_line.size() - 1) {
                // Add condition to check if the current token is not equal to "\"Sum:"
                if (curr_line[i] != "\"Sum:") {
                    cout << " | ";
                }
            }
        }
        cout << endl << endl;


		/* finds first word, finds if its a keyword from vector, stores in vector
		this is more focused on 323example.txt

		if (find(keywords.begin(), keywords.end(), curr_line[0]) != keywords.end()) {
		lexemes.push_back(make_pair(curr_line[0], "keyword"));
		count++;

		 Moved this into ranged based loop underneath */

		 // Goes through all tokens in curr_line, classifies each one
		for (string& text : curr_line) {
			// Checks for keywords
			if (find(keywords.begin(), keywords.end(), text) != keywords.end()) {
				// Adds any keywords into keywords set
				keywordsSet.insert(text);
				//lexemes.push_back(make_pair(text, "keyword"));
				count++;
			}
			// Checks for identifiers
			if (find(identifier.begin(), identifier.end(), text) != identifier.end()) {
				// Adds any identifiers into identifier set
				identifiersSet.insert(text);
				//lexemes.push_back(make_pair(text, "identifier"));
				count++;
			}

			// Checks for operators
			if (find(operators.begin(), operators.end(), text) != operators.end()) {
				// Adds any operators to operator set
				operatorsSet.insert(text);
				//lexemes.push_back(make_pair(text, "operator"));
				count++;

			}
			//Finds delimiters
			if (regex_match(text, delimiter_regex)) {
				//Adds last to delimiters set
				delimitersSet.insert(text);
				//lexemes.push_back(make_pair(last, "delimiter"));
				count++;
			}

			//Finds string literals (incomplete)
			if (regex_search(text, string_regex)) {
				literalsSet.insert(text);
				//lexemes.push_back(make_pair(text, "literals"));
				count++;
			}
			//Finds numeric literals
			if (regex_search(text, number_regex)) {
				//lexemes.push_back(make_pair(text, "literals"));
				literalsSet.insert(text);
				count++;
			}
		}

		/* check if last character of last element is separator
		string last = curr_line.back();
		last = last.back();
		if (find(delimiters.begin(), delimiters.end(), last) != delimiters.end()) {
			//Adds last to delimiters set
			delimitersSet.insert(last);
			//lexemes.push_back(make_pair(last, "delimiter"));
			count++;
		} */

	}

	// Close File
	ReadFile.close();

	// Outputs - (need to delete duplicates) <- Solved?
	cout << "\nOutput 2 - Tokenized code:\n" << endl;
	cout << setw(13) << left << "Category" << setw(8) << left << "Tokens" << endl
		<< setw(13) << left << "Keywords";
	for (const auto& keyword : keywordsSet) {
		cout << keyword << " ";
	}
	cout << endl << setw(13) << left << "Identifiers";
	for (const auto& identifier : identifiersSet) {
		cout << identifier << " ";
	}
	cout << endl << setw(13) << left << "Operators";
	for (const auto& operators : operatorsSet) {
		cout << operators << " ";
	}
	cout << endl << setw(13) << left << "Delimiters";
	for (const auto& delimiter : delimitersSet) {
		cout << delimiter << " ";
	}
	cout << endl << setw(13) << left << "Literals";
	for (const auto& literal : literalsSet) {
		cout << literal << " ";
	}

	cout << "\n\nTotal Token Count: " << count << endl;

	return 0;
}