#pragma once
#include <iostream>
#include <string>
#include <time.h>

using std::cout;
using std::endl;
using std::string;

/*
	Templated Single Linked List
*/
template<typename T>
class LinkedList {
public:
	typedef struct ListNode {
		T val;
		ListNode* next;

		ListNode(T val) {
			this->val = val;
			this->next = nullptr;
		}
	};

	LinkedList() : size(-1), head(nullptr) {
	}

	// Copy Constructor - Deep Copy
	LinkedList(const LinkedList<T>& obj) : size(-1), head(nullptr) {
		LinkedList<T>::ListNode* runPtr = obj.head;
		printf("Copied\n");
		while (runPtr != NULL) {
			append(runPtr->val);
			runPtr = runPtr->next;
		}
	}

	// Move Constructor - Shallow Copy , take ownership
	LinkedList(LinkedList<T>&& obj) : size(-1), head(nullptr) {
		printf("Moved\n");
		this->head = obj.head;
		this->size = obj.size;
		obj.head = nullptr;
		obj.size = 0;
	}

	~LinkedList() {
		LinkedList<T>::ListNode* runPtr = head;
		while (runPtr != NULL) {
			ListNode* delPtr = runPtr;
			runPtr = runPtr->next;
			delete(delPtr);
		}
	}

	void generateRandom(size_t count, int limit) {
		srand(time(0));
		while (count-- > 0) {
			int val = rand() % limit;
			append(val);
		}
	}

	/*
		Append to the end of the list
	*/
	void append(T val) {
		LinkedList<T>::ListNode* temp = new LinkedList<T>::ListNode(val);
		temp->next = nullptr;
		//temp->val = val;
		// If head is not initialized yet , set head to new node
		if (head == nullptr) {
			head = temp;
		}
		else
		{
			// Traverse to end of list
			LinkedList<T>::ListNode* ptr = head;
			while (ptr->next != NULL) {
				ptr = ptr->next;
			}
			// Add temp node to list's end
			ptr->next = temp;
		}
		size++;
	}

	void deleteNode(ListNode* deleteMe) {
		if (deleteMe == head) {
			ListNode* deletePtr = head;
			head = head->next;
			delete(deletePtr);
			size--;
		}
		else {
			ListNode* linkPtrBfr = head;										//	Element before the element to be deleted
			while (linkPtrBfr != NULL) {
				if (linkPtrBfr->next == deleteMe) {
					break;
				}
				linkPtrBfr = linkPtrBfr->next;
			}
			if (linkPtrBfr != NULL) {
				ListNode* linkPtrAft = linkPtrBfr->next->next;						//  Element after the element to be deleted
				ListNode* deletePtr = linkPtrBfr->next;
				linkPtrBfr->next = linkPtrAft;
				delete(deletePtr);
				size--;
			}
		}
	}

	void deleteNode(size_t idx) {
		if (idx <= size) {
			if (idx == 0) {
				ListNode* deletePtr = head;
				head = head->next;
				delete(deletePtr);
			}
			else {
				ListNode* linkPtrB = getNode(idx - 1);				//	Element before the element to be deleted
				ListNode* linkPtrA = linkPtrB->next->next;						//  Element after the element to be deleted
				ListNode* deletePtr = linkPtrB->next;
				linkPtrB->next = linkPtrA;
				delete(deletePtr);
			}size--;
		}
	}

	void insertNode(size_t idx, T val) {
		if (idx <= size) {
			LinkedList<T>::ListNode* temp = new LinkedList<T>::ListNode(val);
			if (idx == 0) {
				temp->next = head;
				head = temp;
			}
			else {
				ListNode* ptr = getNode(idx - 1);
				auto* nextPtr = ptr->next;
				ptr->next = temp;
				temp->next = nextPtr;
			}
			size++;
		}
		else {
			printf("Out of Bounds!!\n");
		}
	}
	/*
		Pretty Print the list
	*/
	void printList() {
		auto* ptr = head;
		while (ptr != NULL) {
			cout << "->" << ptr->val;
			ptr = ptr->next;
		}
		cout << endl;
	}

	ListNode* getHead() {
		return head;
	}

	ListNode* getNode(size_t idx) {
		if (idx <= size) {
			ListNode* ptr = head;
			while (idx-- > 0) {
				ptr = ptr->next;
			}
			return ptr;
		}
	}

	size_t getSize() {
		return size;
	}

private:
	size_t size = -1;
	LinkedList<T>::ListNode* head = nullptr;
};

//int main() {
//	LinkedList<int> test;
//	test.generateRandom(20, 10);
//	LinkedList<int>::ListNode* temp = test.getNode(0);
//	cout << temp->next << " | " << temp->val << endl;
//	test.printList();
//	test.deleteNode(test.getNode(1));
//	test.deleteNode(2);
//	test.printList();
//}