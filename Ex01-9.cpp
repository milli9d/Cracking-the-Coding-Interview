/*
	1.9 String Rotation:Assumeyou have a method isSubstringwhich checks if one word is a substring
	of another. Given two strings, sl and s2, write code to check if s2 is a rotation of sl using only one
	call to isSubstring(e.g.,"waterbottle"is a rotation of"erbottlewat").
	Hints:#34,#88, # 704
*/

#include <iostream>
#include <string>

using namespace std;

class EX_01_9 {
private:
	// Find needle in haystack
	bool isSubString(string needle, string haystack) {
		if (needle.length() > haystack.length()) { return false; }
		char firstCharNeedle = needle[0];
		auto ptr = haystack.find(firstCharNeedle);
		while (ptr != string::npos) {
			// Here we have a position where first character of needle occurs
			// Check if rest matches needle
			for (int i = 0; i < needle.length(); i++) {
				char first = haystack[ptr + i];
				char second = needle[i];
				if (first != second) { break; }
				if (first == second && i == needle.length() - 1) {
					return true;
				}
			}
			ptr = haystack.find(firstCharNeedle, ptr + 1);
		}
		return false;
	}

public:

	// This looks similiar to Circular Buffer , must be a way to it by circular buffer method
	bool isStringRotation(string& str1, string& str2) {
		// Sanity Check
		if (str1.size() != str2.size()) { return false; }

		string temp = str1 + str1;

		return isSubString(str2, temp);
	}
};

int main(int argc, char** argv) {
	EX_01_9 solution;
	string str1 = "bottlewater";
	string str2 = "erbottlewet";

	cout << (solution.isStringRotation(str1, str2) ? "True" : "False");

	return 0;
}