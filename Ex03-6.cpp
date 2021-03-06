/*
	3.6 Animal Shelter: An animal shelter, which holds only dogs andcats, operates on a strictly"first in, first
	out"basis. People must adopt either the "oldest"(based on arrival time) ofall animals at the shelter,
	or they can select whether they would prefer a dog or a cat (and will receive the oldest animal of
	that type). They cannot select which specific animal they would like. Create the data structures to
	maintain this system and implement operations such as enqueue, dequeueAny, dequeueDog,
	and dequeueCat.You may use the built-in Linkedlist data structure

*/

#include <iostream>
#include "StackStatic.h"
#include <time.h>
#include <string>
#include "LinkedListQueue.h"

using std::cout;
using std::endl;
using std::string;

class EX_03_6 {
	// Inner Classes
public:
	enum AnimalNames {
		CAT, DOG, ANIMAL
	};

	//Inner Classes
private:
	// Base Animal Class
	class Animal {
	private:
		AnimalNames name = ANIMAL;
		int order = -1;
	public:
		// Deleted Default Constructor
		Animal() = delete;
		// Constructor to put animal name
		Animal(enum AnimalNames sname) :name(sname) {}
		int getOrder() { return order; }
		void setOrder(int o) { order = o; }
	};

	// Derived Class
	class Cat : public Animal {
	public:
		// Default Constructor
		Cat() :Animal(CAT) {}
	};
	// Derived Class
	class Dog : public Animal {
	public:
		// Default Constructor
		Dog() :Animal(DOG) {}
	};

	// Storage Members
private:
	Queue<Dog> dogQueue;
	Queue<Cat> catQueue;
	int order = -1;

	// Member Functions
public:
	// Defualt Constructor
	EX_03_6() : order(-1) {}

	// Enqueue an animal
	void enqueue(AnimalNames name) {
		if (name == CAT) {
			Cat* temp = new Cat();
			temp->setOrder(++order);
			catQueue.push(*temp);
		}
		else if (name == DOG) {
			Dog* temp = new Dog();
			temp->setOrder(++order);
			dogQueue.push(*temp);
		}
	}

	// Dequeue a Dog
	void dequeueDog() {
		if (!dogQueue.empty()) {
			dogQueue.pop();
		}
		else { printf("No More Dogs!\n"); }
	}

	// Dequeue a Cat
	void dequeueCat() {
		if (!catQueue.empty()) {
			catQueue.pop();
		}
		else { printf("No More Cats!\n"); }
	}

	// Choose the older one and pop
	void dequeueAny() {
		// Check if any one queue is empty , if empty pop from other queue
		if (!dogQueue.empty() && catQueue.empty()) {
			dogQueue.pop();
		}
		//
		else if (dogQueue.empty() && !catQueue.empty()) {
			catQueue.pop();
		}
		// If both queues are full compare which came earlier
		else if (!dogQueue.empty() && !catQueue.empty()) {
			(dogQueue.peek().getOrder() <= catQueue.peek().getOrder()) ? dogQueue.pop() : catQueue.pop();
		}
		else { printf("Animal Shelter is Empty!\n"); }
	}

	// Print Shelter Stats
	void printStats() {
		printf("===============\nAnimal Shelter:\nDogs:%d\nCats:%d\n", dogQueue.size() + 1, catQueue.size() + 1);
	}
};

//int main() {
//	EX_03_6 AnimalShelter;
//	AnimalShelter.enqueue(AnimalShelter.DOG);
//	AnimalShelter.enqueue(AnimalShelter.CAT);
//	AnimalShelter.enqueue(AnimalShelter.DOG);
//	AnimalShelter.enqueue(AnimalShelter.CAT);
//	AnimalShelter.enqueue(AnimalShelter.DOG);
//	AnimalShelter.enqueue(AnimalShelter.DOG);
//	AnimalShelter.dequeueAny();
//	AnimalShelter.dequeueAny();
//	AnimalShelter.dequeueAny();
//	AnimalShelter.dequeueAny();
//	AnimalShelter.dequeueAny();
//	AnimalShelter.dequeueAny();
//	AnimalShelter.printStats();
//	AnimalShelter.enqueue(AnimalShelter.CAT);
//	AnimalShelter.enqueue(AnimalShelter.DOG);
//	AnimalShelter.enqueue(AnimalShelter.DOG);
//	AnimalShelter.enqueue(AnimalShelter.DOG);
//	AnimalShelter.enqueue(AnimalShelter.CAT);
//	AnimalShelter.enqueue(AnimalShelter.CAT);
//	AnimalShelter.enqueue(AnimalShelter.CAT);
//
//	AnimalShelter.dequeueCat();
//	AnimalShelter.dequeueDog();
//	AnimalShelter.dequeueDog();
//	AnimalShelter.printStats();
//
//	return 0;
//}