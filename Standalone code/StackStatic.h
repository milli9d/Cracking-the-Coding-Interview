#pragma once
#include <iostream>
#include <vector>
#include <assert.h>

template<typename T, size_t S>
class Stack {
	// Private Members
private:
	T mData[S];
	int TOP = -1;
	int capacity = NULL;

	// Constructors / Destructors
public:
	// Default Constructor
	Stack() : TOP(-1), capacity(S - 1) {
		memset(mData, 0, S * sizeof(T));
	}

	~Stack() {
	}

	// Member Functions
	// 1. PUSH
	// 2. POP
	// 3. PEEK/TOP
public:
	void push(const T& val) {
		if (TOP < capacity) {
			mData[++TOP] = val;
		}
		else {
			printf("Stack Capacity(%d) Exceeded. \n", S);
		}
	}

	void pop() {
		if (TOP != -1) {
			TOP--;
		}
		else
		{
			printf("Stack Empty!\n");
		}
	}

	T& peek() {
		if (TOP != -1) {
			return mData[TOP];
		}
		else {
			printf("Stack Empty!\n");
		}
	}

	T& top() {
		if (TOP != -1) {
			return mData[TOP];
		}
		else
		{
			printf("Stack Empty!\n");
		}
	}

	int size() {
		return TOP;
	}

	bool isFull() {
		return (TOP == S - 1) ? true : false;
	}

	bool empty() {
		return (TOP == -1) ? true : false;
	}
};

//int main() {
//	Stack<int, 10> test;
//	test.push(10);
//	int a = test.peek();
//	test.push(20);
//	a = test.peek();
//	test.push(30);
//	a = test.peek();
//	test.push(40);
//	a = test.peek();
//	assert(a == 40);
//	test.pop();
//	a = test.peek();
//	assert(a == 30);
//
//	test.push(80);
//	test.push(90);
//	test.push(100);
//	test.push(110);
//	test.push(120);
//	test.push(130);
//	test.pop();
//	test.pop();
//	test.pop();
//	test.pop();
//	test.pop();
//	test.pop();
//	test.pop();
//	test.pop();
//	test.pop();
//	test.pop();
//	test.pop();
//	test.pop();
//	test.pop();
//	test.pop();
//	return 0;
//}