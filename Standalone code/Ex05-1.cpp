/*
	Insert Bit Mask

	Given 32-bit N , add 32-bit M between position j and i

*/
#include <iostream>
#include <bitset>

using namespace std;

void insertMask(uint32_t& val, uint32_t mask, uint8_t offset_beg, uint8_t offset_end) {
	// Sanity check
	if (offset_beg >= offset_end) { return; }

	// Make temporary mask to use for various ops
	uint32_t tempmask = 0;
	int numBitsMask = offset_end - offset_beg;

	// Check if the mask is larger than available positions
	if (numBitsMask + offset_beg > 32) { return; }

	// Clear bits in value
	for (int i = 0; i <= numBitsMask; i++) {
		tempmask = tempmask << 1;
		tempmask |= 1;
	}

	// Clear Val
	tempmask = ~(tempmask << offset_beg);
	val = val & (tempmask);

	// Insert new bits
	tempmask = mask << offset_beg;
	val = val | tempmask;

	cout << bitset<32>(tempmask) << " | " << std::hex << tempmask << endl;
	cout << bitset<32>(val) << " | " << std::hex << val << endl;
}

//int main() {
//	uint32_t temp = 0xffffffff;
//
//	insertMask(temp, 0x0000cccc, 8, 23);
//
//	return 0;
//}