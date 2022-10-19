/*
	Flip Bit to Win: You have an integer and you can flip exactly one bit from a 0 to a 1. Write code to
	find the length of the longest sequence of ls you could create.
	EXAMPLE
		Input: 1775	(or: 11011101111)
		Output: 8
	Hints:#759,#226, #374,#352

*/

#include <iostream>
#include <bitset>
#include <vector>

using std::cout;
using std::endl;
using std::bitset;
using std::vector;

class EX_05_3_naive {
private:

	/*
	Compress unsigned number into number of 1s between 0s
		eg = 11100101101 ==> 3,0,1,2,1 occurences between 0s

		@return vector<int> containing number of occurences
	*/
	std::vector<int> compressVal(uint64_t& val, const int& INT_SIZE)
	{
		int count_1s = 0;
		std::vector<int> countArr;
		for (int i = 0; i < INT_SIZE; i++) {
			// Extract a bit from LSB (Right)
			bool bit = val & 1UL;
			// If bit is 1, Increment count
			if (bit) {
				count_1s++;
			}
			// If bit is 0, Push count and reset counter
			else {
				countArr.push_back(count_1s);
				count_1s = 0;
			}

			// Shift temp val to get next bit
			val >>= 1;
		}
		// Flush count if end without 0
		if (count_1s != 0) {
			countArr.push_back(count_1s);
		}
		return countArr;
	}

public:
	int flipBit(uint64_t val, const int INT_SIZE) {
		// Sanity Check
		if (INT_SIZE > 64) { return -1; }

		// Compress given value into numbers of 1s between 0s
		vector<int> countArr = compressVal(val, INT_SIZE);

		// Run over vector and determine longest possible length
		int max_possible_len = -1;
		const int arr_size = countArr.size();

		// Sanity Checks
		if (arr_size == 0) { return 1; }
		if (arr_size == 1) { max_possible_len = countArr[0]; }

		for (int i = 0; i < arr_size - 1; i++) {
			// Take slice of 2 elements and sum them
			int sum = countArr[i] + countArr[i + 1];
			max_possible_len = (sum > max_possible_len ? sum : max_possible_len);
		}

		if (max_possible_len >= INT_SIZE) { return INT_SIZE; }

		return max_possible_len + 1;
	}
};
class EX_05_3 {
private:

public:
	/*
		I optimize the naive approach by reducing ooperations and rolling into one loop.
		I also reduce memory usage by eliminating storing the whole array of occurences , I can keep track of current and last count to get my highest sum.
	*/
	int flipBit(uint64_t val, const int INT_SIZE) {
		// Sanity Check
		if (INT_SIZE > 64) { return -1; }
		if (val == 0) { return 1; }

		int max_possible_len = -1;

		int count_1s = 0;
		int prev_count = 0;

		for (int i = 0; i < INT_SIZE; i++) {
			// Extract a bit from LSB (Right)
			const bool bit = val & 1UL;
			// If bit is 1, Increment count
			if (bit) {
				count_1s++;
			}
			// If bit is 0, Push count and reset counter
			else {
				int sum = count_1s + prev_count;
				if (sum > max_possible_len) { max_possible_len = sum; }
				prev_count = count_1s;
				count_1s = 0;
			}
			// Shift temp val to get next bit
			val >>= 1;
		}
		// Flush count if end without 0
		{
			int sum = count_1s + prev_count;
			if (sum > max_possible_len) { max_possible_len = sum; }
			prev_count = count_1s;
			count_1s = 0;
		}

		if (max_possible_len >= INT_SIZE) { return INT_SIZE; }

		return max_possible_len + 1;
	}
};

//int main() {
//	//	EX_05_3_naive solution;
//	EX_05_3 solution;
//	cout << solution.flipBit(0b1001, 4) << endl;										// 1101 OR 1011 ==> 2
//	cout << solution.flipBit(0b1001'1011, 8) << endl;									// 1001'1111 ==> 5
//	cout << solution.flipBit(0b1010'1111'1011'1110, 16) << endl;						// 11
//	cout << solution.flipBit(0b1000'1000'1000'1000'1011'1111'1011'1110, 32) << endl;	// 13
//
//	return 0;
//}