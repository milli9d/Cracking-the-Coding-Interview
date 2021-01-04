/*
	Draw Line: A monochrome screen is stored as a single array of bytes, allowing eight consecutive	pixels to be stored in one byte.The screen has width w, where w is divisible by 8 (that is, no byte will be split across rows). The height of the screen, of course, can be derived from the length of the array and the width. Implement a function that draws a horizontal line from (xl, y) to (x2, y).

	The method signature should look something like:
		drawLine(byte[] screen, int width, int xl, int x2, int y)

*/

#include <iostream>
#include <bitset>

using std::cout;
using std::endl;
using std::bitset;
#define TFT_WIDTH 64
#define TFT_HEIGHT 32

class EX_05_8 {
private:
	uint8_t makeCharMask(uint8_t end) {
		if (end >= 7) { return 0xFF; }
		uint8_t out = (1 << end) - 1;
		return out;
	}

	void changeCharEndianness(uint8_t& a) {
		a = ((0x55 & a) << 1) | ((a & 0xAA) >> 1);		// 1010:0xA     0101:0x5
		a = ((0x33 & a) << 2) | ((a & 0xCC) >> 2);		// 1100:0xC     0011:0x3
		a = ((0x0F & a) << 4) | ((a & 0xF0) >> 4);		// 1111:0xF     0000:0x0
	}

public:
	void drawLine(unsigned char* screen, const uint32_t size, const uint32_t width, const uint32_t x1, const uint32_t x2, const uint32_t y) {
		// Find the height
		uint32_t height = size / width;
		printf("Drawing line b/w x = %d x = %d\n", x1, x2);
		// Sanity Checks
		if (y > height || x1 > width || x2 > width) {
			printf("OUT OF BOUNDS!\n");
			return;
		}

		// Find where line needs to start and end , in terms of Bytes in a row
		uint32_t firstByteIdx = x1 / 8;
		uint32_t lastByteIdx = x2 / 8;

		// Find if splits exist
		uint32_t firstByteSplitIdx = x1 % 8;
		uint32_t lastByteSplitIdx = x2 % 8;
		uint32_t heightIdx = (height - 1 - y) * (width / 8);

		// Fill a row on the screen
		// If line is complete in one byte
		if (firstByteIdx == lastByteIdx) {
			screen[firstByteIdx + heightIdx] = makeCharMask(lastByteSplitIdx - firstByteSplitIdx) << (8 - lastByteSplitIdx);
			return;
		}

		// Fill First Byte
		screen[firstByteIdx + heightIdx] = makeCharMask(8 - firstByteSplitIdx);
		changeCharEndianness(screen[firstByteIdx + heightIdx]);
		screen[firstByteIdx + heightIdx] >>= firstByteSplitIdx;
		// Fill Middle Bytes
		for (int i = firstByteIdx + 1; i < lastByteIdx; i++)
		{
			screen[i + heightIdx] = 0xFF;
		}

		// Fill Last Byte
		screen[lastByteIdx + heightIdx] = makeCharMask(lastByteSplitIdx);
		changeCharEndianness(screen[lastByteIdx + heightIdx]);
		return;
	}

	void printScreen(unsigned char* screen, const uint32_t width, const uint32_t height) {
		printf("Screen width = %d height = %d\n", width, height);
		uint32_t widthChar = width / 8;
		for (uint32_t col = 0; col < height; col++) {
			for (uint32_t row = 0; row < widthChar; row++) {
				cout << bitset<8>(screen[row + (col * widthChar)]);
			}
			cout << endl;
		}
	}
};

int main() {
	EX_05_8 solution;
	unsigned char TFT[TFT_WIDTH * TFT_HEIGHT] = { 0 };
	uint32_t size = TFT_WIDTH * TFT_HEIGHT;

	solution.drawLine(TFT, size, TFT_WIDTH, 4, 35, 0);
	solution.printScreen(TFT, TFT_WIDTH, TFT_HEIGHT);

	return 0;
}