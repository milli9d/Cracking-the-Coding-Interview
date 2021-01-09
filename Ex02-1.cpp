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
		mData.generateRandom(30, 3);
		mData.printList();
	}

	void removeDupsNoMem() {
		struct LinkedList<int>::ListNode* runPtr = mData.getHead();

		// Traverse the list , pick one element
		while (runPtr != NULL) {
			// Traverse the list from here to end , start search from next element
			struct LinkedList<int>::ListNode* searchPtr = runPtr->next;
			while (searchPtr != NULL) {
				if (searchPtr->val == runPtr->val) {
					// Copy pointer to counter pointer invalidation
					struct LinkedList<int>::ListNode* delPtr = searchPtr;
					searchPtr = searchPtr->next;
					mData.deleteNode(delPtr);
				}
				else {
					searchPtr = searchPtr->next;
				}
			}
			runPtr = runPtr->next;
		}
		// Check Output
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
			// If found in tracker then delete the node : O(n) time
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
//	EX_02_01 solution1;
//	solution1.removeDupsNoMem();
//	return 0;
//}