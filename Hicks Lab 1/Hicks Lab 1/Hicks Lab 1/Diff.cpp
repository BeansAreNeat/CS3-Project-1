#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void output(string f1N, string f2N, string txt1, string txt2, int lineNum, int i);

int main() {
	string text1, text2;
	string file1Name = "file1.txt";
	string file2Name = "file2.txt";
	int lineCount = 0;
	ifstream file1(file1Name);
	ifstream file2(file2Name);

	if (file1.is_open() && file2.is_open()) {
		// Loops through each line and interates line count
		while (getline(file1, text1) && getline(file2, text2)) {
			++lineCount;
			size_t minLength = min(text1.length(), text2.length());
			for (int i = 0; i < minLength || i < text1.length() || i < text2.length(); i++) {
				if (i < minLength && text1[i] != text2[i]) {
					output(file1Name, file2Name, text1, text2, lineCount, i);
				} else if (i >= text1.length() || i >= text2.length()) {
					output(file1Name, file2Name, text1, text2, lineCount, i);
				}
			}
		}
		file1.close();
		file2.close();
	} else {
		std::cout << "Error";
	}
	std::cout << std::endl;
	return 0;
}

void output(string f1N, string f2N, string txt1, string txt2, int lineNum, int i) {
	int offset = f2N.length() + 4 + to_string(lineNum).length() + i;
	cout << f1N << ": " << lineNum << ": " << txt1 << endl;
	cout << f1N << ": " << lineNum << ": " << txt2 << endl;
	cout << string(offset, ' ') << "^" << endl;
	cout << endl;
}