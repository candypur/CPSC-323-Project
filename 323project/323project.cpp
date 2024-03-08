#include <iostream>
#include <fstream>
using namespace std;

int main() {
	string text;
	ifstream ReadFile("323example.txt");

	if (!ReadFile) {
		cerr << "Unable to open file 323example.txt" << endl;
		return 1;
	}

	while (getline(ReadFile, text)) {
		cout << text << endl;
		}

		ReadFile.close();
		return 0;
	}