/*
	Sum Lists: You have two numbers represented by a linked list,where each node contains a single
	digit. The digits are stored in reverse order,such that the 1's digit is at the head of the list. Write a
	function that adds the two numbers and returns the sum as a linked list.
	EXAMPLE
		Input: (7-> 1 -> 6) + (5 -> 9 -> 2).That is,617 + 295.
		Output: 2 -> 1 -> 9.That is,912.
	FOLLOW UP
		Suppose the digits are stored in forward order. Repeat the above problem.
		Input: (6 -> 1 -> 7) + (2 -> 9 -> 5).That is,617 + 295.
		Output: 9 -> 1 -> 2.That is, 912.
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

class EX_02_5 {
private:
	// Helper code to pad lists with zeroes for unequal lists
	static void padLists(LinkedList<int>& num1, LinkedList<int>& num2) {
		int sizeList1 = 0;
		int sizeList2 = 0;
		LinkedList<int>::Iterator first(num1.getHead());
		LinkedList<int>::Iterator second(num2.getHead());
		// Count elements in both lists
		while (first != NULL && second != NULL) {
			first++;
			sizeList1++;
			second++;
			sizeList2++;
		}
		// Complete count if any elements left
		while (first != NULL) {
			first++;
			sizeList1++;
		}
		while (second != NULL) {
			second++;
			sizeList2++;
		}
		// Pad zeroes on the shorter list
		LinkedList<int>& padList = (sizeList1 < sizeList2) ? num1 : num2;
		int count = abs(sizeList1 - sizeList2);
		while (count-- > 0) {
			padList.append(0);
		}
	}

public:
	/*
		Sum signed integer in a linked list stored in Forward order
	*/
	static LinkedList<int>* sumListForward(LinkedList<int>* num1, LinkedList<int>* num2) {
		// Reverse the Linked Lists
		LinkedList<int> temp1 = *num1;
		LinkedList<int> temp2 = *num2;
		temp1.reverse();
		temp2.reverse();
		LinkedList<int>* out = sumListReverse(&temp1, &temp2);
		out->reverse();
		return out;
	}

	/*
		Sum signed integer in a linked list stored in reverse order
	*/
	static LinkedList<int>* sumListReverse(LinkedList<int>* num1, LinkedList<int>* num2) {
		LinkedList<int>* output = new LinkedList<int>();
		// Pad Lists if they are unequal
		padLists(*num1, *num2);

		printf("\n");

		LinkedList<int>::Iterator first(num1->getHead());
		LinkedList<int>::Iterator second(num2->getHead());

		int prevCarry = 0;
		while (first != NULL && second != NULL) {
			// Calculate total and isolate carry and sum
			int total = first->val + second->val;
			int carry = total / 10;
			int sum = total % 10;

			// Re-use storage for total to be added to list
			total = sum + prevCarry;

			// Previous Carry Check, if total exceeds 9 that means there is additional carry to be forwarded
			if (total > 9) {
				// Forward by adding to current cycle carry
				carry += total / 10;
				// New total becomes units place of the result
				total = total % 10;
			}

			// Insert in new Linked List
			output->append(total);

			// Move Pointers
			first++;
			second++;
			prevCarry = carry;
		}

		if (prevCarry != 0) {
			output->append(prevCarry);
		}

		return output;
	}
};

//int main() {
//	LinkedList<int> num1;
//	num1.generateRandom(10, 5);
//	num1.printList();
//	LinkedList<int> num2;
//	num2.generateRandom(5, 10);
//	num2.printList();
//
//	LinkedList<int>* test = EX_02_5::sumListForward(&num1, &num2);
//	test->printList();
//	//LinkedList<int>* test1 = EX_02_5::sumListReverse(&num1, &num2);
//	//test1->printList();
//	//delete(test1);
//
//	return 0;
//}