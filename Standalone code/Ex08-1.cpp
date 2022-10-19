/*
	Triple Step: A child is running up a staircase with n steps and can hop either 1 step, 2 steps, or 3
	steps at a time. Implement a method to count how many possible ways the child can run up the stairs
*/

#include <iostream>
#include <unordered_map>

using namespace std;

// Solution with Recursion no DP , no Memoization
class Ex08_1_Recursion {
public:
	// Tail Recursion Case
	long long climbStairs(int n) {
		// Base Cases
		if (n <= 0) { return 0; }
		else if (n == 1) { return 1; }
		else if (n == 2) { return 2; }
		else if (n == 3) { return 4; }
		// Recursive Relation
		return climbStairs(n - 1) + climbStairs(n - 2) + climbStairs(n - 3);
	}
};

// Solution with Recursion with Memoization DP
class Ex08_1_DP {
private:
	// Memoization helper
	long long countWays(int n, vector<long long>& memo) {
		// Base Cases
		if (n == 0) { return 0; }
		else if (n == 1) { return 1; }
		else if (n == 2) { return 2; }
		else if (n == 3) { return 4; }
		// If not in Memo array then add it
		if (memo[n] == -1) {
			memo[n] = countWays(n - 1, memo) + countWays(n - 2, memo) + countWays(n - 3, memo);
		}
		return memo[n];
	}

public:
	long long climbStairs(int n) {
		vector<long long> tracker((size_t)n + 1, -1);
		return countWays(n, tracker);
	}
};

//int main() {
//	Ex08_1_DP solution;
//	cout << solution.climbStairs(40);
//	getchar();
//	return 0;
//}