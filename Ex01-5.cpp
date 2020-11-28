/*
	One Away: There are three types of edits that can be performed on strings: insert a character,
remove a character, or replace a character. Given two strings, write a function to check if they are
one edit (or zero edits) away.
	*/

#include <iostream>
#include <unordered_set>
#include <set>
#include <stdbool.h>
#include <algorithm>

using namespace std;

class Ex01_5 {
private:

	bool isOneReplacementAway(string& str1, string& str2) {
		bool replaceCount = false;			// track if we already saw a candidiate for replacement

		// Iterate through both screens and look for replacement candidates
		for (int i = 0; i < str1.length(); i++) {
			// Find a replacement index
			if (str1[i] != str2[i]) {
				// check if replacement candidate has already been seen and return false if seen already
				if (replaceCount == true) { return false; }
				replaceCount = true;
			}
		}
		return true;						// Return true if no replacement or just 1 replacement
	}

	bool isOneInsRepAway(string& str1, string& str2) {
		int idx1 = 0;
		int idx2 = 0;
		int size1 = str1.size();
		int size2 = str2.size();

		// Two-Pointer Technique
		while (idx1 < size1 && idx2 < size2)
		{
			// If same characters , incrment both pointers
			if (str1[idx1] == str2[idx2]) {
				idx1++;
				idx2++;
			}
			// If different characters , increase idx2
			else {
				// But , first check if we have already seen such a case before , if yes , then this is not true
				if (idx1 != idx2) { return false; }
				idx2++;
			}
		}
		return true;
	}

public:

	// Check to see if two strings are atmost one edit away from each other
	bool isOneEditAway(string& str1, string& str2) {
		int size1 = str1.size();
		int size2 = str2.size();

		// Check for Replacement
		if (size1 == size2) {
			return isOneReplacementAway(str1, str2);
		}
		// Check for insertion
		else if (size1 < size2) {
			return isOneInsRepAway(str1, str2);
		}
		// Check for deletion , since logic for insertion and deletion is same , except for which string is smaller , we can exchange the strings in the function above to get our answer for deletion
		else if (size1 > size2) {
			return isOneInsRepAway(str2, str1);
		}
		return false;				// Return true by default
	}
};

int main() {
	Ex01_5 solution;

	string str1 = "Milind Singh";
	string str2 = "Milind Singh";

	cout << (solution.isOneEditAway(str1, str2) ? "true" : "false");
	cin.get();
	return 0;
}