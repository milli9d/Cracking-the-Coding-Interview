/*
	Partition: Write code to partition a linked list around a value x, such that all nodes less than x come
	before all nodes greater than or equal to x. If x is contained within the list the values of x only need
	to be after the elements less than x (see below). The partition element x can appear anywhere in the
	"right partition"; it does not need to appear between the left and right partitions.
	EXAMPLE
		Input: 3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 [partition= 5]
		Output: 3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8

*/

#include <iostream>
#include <assert.h>
#include <vector>
#include "LinkedList.h"

using std::cout;
using std::endl;
using std::vector;

#define LIST_SIZE 30
#define LIST_MOD 10

class EX_02_4 {
public:
	EX_02_4(LinkedList<int>* list) : mData(list) {}

	~EX_02_4() {
	}

	/*
		Partition a linked list to a pivot element
		1. Using Extra Space , not in-place (preserve original list)
	*/
	LinkedList<int>* partitionNodes(int pivot) {
		// Copy Linked List , Make unordered_set for storing one partition
		LinkedList<int>* output = new LinkedList<int>(*mData);
		vector<int> tracker;
		// Traverse the list
		// Delete any one partition from list and store in extra space
		LinkedList<int>::ListNode* runPtr = output->getHead();
		while (runPtr != NULL) {
			if (runPtr->val < pivot)
			{
				runPtr = runPtr->next;
			}
			else {
				LinkedList<int>::ListNode* delPtr = runPtr;
				runPtr = runPtr->next;
				tracker.push_back(delPtr->val);
				output->deleteNode(delPtr);
			}
		}
		// Put back into modified list
		for (int i : tracker) {
			output->append(i);
		}
		return output;
	}

	/*
		Partition a linked list to a pivot element
		2. Using No-Extra Space , not in-place (preserve original list)
	*/
	LinkedList<int>* partitionNodes2(int pivot) {
		// Copy Linked List , Make unordered_set for storing one partition
		LinkedList<int>* output = new LinkedList<int>();

		// Traverse the list
		LinkedList<int>::ListNode* runPtr = mData->getHead();
		while (runPtr != NULL) {
			if (runPtr->val < pivot)
			{
				output->insertNode(0, runPtr->val);
			}
			else {
				output->append(runPtr->val);
			}
			runPtr = runPtr->next;
		}
		return output;
	}

private:
	LinkedList<int>* mData = nullptr;
};

//int main() {
//	LinkedList<int> mData;
//	mData.generateRandom(LIST_SIZE, LIST_MOD);
//	mData.printList();
//	assert(mData.getSize() + 1 == LIST_SIZE);
//
//	EX_02_4 solution(&mData);
//
//	LinkedList<int>* output = solution.partitionNodes(5);
//	assert(mData.getSize() == output->getSize());
//	output->printList();
//	output = solution.partitionNodes2(5);
//	assert(mData.getSize() == output->getSize());
//	output->printList();
//
//	return 0;
//}