#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Recursive function with memoization
    int solve(vector<int>& arr, int i, int j, vector<vector<int>>& dp) {
        // Base case: only one matrix, no multiplication
        if (i == j) return 0;

        // If already computed, return from dp
        if (dp[i][j] != -1) return dp[i][j];

        // Initialize min cost as very large
        int minCost = INT_MAX;

        // Try every partition
        for (int k = i; k < j; k++) {
            int cost1 = solve(arr, i, k, dp);
            int cost2 = solve(arr, k + 1, j, dp);
            int costMultiply = arr[i - 1] * arr[k] * arr[j];

            int total = cost1 + cost2 + costMultiply;

            minCost = min(minCost, total);
        }

        // Store and return result
        return dp[i][j] = minCost;
    }

    // Function to start the memoization approach
    int matrixChainOrder(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(arr, 1, n - 1, dp);
    }
};

// Driver code
int main() {
    Solution sol;
    vector<int> arr = {40, 20, 30, 10, 30};
    cout << "Minimum number of multiplications is: "
         << sol.matrixChainOrder(arr) << endl;
    return 0;
}
