/*
	Delete Middle Node: Implement an algorithm to delete a node in the middle (i.e., any node but
	the first and last node, not necessarily the exact middle) of a singly linked list, given only access to
	that node.
	EXAMPLE
		Input:the node c from the linked lista->b->c->d->e->f
		Result: nothing is returned, but the new linked list looks likea->b->d->e->f
		Hints:#72

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
class EX_02_3 {
public:
	EX_02_3(LinkedList<T>* list) : mData(list) {}

	/*
		We don't have access to the head of the list , so we can take the element to be deleted to the end of the list and
		then severe its link to the list and delete it safely
	*/
	void deleteMiddleNode(struct LinkedList<T>::ListNode* deleteMe) {
		cout << deleteMe->val << endl;
		struct LinkedList<T>::ListNode* runPtr = deleteMe;
		struct LinkedList<T>::ListNode* swapPtr = runPtr;
		while (runPtr->next != NULL) {
			swapPtr = runPtr->next;
			std::swap(swapPtr->val, runPtr->val);
			runPtr = runPtr->next;
		}
		mData->deleteNode(runPtr);
	}

	/*
		We don't have access to the head of the list , so we can swap the element to be deleted with the next element and delete that element, the only issue is this will break when element to delete is at the end of list
	*/
	void deleteMiddleNode2(struct LinkedList<T>::ListNode* deleteMe) {
		// If already at end then delete the pointed element
		if (deleteMe->next == NULL) {
			mData->deleteNode(deleteMe);
			return;
		}
		// Move element to be deleted to next element
		struct LinkedList<T>::ListNode* swapPtr = deleteMe->next;
		std::swap(swapPtr->val, deleteMe->val);

		mData->deleteNode(swapPtr);
	}

private:
	LinkedList<T>* mData = nullptr;
};

//int main() {
//	LinkedList<int> mData;
//	mData.generateRandom(LIST_SIZE, LIST_MOD);
//	mData.printList();
//
//	EX_02_3<int> solution(&mData);
//	solution.deleteMiddleNode2(mData.getNode(9));
//	mData.printList();
//	solution.deleteMiddleNode2(mData.getNode(0));
//	mData.printList();
//	solution.deleteMiddleNode2(mData.getNode(7));
//	mData.printList();
//
//	return 0;
//}