/*
	Three in One: Describe how you could use a single array to implement three stacks.
		Hints: #2, #72, #38, #58

*/

#pragma once
#include <iostream>
#include <vector>

/*
	A multiStack stores multiple stacks of size S on a single static array , user needs to instantiate with 3 template parameters
	1. Typename T = Data Type of Stack
	2. size_t S = Capacity of each individual stack
	3. size_t numStacks = Number of stacks of Capacity S

	PUSH/POP/PEEK works by supplying additional Stack Index parameter in member calls
*/
template<typename T, size_t S, size_t numStacks>
class MultiStack {
private:
	T mData[S * numStacks];
	int TOP[numStacks];
	int TOPLIM[numStacks];
	int CAP[numStacks];
public:
	MultiStack() {
		// Clear Arrays
		memset(mData, 0, S * numStacks * sizeof(T));
		memset(TOP, -1, numStacks * sizeof(int));
		memset(CAP, -1, numStacks * sizeof(int));

		for (int i = 0; i < numStacks; i++) {
			// Generate TOP starting points
			TOP[i] = (S * i) - 1;
			TOPLIM[i] = (S * i) - 1;
			// Generate CAP limits
			CAP[i] = (S * (i + 1)) - 1;
		}
	}

	void push(T val, size_t stackIdx) {
		if (stackIdx < numStacks && TOP[stackIdx] < CAP[stackIdx]) {
			mData[++TOP[stackIdx]] = val;
		}
	}

	void pop(size_t stackIdx) {
		if (stackIdx <numStacks && TOP[stackIdx] > TOPLIM[stackIdx]) {
			TOP[stackIdx]--;
		}
	}

	const T& peek(size_t stackIdx) {
		if (stackIdx < numStacks && TOP[stackIdx] > TOPLIM[stackIdx]) {
			return mData[TOP[stackIdx]];
		}
	}
};

//int main() {
//	MultiStack<int, 10, 10> test;
//	test.push(2, 0);
//	test.push(3, 1);
//	test.push(4, 2);
//	test.push(10, 4);
//	test.push(20, 3);
//	test.push(50, 2);
//	test.push(645, 1);
//	test.push(1435, 2);
//	test.push(1345, 2);
//	test.push(132, 1);
//	test.push(123, 2);
//	int a = test.peek(0);
//	a = test.peek(1);
//	a = test.peek(2);
//	test.pop(0);
//	test.pop(1);
//	a = test.peek(1);
//	test.pop(1);
//	a = test.peek(1);
//	test.pop(2);
//	a = test.peek(2);
//	return 0;
//}