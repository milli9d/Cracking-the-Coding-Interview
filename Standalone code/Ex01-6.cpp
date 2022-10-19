/*
	String Compression: Implement a method to perform basic string compression using the counts
	of repeated characters. For example, the string aabcccccaaa would become a2blc5a3. If the
	"compressed" string would not become smaller than the original string, your method should return
	the original string. You can assume the string has only uppercase and lowercase letters (a - z).
	Hints:#92, #110
*/

#include <iostream>
#include <string>
#include <unordered_set>
#include <stdbool.h>

using namespace std;

class EX_01_6 {
private:
	// Optimisation , calculate if compression will result in smaller string or not
	int calcCompressedLength(string& str) {
		char lastChar = '\0';
		int countUniqueAppearances = 0;
		// Find how many unique characters occur in the string
		for (int i = 0; i < str.length(); i++) {
			if (str[i] != lastChar) {
				countUniqueAppearances++;
				lastChar = str[i];
			}
		}
		// Compressed length will be double of this count
		return countUniqueAppearances * 2;
	}

public:
	void stringCompress(string& str) {
		if (str.length() <= 1) {
			return;
		}
		// Compare Compressed Length to original , return if more or equal
		int compressedLength = calcCompressedLength(str);
		if (compressedLength > str.length()) { return; }

		// Optimisation : Reserve the whole string length to eliminate copying
		string temp = "";
		temp.reserve(compressedLength);

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
		// Replace string with generated compressed string
		str = temp;
	}
};

//int main(int argc, char** argv) {
//	EX_01_6 solution;
//	string test = "aaaaaaaaaabbbbbbbbbbbbbbbbbbbbccccccccccccccc";
//	solution.stringCompress(test);
//	cout << test;
//	return 0;
//}