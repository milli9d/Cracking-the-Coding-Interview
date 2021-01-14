/*
	Intersection: Given two (singly) linked lists, determine if the two lists intersect. Return the
	intersecting node. Note that the intersection is defined based on reference, not value. That is, if the
	kth node of the first linked list is the exact same node (by reference) as the jth node of the second
	linked list, then they are intersecting.

*/

#include <iostream>
#include <vector>
#include "LinkedList.h"

using std::cout;
using std::endl;
using std::vector;

class EX_02_07 {
public:
	template<typename T>
	static void intersection(LinkedList<T>& a, LinkedList<T>& b) {
		LinkedListIterator aPtr = a.begin();
		LinkedListIterator bPtr = b.begin();
	}

private:
};

int main() {
	return 0;
}