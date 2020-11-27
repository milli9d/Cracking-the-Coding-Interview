/*
	1.1 Is Unique : Implement an algorithm to determine if a string has all unique characters.What if you
cannot use additional data structures ?
	Hints : #44, #7 77, #732
	*/

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
	// Check if string is all unique
	bool hasAllUnique(string& str) {
		//  Corner Case
		if (str.size() == 0) {
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

int main() {
	Solution s;

	string str = "";
	cout << (s.hasAllUnique(str) ? "true" : "false");

	return 0;
}