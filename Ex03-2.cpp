/*
	Stack Min: How would you design a stack which, in addition to push and pop, has a function min
which returns the minimum element? Push, pop and min should all operate in 0(1) time.
Hints:#27, #59, #78

*/

#include <iostream>
#include "StackStatic.h"
#include <vector>
#include <assert.h>

/*
	This class solves this problem by using an additional stack to track the minumums after each PUSH/POP.
	This class is a wrapper on the already present static stack class
*/
template <size_t S>
class EX_03_02 {
public:
	// Find minimum after this push and place it in the tracker stack
	void push(int val) {
		if (val < min) {
			min = val;
			minData.push_back(val);
		}
		stackData.push(val);
	}

	// Pop from both Data and tracker stack
	void pop() {
		if (stackData.peek() == minData[minData.size() - 1]) {
			minData.pop_back();
		}
		stackData.pop();
	}

	// Peek from Data
	const int& peek() {
		return stackData.peek();
	}

	// Peek from Tracker
	const int& MIN() {
		return *(minData.end() - 1);
	}

private:
	Stack<int, S> stackData;
	std::vector<int> minData;
	int min = INT32_MAX;
};

//int main() {
//	EX_03_02<10> test;
//
//	test.push(23);
//	test.push(15);
//	test.push(1);
//	test.push(3);
//	test.push(10);
//	int a = test.MIN();
//	assert(a == 1);
//	test.pop();
//	test.pop();
//	test.pop();
//	a = test.MIN();
//	assert(a == 15);
//	test.push(23);
//	a = test.MIN();
//	test.push(-10);
//	a = test.MIN();
//	test.push(12);
//	test.pop();
//	a = test.MIN();
//	return 0;
//}