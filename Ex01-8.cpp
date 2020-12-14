/*
	Zero Matrix: Write an algorithm such that if an element in an MxN matrix is 0, its entire row and
	column are set to 0.
	Hints:#17, #74, #702
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class EX_01_8 {
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
public:
	void zeroMatrix(vector<vector<int>>& mData) {
		prettyPrint(mData);
		int rows = mData[0].size();
		int cols = mData.size();

		stack<pair<int, int>> toZero;

		// Find all zero elements and push them in stack
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (mData[i][j] == 0) {
					int row_idx = i;
					int col_idx = j;
					toZero.push(make_pair(row_idx, col_idx));
				}
			}
		}
		// Pop the stack and start applying zeroing
		while (!toZero.empty()) {
			auto ptr = toZero.top();
			int row_idx = ptr.first;
			int col_idx = ptr.second;

			// Zero Row
			for (int x = 0; x < cols; x++) {
				mData[row_idx][x] = 0;
			}
			// Zero Column
			for (int x = 0; x < rows; x++) {
				mData[x][col_idx] = 0;
			}
			toZero.pop();
		}
		prettyPrint(mData);
	}
};

int main() {
	EX_01_8 Solution;
	vector<vector<int>> mData = { {1,0,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,0} };

	Solution.zeroMatrix(mData);
}