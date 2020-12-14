/*
	String Compression: Implement a method to perform basic string compression using the counts
	of repeated characters. For example, the string aabcccccaaa would become a2blc5a3. If the
	"compressed" string would not become smaller than the original string, your method should return
	the original string. You can assume the string has only uppercase and lowercase letters (a - z).
	Hints:#92, #110
*/

#include <iostream>
#include <string>
#include <stdbool.h>

using namespace std;

class EX_01_6 {
private:

public:
	void stringCompress(string& str) {
		if (str.length() <= 1) {
			return;
		}
		string temp = "";

		// Start with first character already seen
		char lastUniqueChar = str[0];
		int count = 0;
		// End at terminal character for completion of algorithm
		for (int i = 0; i <= str.length(); i++) {
			// If same then keep counting
			if (str[i] == lastUniqueChar) {
				count++;
			}
			// When different push into new string and reset count
			else {
				temp += lastUniqueChar + to_string(count);
				count = 1;
				lastUniqueChar = str[i];
			}
		}
		if (temp.length() < str.length()) {
			str = temp;
		}
	}
};

//int main(int argc, char** argv) {
//	EX_01_6 solution;
//	string test = "aaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbcccccccccccccccccccccccccaddd";
//	solution.stringCompress(test);
//	cout << test;
//
//	return 0;
//}