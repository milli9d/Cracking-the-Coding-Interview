/*
	Implementation of Common Sorting Algorithms
	1. Bubble Sort
	2. Selection Sort
	3. Merge Sort
	4. Quick Sort

*/
#pragma once
#include <iostream>
#include <vector>

using intVector = std::vector<int>;
using std::cout;
using std::endl;

#define INPUT_SIZE 20
#define INPUT_MOD 100

class Sorter {
public:
	/*
		Merge sort is an recursive algorithm, divide the array into 2 halves, sort the halves , merge them back
		O(nlog(n)) time O(n) space
	*/
	static void mergeSort(intVector& arr) {
		mergeSorter::mergeSort(arr, 0, arr.size() - 1);
	}

	static void quickSort(intVector& arr) {
		quickSorter::quickSort(arr, 0, arr.size() - 1);
	}

	Sorter() = delete;

private:
	// Helper class for Merge Sort
	class mergeSorter {
	public:
		// Merge two psuedo-arrays in ascending order
		static void merge(intVector& arr, size_t low, size_t high, size_t mid) {
			// Helper Storage
			intVector out;
			out.resize(high - low + 1);

			// Two-Pointer Technique
			size_t first = low;
			size_t second = mid + 1;

			// Choose smallest element and put in output array , similiar to bubble sort
			int outIdx = 0;
			while (first <= mid && second <= high) {
				// Find which is smaller ,  put it in the output array
				if (arr[first] < arr[second]) {
					out[outIdx++] = arr[first++];
				}

				else if (arr[first] > arr[second]) {
					out[outIdx++] = arr[second++];
				}

				else if (arr[first] == arr[second]) {
					out[outIdx++] = arr[first++];
					out[outIdx++] = arr[second++];
				}
			}

			// If any of the sub-array pointers has not reached the end , copy the leftover elements from the sub-array
			while (first <= mid) {
				out[outIdx++] = arr[first++];
			}

			// If any of the sub-array pointers has not reached the end , copy the leftover elements from the sub-array
			while (second <= high) {
				out[outIdx++] = arr[second++];
			}

			// Copy into original array
			for (int i = low; i <= high; i++) {
				arr[i] = out[i - low];
			}
			return;
		}

		static void mergeSort(intVector& arr, size_t low, size_t high) {
			if (low < high) {
				int mid = (low + high) / 2;
				//cout << low << "  " << mid << "  " << high << "  " << endl;
				mergeSort(arr, low, mid);
				mergeSort(arr, mid + 1, high);
				merge(arr, low, high, mid);
			}
			return;
		}
	};

	class quickSorter {
	public:
		static void quickSort(intVector& arr, int left, int right) {
			int index = partition(arr, left, right);
			// quicksort left partition
			if (left < index - 1) {
				quickSort(arr, left, index - 1);
			}
			// quicksort right partition
			if (index < right) {
				quickSort(arr, index, right);
			}
		}

		// Partition the subarrays such that all elements smaller to pivot are on left and all larger on right
		static int partition(intVector& arr, int left, int right) {
			int pivot = arr[(left + right) / 2];
			while (left <= right) {
				// Find element on left , which needs to be on right
				while (arr[left] < pivot) {
					left++;
				}
				// Find element on right , which needs to be on left
				while (arr[right] > pivot) {
					right--;
				}

				// Swap the found elements
				if (left <= right) {
					std::swap(arr[left], arr[right]);
					left++;
					right--;
				}
			}
			return left;
		}
	};

public:
	/*
		Bubble sort uses small bubbles of 2 elements (i.e consecutive pairs) , it rearranges (swaps) the pair to be in ascending order.
		We do this enough iterations we get a sorted array , over time smaller elements bubble up to the beginning
		O(n^2) time , O(1) space
	*/
	static void bubbleSort(intVector& arr) {
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
	static void selectionSort(intVector& arr) {
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
	static void printArr(const intVector& arr) {
		for (int i : arr) {
			printf("%2d | ");
		}
		printf("\n");
	}

	/*
		Helper function to generate random arrays
	*/
	static void generateRandom(intVector& arr, size_t count, int mod) {
		srand(time(0));
		for (int i = 0; i < count; i++) {
			arr.push_back(rand() % mod);
		}
	}
};

void demo(void (*myfun)(intVector& arr)) {
	intVector test;
	test.clear();
	Sorter::generateRandom(test, INPUT_SIZE, INPUT_MOD);
	printf("Input.\n");
	Sorter::printArr(test);
	myfun(test);
	printf("Output.\n");
	Sorter::printArr(test);
}

//int main() {
//	printf("\nBubble Sort.\n");
//	demo(&Sorter::bubbleSort);
//
//	printf("\nSelection Sort.\n");
//	demo(&Sorter::selectionSort);
//
//	printf("\nMerge Sort.\n");
//	demo(&Sorter::mergeSort);
//
//	printf("\nQuick Sort.\n");
//	demo(&Sorter::quickSort);
//
//	return 0;
//}