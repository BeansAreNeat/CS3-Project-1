#include <iostream>
#include <fstream>
#include <string>
using namespace std;

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
			for (int i = 0; i < minLength; i++) {
				if (text1[i] != text2[i]) {
					int offSet = file2Name.length() + 2 + lineCount + i;
					cout << file1Name << ": " << lineCount << ": " << text1 << endl;
					cout << file2Name << ": " << lineCount << ": " << text2 << endl;
					cout << string(offSet, ' ') << "^" << endl;
					break;
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