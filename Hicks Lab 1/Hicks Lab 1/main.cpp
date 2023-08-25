#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	string lines1, lines2; // Number linked to each file
	int lineCount = 0;
	ifstream file1("file1.txt");
	ifstream file2("file2.txt");

	if (file1.is_open() && file2.is_open()) {
		while (getline(file1, lines1) && getline(file2, lines2)) {
			lineCount++;
			cout << "file1.txt: " << lines1;

			// Compares lengths of text
			size_t minLength;
			if (lines1.length() < lines2.length())
				minLength = lines1.length();
			else
				minLength = lines2.length();

			for (size_t i = 0; i < minLength; ++i) {
				if (lines1[i] != lines2[i]) {
					cout << "file1.txt: " << lineCount << ": " << lines1 << endl;
					cout << "file2.txt: " << lineCount << ": " << lines2 << endl;
					cout << string(i, ' ') << "^" << endl;
					break;
				}
			}
			file1.close();
			file2.close();
		}
	}
	else {
		std::cout << "Cry about it";
	}
	return 0;
}