/*
	1.1 Is Unique : Implement an algorithm to determine if a string has all unique characters.What if you
cannot use additional data structures ?
	Hints : #44, #7 77, #732
	*/

#include <iostream>
#include <unordered_set>
#include <stdbool.h>

using namespace std;

class Ex01_array {
public:
	// Check if string is all unique
	bool hasAllUnique(string& str) {
		// Make a tracker array of 256 bools , each bit of this array is a character in ASCII table
		bool tracker[UCHAR_MAX] = { 0 };

		// Isolate a character from String
		for (char ch : str) {
			// See if character flag is set true in tracker , if yes , then return false
			if (tracker[ch] == 1) {
				return false;
			}
			else {
				// If not , then set it true
				tracker[ch] = true;
			}
		}
		return true;				// Return true by default
	}
};

//int main() {
//	Ex01_array solution;
//
//	string str = "Milind Singh";
//	cout << (solution.hasAllUnique(str) ? "true" : "false");
//
//	return 0;
//}