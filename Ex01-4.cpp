/*
Palindrome Permutation: Given a string, write a function to check if it is a permutation of a palindrome. A palindrome is a word or phrase that is the same forwards and backwards. A permutation
is a rearrangement of letters. The palindrome does not need to be limited tojust dictionary words.
	*/

#include <iostream>
#include <unordered_set>
#include <bitset>
#include <sstream>

using namespace std;

class msUtil {
private:

public:
	vector<string> stringGen(int maxLen, int num) {
		// Output in vector of strings
		vector<string> out;

		// Make a random number generator
		srand(time(0));

		// Loop n times
		for (int i = 0; i < num; i++) {
			// Generate length
			int len = rand() % maxLen;
			stringstream ss;
			// Loop through length
			for (int j = 0; j < len; j++) {
				ss << (char)(rand() % 26 + 65);
			}
			out.push_back(ss.str());
		}
		return out;
	}
};

class Ex1_4 {
public:
	bool isPalindromePermutation(string& str) {
		// Means that each character will have a pair , we can easily check for this
		if (str.size() <= 1) { return false; }
		// Make ASCII tracker array
		int tracker[UCHAR_MAX] = { 0 };

		// Go through array and count all occurences
		for (char ch : str) {
			if (isalnum(ch) && ch != ' ') {
				char low = tolower(ch);
				tracker[low]++;
			}
		}
		int oneCount = 0;
		// Go through tracker and find discrepancies
		for (int i : tracker) {
			if (oneCount > 1) { return false; }
			// If count is 1 or not
			if (i == 1) {
				oneCount++;
			}
			// If there is a count which is odd and not 1
			if (i > 1 && i % 2 != 0)
			{
				return false;
			}
		}

		return true;
	}
};

class Ex1_4_array {
public:
	bool isPalindromePermutation(string& str) {
		// Means that each character will have a pair , we can easily check for this
		if (str.size() <= 1) { return false; }
		// Make ASCII tracker array
		bool tracker[UCHAR_MAX] = { 0 };

		int oneCount = 0;
		// Go through array and count all occurences
		for (char ch : str) {
			if (isalnum(ch) && ch != ' ') {
				char low = tolower(ch);
				tracker[low] = !(tracker[low]);
			}
		}
		// Go through tracker and find discrepancies
		for (bool b : tracker) {
			if (b == true) {
				oneCount++;
			}
			if (oneCount > 1) { return false; }
		}

		return true;
	}
};

//int main() {
//	Ex1_4_array s;
//
//	cout << (s.isPalindromePermutation(string("abaab")) ? "true" : "false") << endl;
//
//	cin.get();
//
//	return 0;
//}