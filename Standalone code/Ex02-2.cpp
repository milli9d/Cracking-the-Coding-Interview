/*
	2.2 Return Kth to Last: Implement an algorithm to find the kth to last element of a singly linked list.
*/

#include <iostream>
#include <assert.h>
#include <unordered_map>
#include "LinkedList.h"

using std::cout;
using std::endl;
using std::unordered_map;

#define LIST_SIZE 10
#define LIST_MOD 100

template<typename T>
class EX_02_2 {
public:
	EX_02_2(LinkedList<T>* mData) {
		this->mData = mData;
	}

	/*
		Using Extra space , keep track of how many nodes visited in a hashmap
	*/
	struct LinkedList<T>::ListNode* getNthFromBack1(size_t n) {
		// Sanity Check
		if (mData->getSize() < n) {
			printf("FETCH ERROR: Out of bounds!\n");
			return nullptr;
		}
		// Local Storage
		unordered_map<int, struct LinkedList<T>::ListNode*> idxTrack;
		struct LinkedList<T>::ListNode* ptr = mData->getHead();
		int count = 0;

		// Track whole list
		while (ptr != NULL) {
			idxTrack.insert({ count++,ptr });
			ptr = ptr->next;
		}
		// Return ptr to required idx
		return idxTrack.at(mData->getSize() - n);
	}
	/*
		Using little Extra space , maintain a slow pointer which runs n elements behind runPtr
	*/
	struct LinkedList<T>::ListNode* getNthFromBack2(size_t n) {
		// Sanity Check
		if (mData->getSize() < n) {
			printf("FETCH ERROR: Out of bounds!\n");
			return nullptr;
		}

		struct LinkedList<T>::ListNode* runPtr = mData->getHead();
		struct LinkedList<T>::ListNode* slowPtr = mData->getHead();

		// Get runPtr to be n elements ahead
		while (n-- > 0) {
			runPtr = runPtr->next;
		}
		// Run both pointers till runPtr reaches end
		while (runPtr->next != NULL) {
			runPtr = runPtr->next;
			slowPtr = slowPtr->next;
		}
		return slowPtr;
	}

private:
	LinkedList<T>* mData = nullptr;
};

//int main() {
//	LinkedList<int> mData;
//	mData.generateRandom(LIST_SIZE, LIST_MOD);
//	assert(mData.getSize() + 1 == LIST_SIZE);
//	mData.printList();
//	EX_02_2<int> solution(&mData);
//
//	LinkedList<int>::ListNode* fetched = nullptr;
//	fetched = solution.getNthFromBack1(3);
//	if (fetched != nullptr) {
//		cout << fetched->val << endl;
//	}
//	fetched = solution.getNthFromBack2(3);
//	if (fetched != nullptr) {
//		cout << fetched->val << endl;
//	}
//	return 0;
//}