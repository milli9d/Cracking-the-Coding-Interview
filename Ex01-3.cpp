/*
	URLify
	*/

#include <iostream>
#include <unordered_set>

using namespace std;

class Ex03 {
public:
	// Check if string is all unique
	bool URLify(string& str, int trueLen) {
		int size = str.size();

		//  Corner Case
		if (size == 0) {
			return false;
		}

		int countspc = 0;

		// Count number of spaces
		for (int i = 0; i < trueLen; i++) {
			if (str[i] == ' ') {
				countspc++;
			}
		}

		// Check if enough space
		if ((size - trueLen) < (countspc * 2)) {
			return false;
		}

		// Start at end of string + spaces , last char in array
		int idx = trueLen + (countspc * 2) - 1;

		for (int i = trueLen - 1; i >= 0; i--) {
			// Place %20 in-place of all spaces
			if (str[i] == ' ') {
				str[(size_t)idx - 0] = '0';
				str[(size_t)idx - 1] = '2';
				str[(size_t)idx - 2] = '%';
				idx -= 3;
			}
			// Move curr char to end of array i.e. last idx position
			else {
				str[idx] = str[i];
				idx--;
			}
		}
		return true;
	}
};

//int main() {
//	Ex03 s;
//
//	string str = "Milind is a fast coder   ";
//	int len = str.find_last_not_of(' ') + 1;
//	cout << (s.URLify(str, len) ? str : "Invalid Size") << endl;
//
//	cin.get();
//	return 0;
//}