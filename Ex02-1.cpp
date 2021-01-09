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
		LinkedList<int>::ListNode* runPtr = mData.getHead();
		while (runPtr != NULL) {
			LinkedList<int>::ListNode* copyPtr = runPtr;
			LinkedList<int>::ListNode* searchPtr = runPtr->next;
			LinkedList<int>::ListNode* delPtr = searchPtr;
			while (searchPtr != NULL) {
				if (searchPtr != NULL && searchPtr->val == runPtr->val) {
					delPtr = searchPtr;
					searchPtr = searchPtr->next;
					delete(delPtr);
				}
				else {
					searchPtr = searchPtr->next;
				}
			}
			runPtr = copyPtr->next;
		}
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
//	//solution.removeDups();
//	solution.removeDupsNoMem();
//	return 0;
//}