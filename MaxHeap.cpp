/*
	Binary Heaps
	1. Min-Heap
	2. Max-Heap

*/

#include <iostream>
#include <vector>

using std::vector;

// Min Heap is a BST with Minimum Element always at the root
template<typename T>
class MaxHeap {
	// Private Members
private:
	vector<T> mData;

	// Heapify Operations
private:
	void heapifyDown() {
		int heapifyDownIdx = 0;
		int size = this->size();
		while (heapifyDownIdx < size) {
			// Swap element with smaller child till it's at right place
			int leftChildIdx = (2 * heapifyDownIdx) + 1;
			int rightChildIdx = (2 * heapifyDownIdx) + 2;

			if (leftChildIdx >= size || rightChildIdx >= size) { return; }
			// Get the smallest child
			int smallChildIdx = (mData[leftChildIdx] > mData[rightChildIdx]) ? leftChildIdx : rightChildIdx;
			// Compare with current to heapfify subtree element
			if (mData[smallChildIdx] > mData[heapifyDownIdx]) {
				std::swap(mData[smallChildIdx], mData[heapifyDownIdx]);
			}
			heapifyDownIdx = smallChildIdx;
		}
	}

	// Bubble up the inserted element till its in correct position
	void heapifyUp() {
		// Get last element
		int lastElementIdx = size() - 1;
		// Get its parent
		int parentIdx = (lastElementIdx - 1) / 2;
		while (parentIdx >= 0 && mData[lastElementIdx] > mData[parentIdx]) {
			// Swap
			std::swap(mData[parentIdx], mData[lastElementIdx]);
			// Walk UP
			lastElementIdx = parentIdx;
			parentIdx = (lastElementIdx - 1) / 2;
		}
	}

	// Min Heap Operations
public:
	// Simply add to the end of heap data structure
	void insert(T val) {
		mData.push_back(val);
		heapifyUp();
	}

	// Remove the minimum element
	void poll() {
		if (mData.empty()) { return; }
		// Swap the min element with last inserted element
		int lastElementIdx = size() - 1;
		std::swap(mData[lastElementIdx], mData[0]);
		// Erase the Last Element
		mData.erase(mData.begin() + lastElementIdx);
		// Heapify down
		heapifyDown();
	}

	T max() {
		if (!mData.empty) {
			return mData[0];
		}
		else {
			printf("MIN on EMPTY\n");
			return NULL;
		}
	}

	int size() {
		return mData.size();
	}

	// Miscellaneous Fuctions
public:
	void print() {
		vector<int>::iterator tPtr = mData.begin();
		int power = 0;
		while (tPtr != mData.end()) {
			for (int i = 0; i < pow(2, power); i++) {
				if (tPtr == mData.end()) {
					printf("\n");
					return;
				}
				printf("%d ", *(tPtr++));
			}
			power++;
			printf("\n");
		}
	}

	void generateRandom(int count, int mod) {
		srand(time(0));
		for (int i = 0; i < count; i++) {
			insert(rand() % mod);
		}
	}

	void pollTester(int val) {
		if (mData.size() > val) {
			for (int i = 0; i < val; i++) {
				poll();
				print();
				printf("-------------------------------\n");
			}
		}
	}
};

int main() {
	MaxHeap<int> test;
	test.generateRandom(10, 100);
	test.print();
	printf("-------------------------------\n");
	test.pollTester(5);
	return 0;
}