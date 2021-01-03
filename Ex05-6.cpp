/*
	Conversion: Write a function to determine the number of bits you would need to flip to convert
	integer A to integer B.
	EXAMPLE
	Input: 29 (or: 11101), 15 (or: 01111)
	Output: 2

*/

#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;

class Ex_05_6 {
private:
public:
	int editsToNumber(uint32_t first, uint32_t second) {
		int count = 0;
		while (first != 0 || second != 0)
		{
			// Extract a bit from both numbers
			bool bitFirst = first & 1;
			bool bitSecond = second & 1;
			// Compare if extracted bits are different
			if (bitFirst != bitSecond) {
				count++;
			}
			// Shift right to keep moving
			first >>= 1;
			second >>= 1;
		}
		return count;
	}

	int editsToNumberXOR(uint32_t first, uint32_t second) {
		uint64_t acc = first ^ second;
		int count = 0;
		while (acc != 0)
		{
			// Extract number from XORd result , this will be 0 where bits were different
			bool bit = acc & 1;
			// Count bits which are 1
			if (bit) {
				count++;
			}
			// Shift right to keep moving
			acc >>= 1;
		}
		return count;
	}
};

int main() {
	Ex_05_6 solution;
	cout << solution.editsToNumber(29, 15) << endl;
	cout << solution.editsToNumberXOR(29, 15) << endl;
	return 0;
}