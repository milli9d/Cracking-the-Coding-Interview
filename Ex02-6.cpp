/*
	2.6 Palindrome: Implement a function to check if a linked list is a palindrome

*/

#include <iostream>
#include <stack>
#include <string>
#include "LinkedList.h"

using std::cout;
using std::endl;
using std::stack;
using std::string;

class EX_02_06 {
public:
	EX_02_06() {
	}

	// Using Extra Storage
	template<typename T>
	static bool isPalindromeList(LinkedList<T>& list) {
		// Get number of elements
		size_t count = list.getSize() + 1;
		size_t half = count / 2;

		// Stack to track half list elements
		stack<T> track;
		LinkedList<T>::Iterator runPtr = list.begin();
		// Push into stack
		while (half-- > 0) {
			track.push(runPtr->val);
			runPtr++;
		}

		// Adjust for odd elements
		if (count % 2 == 1) { runPtr++; }

		// Now we are at half point , pop from stack and keep reading list , if any value is a mismatch then break
		while (runPtr != list.end()) {
			T val = track.top();
			if (val != runPtr->val) { return false; }
			runPtr++;
			track.pop();
		}
		return true;
	}

	// Using Reverse List O(n) time
	template<typename T>
	static bool isPalindromeList2(LinkedList<T>& list) {
		// Make a copy list
		LinkedList<T> reverseList = list;
		// Reverse the copy
		reverseList.reverse();

		LinkedList<T>::Iterator listItr = list.begin();
		LinkedList<T>::Iterator reverseListItr = reverseList.begin();
		// Compare the copies , if mismatch then throw false
		while (listItr != list.end() && reverseListItr != reverseList.end()) {
			if ((listItr++)->val != (reverseListItr++)->val) { return false; }
		}
		return true;
	}
};

//int main() {
//	LinkedList<string> pal;
//	pal.append("Hello");
//	pal.append("HI");
//	pal.append("Bye");
//	pal.append("HI");
//	pal.append("Hello");
//	pal.printList();
//
//	cout << (EX_02_06::isPalindromeList<string>(pal) ? "True" : "False") << endl;
//	cout << (EX_02_06::isPalindromeList2<string>(pal) ? "True" : "False") << endl;
//
//	return 0;
//}