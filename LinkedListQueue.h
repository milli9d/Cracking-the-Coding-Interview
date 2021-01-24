/*
	Linked List Based Queue
	1. Push ->  back
	2. Pop  ->  front
	3. Peek ->  front

*/

#include "LinkedList.h"
#include <iostream>
#include <vector>

template<typename T>
class Queue {
private:
	LinkedList<T> mData;
public:
	Queue() {}

	// Enqueue , push from back
	void push(T val) {
		mData.append(val);
	}

	void pop() {
		mData.deleteNode((size_t)0);
	}

	T& peek() { return mData.begin()->val; }

	int size() { return mData.getSize(); }

	bool empty() {
		return (size() == -1) ? true : false;
	}

	void print() {
		printf("Front:");
		mData.printList();
	}
};

//int main() {
//	Queue<int> test;
//	test.push(10);
//	test.push(20);
//	test.push(30);
//	test.push(40);
//	test.print();
//	int a = test.peek();
//	test.pop();
//	a = test.peek();
//	test.pop();
//	a = test.peek();
//	test.pop();
//	a = test.peek();
//	test.print();
//
//	return 0;
//}