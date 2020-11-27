/*
	1.2 Check Permutation: Given two strings, write a method to decide if one is a permutation of the
other.
Hints: #7, #84, #722, #737
	*/

#include <iostream>
#include <unordered_set>
#include <set>
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
		// Boundary Check
		if (str1.size() != str2.size()) {
			return false;
		}

		// Store characters of first string in hashmap
		unordered_multiset<char> str1Map(str1.begin(), str1.end());

		// Go through second string
		for (auto ch : str2) {
			// If char not found in map , return False
			if (str1Map.find(ch) == str1Map.end()) {
				return false;
			}
			// If found then remove one count from map
			else {
				str1Map.erase(str1Map.find(ch));
			}
		}

		// Check to see if all values in map have been removed , only then it is a permutaution
		if (str1Map.empty()) {
			return true;
		}
		else return false;			// Return false by default
	}
};

int main() {
	Ex02_hash solution;

	string str1 = "aab";
	string str2 = "baa";

	cout << (solution.isPermutation(str1, str2) ? "true" : "false");

	return 0;
}