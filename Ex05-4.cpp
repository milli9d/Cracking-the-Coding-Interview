/*
	Next Number: Given a positive integer, print the next smallest and the next largest number that
	have the same number of 1 bits in their binary representation.
	Hints:#747,#775, #242,#372,#339,#358,#375,#390
*/

#include <iostream>
#include <bitset>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::bitset;
using std::vector;

class EX_05_4 {
private:

public:
	template<size_t SIZE>
	void nextNumbers(uint32_t num) {
		bitset<SIZE> numbitset = num;
		// TODO: Check for bounds of integer

		// Get number of 1s in val
		uint32_t count = 0;
		for (int i = 0; i < SIZE; i++) {
			count += num & 1;
			num >>= 1;
		}

		// Get next largest number
		bitset<SIZE> nextLarge = bitset<SIZE>(pow(2, count) - 1) << (SIZE - count);					// 1110 not 0111

		// Get next smallest number
		bitset<SIZE> nextSmall = numbitset.to_ulong();
		for (int i = 0; i > SIZE - 1; i++) {
			auto& curr = nextSmall[i];
			auto& next = nextSmall[i + 1];
			if (curr != next) {
				bool temp = curr;
				curr = next;
				next = temp;
			}
			cout << nextSmall << endl;
			if (nextSmall.to_ulong() > numbitset.to_ulong()) {
				break;
			}
		}

		cout << "Current Number is " << std::to_string(numbitset.to_ulong()) << " | " << numbitset << endl;
		if (nextLarge != numbitset) {
			cout << "Next Number is " << std::to_string(nextLarge.to_ulong()) << " | " << nextLarge << endl;
		}
		else {
			cout << "Next largest is out of bounds!!" << endl;
		}

		cout << "Next Smallest Number is " << std::to_string(nextSmall.to_ulong()) << " | " << nextSmall << endl;
	}
};

//int main() {
//	EX_05_4 solution;
//
//	solution.nextNumbers<4>(0b0101);				// 0110(6) ==> 1100(12) ++ 0011(3)
//}