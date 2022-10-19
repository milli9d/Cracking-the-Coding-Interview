/*
	3.4 Queue via Stacks : Implement a MyQueue class which implements a queue using two stacks.
		Hints :#98, #7 74
		LIFO
		1. push() back
		2. pop() front
		3. peek() front

*/
#include <iostream>
#include "StackStatic.h"
#include <assert.h>

template<typename T, size_t S>
class EX_03_4 {
private:
	int size = -1;
	Stack<T, S> mData;
	Stack<T, S> popStore;

public:
	EX_03_4() : size(-1) {}

	// Push only when popStore is emptied
	void push(T val) {
		// Push all elements from popStore into mData if not empty
		while (!popStore.empty() && !mData.isFull()) {
			mData.push(popStore.peek());
			popStore.pop();
		}
		mData.push(val);
		size++;
	}

	// Pop only when mData is emptied
	void pop() {
		// Push all elements from mData into popStore if not empty
		while (!mData.empty() && !popStore.isFull()) {
			popStore.push(mData.peek());
			mData.pop();
		}
		popStore.pop();
		size--;
	}

	T& peek() {
		// Push all elements from mData into popStore if not empty
		while (!mData.empty() && !popStore.isFull()) {
			popStore.push(mData.peek());
			mData.pop();
		}
		return popStore.peek();
	}

	bool empty() {
		return (size == -1) ? true : false;
	}
};

//int main() {
//	EX_03_4<int, 10> myQueue;
//
//	srand(time(0));
//
//	for (int i = 0; i < 10; i++) {
//		int val = (rand() % 100);
//		myQueue.push(val);
//		std::cout << val << std::endl;
//	}
//	printf("\n");
//
//	while (!myQueue.empty()) {
//		std::cout << myQueue.peek() << std::endl;
//		myQueue.pop();
//	}
//
//	return 0;
//}