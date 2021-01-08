/*
	Remove Dups! Write code to remove duplicates from an unsorted linked list.
	FOLLOW UP
	How would you solve this problem if a temporary buffer is not allowed?
	Hints: #9,#40

*/

#include <iostream>
#include <unordered_set>
#include "LinkedList.h"

using std::unordered_set;

class EX_02_01
{
private:
	LinkedList<int> mData;

public:
	EX_02_01() {
		mData.generateRandom(30, 10);
		mData.printList();
	}

	/*
		Remove duplicates using Hash Set to track visited nodes
		This takes O(n) time and O(n) space
	*/
	void removeDups() {
		unordered_set<int> tracker;
		LinkedList<int>::ListNode* runPtr = mData.getHead();
		LinkedList<int>::ListNode* delPtr = runPtr;
		// Look for element value in Hash Set , if you find it then delete it from list
		while (runPtr != NULL)
		{
			if (tracker.find(runPtr->val) != tracker.end()) {
				delPtr = runPtr;
				runPtr = runPtr->next;
				mData.deleteNode(delPtr);
			}
			// Else insert it into Tracker
			else {
				tracker.insert(runPtr->val);
				runPtr = runPtr->next;
			}
		}
		mData.printList();
	}
};

//int main() {
//	EX_02_01 solution;
//	solution.removeDups();
//	return 0;
//}