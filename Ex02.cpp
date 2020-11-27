/*
	1.2 Check Permutation: Given two strings, write a method to decide if one is a permutation of the
other.
Hints: #7, #84, #722, #737
	*/

#include <iostream>
#include <unordered_set>
#include <stdbool.h>
#include <algorithm>

using namespace std;

class Ex02_sort {
public:
	bool isPermutation(string& str1, string& str2) {
		//  Sort both strings and compare
		sort(str1.begin(), str1.end());				// O(logN)
		sort(str2.begin(), str2.end());				// O(logN)

		if (str1._Equal(str2)) {
			return true;
		}

		return false;				// Return true by default
	}
};

class Ex02_hash {
public:
	bool isPermutation(string& str1, string& str2) {
		//

		return true;				// Return true by default
	}
};

int main() {
	Ex02_hash solution;

	string str1 = "Milind Singh";
	string str2 = "Singh   Milind";

	cout << (solution.isPermutation(str1, str2) ? "true" : "false");

	return 0;
}