/*
	1.1 Is Unique : Implement an algorithm to determine if a string has all unique characters.What if you
cannot use additional data structures ?
	Hints : #44, #7 77, #732
	*/

#include <iostream>
#include <unordered_set>

using namespace std;

class Ex01_HashSet {
public:
	// Check if string is all unique
	bool hasAllUnique(string& str) {
		//  Corner Case
		if (str.size() > 256) {
			return false;
		}

		// Hashmap to store characters already seen
		unordered_set<char> mData;

		// Iterate through all chars
		for (char ch : str) {
			// Check if previously seen
			// If Yes , them return false
			if (mData.find(ch) != mData.end()) {
				return false;
			}

			else {
				// If Not then add to set
				mData.insert(ch);
			}
		}
		return true;
	}
};

class Ex01_array {
public:
	// Check if string is all unique
	bool hasAllUnique(string& str) {
		if (str.size() > 256) {
			return false;
		}

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
//	Ex01_array s;
//
//	string str = "";
//	cout << (s.hasAllUnique(str) ? "true" : "false");
//
//	return 0;
//}