/*
	Stack of Plates: Imagine a (literal) stack of plates. If the stack gets too high, it might topple.
	Therefore, in real life, we would likely start a new stack when the previous stack exceeds some
	threshold. Implement a data structure SetOfStacks that mimics this. SetOfStacks should be
	composed of several stacks and should create a new stack once the previous one exceeds capacity.
	SetOfStacks.push() and SetOfStacks. pop() should behave identically to a single stack
	(that is, pop() should return the same values as it would if there were just a single stack).

	FOLLOW UP
	Implement a function popAt(int index) which performs a pop operation on a specific substack.

*/

#include <iostream>
#include "StackStatic.h"
#include <vector>
#include <time.h>

/*
	Set of Stacks
*/
template<typename T>
class Ex_03_03 {
private:
	#define S 10
	std::vector<Stack<T, S>*> mData;
	int size = 0;
	int TOP_stack = -1;
public:

	Ex_03_03() : size(-1), TOP_stack(-1) {
	}

	void push(T val) {
		// If the vector is empty , add initial stack
		// If there is no space , then increase capacity
		if (mData.empty() || mData[TOP_stack]->getTOP() >= (S - 1)) {
			mData.push_back(new Stack<T, S>());
			TOP_stack++;
		}
		// If there is space left then push into that space
		mData[TOP_stack]->push(val);
		size++;
	}

	void pop() {
		if (!mData.empty()) {
			// Do a pop
			mData[TOP_stack]->pop();
			size--;
			// If you empty out the stack then delete it , decrement size
			if (mData[TOP_stack]->empty()) {
				mData.erase(mData.begin() + TOP_stack--);
			}
		}
		else {
			printf("STACK EMPTY!");
		}
	}

	// Throws Exception if Stack is empty
	const T& peek() {
		if (!mData.empty()) {
			return mData[TOP_stack]->peek();
		}
	}

	bool isEmpty() {
		return (size == -1) ? true : false;
	}
};

//int main() {
//	Ex_03_03<int> test;
//
//	srand(time(0));
//	for (int i = 0; i < 50; i++) {
//		test.push(rand() % 100);
//	}
//
//	for (int i = 0; i < 100; i++) {
//		if (!test.isEmpty()) {
//			int a = test.peek();
//			std::cout << a << std::endl;
//			test.pop();
//		}
//	}
//	return 0;
//}