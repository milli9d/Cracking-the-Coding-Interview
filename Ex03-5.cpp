/*
	3.5 Sort Stack: Write a program to sort a stack such that the smallest items are on the top. You can use
	an additional temporary stack, but you may not copy the elements into any other data structure
	(such as an array). The stack supports the following operations: push, pop, peek, and isEmpty.

*/

#include <iostream>
#include "StackStatic.h"
#include <time.h>

template<typename T, size_t S>
class EX_03_5 {
private:
	Stack<T, S> mData;
public:
	EX_03_5() {}

	// We check that we always push the smallest value on top.
	// To do this , we temporarily take out all smaller elements in another stack to help
	void push(T val) {
		// When stack is empty
		if (mData.empty()) {
			mData.push(val);
		}
		// When stack is full , check all top values
		else {
			Stack<T, S> temp;

			// Find all smaller values and push into temp stack
			while (!mData.empty() && mData.peek() < val) {
				temp.push(mData.peek());
				mData.pop();
			}

			// Push the value
			mData.push(val);

			// Push back taken out elements
			while (!temp.empty()) {
				mData.push(temp.peek());
				temp.pop();
			}
		}
	}

	T& peek() {
		return mData.peek();
	}

	void pop() {
		mData.pop();
	}

	int size() {
		return mData.size();
	}

	bool empty() {
		return (size() == -1) ? true : false;
	}
};

//int main() {
//	EX_03_5<int, 100> test;
//
//	srand(time(0));
//
//	for (int i = 0; i < 100; i++) {
//		test.push(rand() % 255);
//	}
//
//	while (!test.empty())
//	{
//		std::cout << test.peek() << std::endl;
//		test.pop();
//	}
//
//	return 0;
//}