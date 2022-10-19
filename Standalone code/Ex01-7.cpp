/*
	Rotate Matrix: Given an image represented by an NxN matrix, where each pixel in the image is 4
	bytes, write a method to rotate the image by 90 degrees. Can you do this in place?
	Hints:#51, #100

*/

#include <iostream>
#include <vector>

using namespace std;

class Ex_01_7 {
private:
	// Helper Pretty Printer
	void prettyPrint(vector<vector<int>>& mData) {
		for (vector<int> vec : mData) {
			for (int i : vec) {
				printf("%02d | ", i);
			}
			cout << endl;
		}
		cout << endl;
	}

	// Transpose a NxN matrix
	void transposeMatrix(vector<vector<int>>& mData) {
		int N = mData.size();

		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				// Perform Swap
				int temp = mData[i][j];
				mData[i][j] = mData[j][i];
				mData[j][i] = temp;
			}
		}
	}

	// Standard reverse array
	void reverseVector(vector<int>& mData) {
		int size = mData.size();
		int half = size / 2;
		for (int i = 0; i < half; i++) {
			swap(mData[i], mData[size - 1 - i]);
		}
	}

public:
	// Rotate matrix by a certain degree , auto-reduced to 90 deg increments
	void rotateMatrix(vector<vector<int>>& mData, uint32_t degree) {
		prettyPrint(mData);
		// Sanity Check
		int rows = mData.size();
		for (int i = 0; i < rows; i++) {
			int cols = mData[i].size();
			if (rows != cols) {
				cout << "Not an NXN matrix!\n";
				return;
			}
		}

		int rotateCount = (degree / 90) % 4;

		for (int j = 0; j < rotateCount; j++) {
			transposeMatrix(mData);
			for (int i = 0; i < rows; i++) {
				reverseVector(mData[i]);
			}
		}
		prettyPrint(mData);
	}
};

//int main() {
//	Ex_01_7 Solution;
//
//	vector<vector<int>> mData = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
//
//	Solution.rotateMatrix(mData, 270);
//
//	return 0;
//}