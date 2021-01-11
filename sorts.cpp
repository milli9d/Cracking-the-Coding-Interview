/*
	Implementation of Common Sorting Algorithms
	1. Bubble Sort
	2. Selection Sort
	3. Merge Sort
	4. Quick Sort

*/

#include <iostream>
#include <vector>

using intVector = std::vector<int>;

class Sorter {
private:
	void merge() {
	}

	void mergeSort() {
	}

public:
	/*
		Merge sort is an recursive algorithm
		divide the array into 2 halves
		sort the halves , merge them back
	*/
	void mergeSort(intVector& arr) {
	}

	/*
		Bubble sort uses small bubbles of 2 elements (i.e consecutive pairs) , it rearranges (swaps) the pair to be in ascending order.
		We do this enough iterations we get a sorted array , over time smaller elements bubble up to the beginning
		O(n^2) time , O(1) space
	*/
	void bubbleSort(intVector& arr) {
		size_t size = arr.size();
		// Run nested loop , number of times the size of the array ,
		// this effectively means that we atleast touch every element (the number of times it takes to bubble up to the begining).
		for (int j = 0; j < size; j++) {
			// Count number of swaps for small optimization
			int countSwap = 0;
			// Iterate thorugh array and switch elements which are not in order
			for (intVector::iterator i = arr.begin(); i != arr.end() - 1; i++) {
				intVector::iterator next = i + 1;
				if (*i > *next) {
					// swap
					std::swap(*i, *next);
					countSwap++;
				}
			}
			// Optimization , quit if no swaps were performed in this iteration
			if (countSwap == 0) { break; }
		}
	}

	/*
		Select the smallest/biggest element and move it to the front/back respectively.
		The size of the array is how many iterations are performed to ensure all elements are in place.
		O(n^2) time and O(1) space
	*/
	void selectionSort(intVector& arr) {
		// Size for saving time
		size_t size = arr.size();

		// Iterate through array , select an element
		for (intVector::iterator i = arr.begin(); i != arr.end(); i++) {
			intVector::iterator currMin = i;
			// Find minimum element after this current element
			for (intVector::iterator j = i; j != arr.end(); j++) {
				if (*j < *currMin) {
					currMin = j;
				}
			}
			// Swap the found minimum and the current element
			std::swap(*i, *currMin);
		}
	}

	/*
		Helper function to print array
	*/
	void printArr(const intVector& arr) {
		for (int i : arr) {
			printf("%d | ");
		}
		printf("\n");
	}

	/*
		Helper function to generate random arrays
	*/
	void generateRandom(intVector& arr, size_t count, int mod) {
		srand(time(0));
		for (int i = 0; i < count; i++) {
			arr.push_back(rand() % mod);
		}
	}

private:
};

int main() {
	Sorter solution;
	intVector test;

	{
		printf("\nBubble Sort.\n");
		test.clear();
		solution.generateRandom(test, 20, 50);
		printf("Input.\n");
		solution.printArr(test);

		solution.bubbleSort(test);
		printf("Output.\n");
		solution.printArr(test);
	}

	{
		printf("\nSelection Sort.\n");
		test.clear();
		solution.generateRandom(test, 20, 30);
		printf("Input.\n");
		solution.printArr(test);

		solution.selectionSort(test);
		printf("Output.\n");
		solution.printArr(test);
	}

	{
		printf("\nMerge Sort.\n");
		test.clear();
		solution.generateRandom(test, 20, 10);
		printf("Input.\n");
		solution.printArr(test);

		solution.mergeSort(test);
		printf("Output.\n");
		solution.printArr(test);
	}

	return 0;
}