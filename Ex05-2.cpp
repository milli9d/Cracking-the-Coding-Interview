/*
	Binary to String: Given a real number between 0 and 1 (e.g., 0.72) that is passed in as a double,
	print the binary representation. If the number cannot be represented accurately in binary with at
	most 32 characters, print"ERROR:

*/
#include <iostream>
#include <bitset>
#include <unordered_map>

using namespace std;

class EX_05_02 {
private:
	unordered_map<int, double> valMap;

	void genVals() {
		for (int i = 0; i < 32; i++) {
			valMap.insert({ -i,pow(2,-i) * 100 });
		}
	}

public:
	EX_05_02() {
		genVals();
	}

	void printBin(double val) {
		// Sanity checks
		if (val < 0 || val > 1) { return; }
		if (val == 1) {
			printf("1.0");
			return;
		}
		else {
			printf("0.");
			double runningSum = 0;
			double reqVal = val * 100;
			int count = 1;
			while ((runningSum != reqVal) && count < 32) {
				auto ptr = valMap.find(-1 * count);
				if (ptr == valMap.end()) {
					printf("ERROR MAP NOT INITIALIZED.\n");
					return;
				}
				else {
					// Check if adding current ptr val will increase RunningSum above required val
					// IF yes then print 0
					if (runningSum + ptr->second > reqVal) {
						printf("0");
					}
					// If No print 1
					else {
						printf("1");
						runningSum += ptr->second;
					}
				}
				count++;
			}
		}
	}
};

int main() {
	EX_05_02 solution;
	solution.printBin(0.625);
	return 0;
}