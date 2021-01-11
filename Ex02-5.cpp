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
public:

	/*
			3->1->2   + 1->2->3  =  213 + 321 = 534
	*/
	LinkedList<int>* sumList(LinkedList<int>* num1, LinkedList<int>* num2) {
		LinkedList<int>* output = new LinkedList<int>();
		LinkedList<int>::ListNode* runPtr1 = num1->getHead();
		LinkedList<int>::ListNode* runPtr2 = num2->getHead();
		num1->printList();
		num2->printList();
		int prevCarry = 0;
		while (runPtr1 != NULL && runPtr2 != NULL) {
			int sum = runPtr1->val + runPtr2->val;
			int carry = sum / 10;
			int val = sum % 10;
			// If carry
			output->append(val + prevCarry);

			prevCarry = carry;
			runPtr1 = runPtr1->next;
			runPtr2 = runPtr2->next;
		}
		output->printList();
		return output;
	}
};

//int main() {
//	LinkedList<int> num1;
//	num1.append(8);
//	num1.append(2);
//	num1.append(5);
//	LinkedList<int> num2;
//	num2.append(4);
//	num2.append(5);
//	num2.append(6);
//
//	EX_02_5 solution;
//	solution.sumList(&num1, &num2);
//
//	return 0;
//}