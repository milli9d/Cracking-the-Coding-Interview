/*
	Intersection: Given two (singly) linked lists, determine if the two lists intersect. Return the
	intersecting node. Note that the intersection is defined based on reference, not value. That is, if the
	kth node of the first linked list is the exact same node (by reference) as the jth node of the second
	linked list, then they are intersecting.

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include "LinkedList.h"

using std::cout;
using std::endl;
using std::unordered_set;

class EX_02_07 {
public:

	/*
		Find if two linked lists intersect , return the intersecting nodes by value in a seperate Linked List
	*/
	template<typename T>
	static LinkedList<T>& intersection(LinkedList<T>& a, LinkedList<T>& b) {
		unordered_set<LinkedList<T>::ListNode*> tracker;
		LinkedList<T>* out = new LinkedList<T>();
		LinkedList<T>::Iterator aPtr = a.begin();
		// Insert all elements to Tracker
		while (aPtr != a.end()) {
			tracker.insert(&(*aPtr++));
		}
		// Find elements in tracker , take common elements into new list
		LinkedList<T>::Iterator bPtr = b.begin();

		while (bPtr != b.end()) {
			auto ptr = tracker.find(&(*bPtr));
			if (ptr != tracker.end()) {
				out->append(bPtr->val);
			}
			bPtr++;
		}

		return *out;
	}

	/*
		Find if two linked lists intersect , return the intersecting nodes by reference in a vector
	*/
	template<typename T>
	static std::vector<void*> intersectionVec(LinkedList<T>& a, LinkedList<T>& b) {
		unordered_set<LinkedList<T>::ListNode*> tracker;
		std::vector<void*>* out = new std::vector<void*>();
		LinkedList<T>::Iterator aPtr = a.begin();
		// Insert all elements to Tracker
		while (aPtr != a.end()) {
			tracker.insert(&(*aPtr++));
		}
		// Find elements in tracker , take common elements into new list
		LinkedList<T>::Iterator bPtr = b.begin();

		while (bPtr != b.end()) {
			auto ptr = tracker.find(&(*bPtr));
			if (ptr != tracker.end()) {
				out->push_back((void*)&(*bPtr));
			}
			bPtr++;
		}

		return *out;
	}

private:
};

//int main() {
//	LinkedList<int> a;
//	a.generateRandom(5, 15);
//	a.printList();
//
//	LinkedList<int> b;
//	b.generateRandom(3, 10);
//	b.printList();
//
//	a.append(b);
//	printf("Appended List\n");
//	a.printList();
//
//	printf("Intersection Linked List\n");
//	LinkedList<int>& out = EX_02_07::intersection<int>(a, b);
//	out.printList();
//
//	printf("Intersection Vector of Pointers\n");
//	auto out2 = EX_02_07::intersectionVec<int>(a, b);
//	for (void* i : out2) {
//		LinkedList<int>::ListNode* temp = (LinkedList<int>::ListNode*) i;
//		cout << temp->val << "->";
//	}
//	cout << endl;
//
//	std::cin.get();
//	// Breaks after this point due to Linked List desctructor trying to free up merged linked lists
//	return 0;
//}