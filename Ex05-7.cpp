/*
	Pairwise Swap: Write a program to swap odd and even bits in an integer with as few instructions as
	possible (e.g., bit O and bit 1 are swapped, bit 2 and bit 3 are swapped, and so on).

*/

#include <iostream>
#include <bitset>

using std::cout;
using std::endl;
using std::bitset;

class EX_05_7 {
private:

public:
	void pairSwap(uint32_t in) {
		cout << bitset<32>(in) << endl;
		bitset<32> out = bitset<32>(((0x5555'5555 & in) << 1) | ((in & 0xAAAA'AAAA) >> 1));   // 1010:0xA     0101:0x5
		cout << out;
	}

	void reverseViaSwap(uint32_t in) {
		cout << bitset<32>(in) << endl;
		bitset<32> out = bitset<32>(((0x5555'5555 & in) << 1) | ((in & 0xAAAA'AAAA) >> 1));					// 1010:0xA     0101:0x5
		out = bitset<32>(((0x3333'3333 & out.to_ulong()) << 2) | ((out.to_ulong() & 0xCCCC'CCCC) >> 2));	// 1100:0xC     0011:0x3
		out = bitset<32>(((0x0F0F'0F0F & out.to_ulong()) << 4) | ((out.to_ulong() & 0xF0F0'F0F0) >> 4));	// 1111:0xF     0000:0x0
		out = bitset<32>(((0x00FF'00FF & out.to_ulong()) << 8) | ((out.to_ulong() & 0xFF00'FF00) >> 8));	// 1111:0xF     0000:0x0
		out = bitset<32>((out.to_ulong() >> 16) | (out.to_ulong() << 16));
		cout << out;
	}
};

//int main() {
//	EX_05_7 solution;
//	solution.reverseViaSwap(0x0000'0005);
//	return 0;
//}