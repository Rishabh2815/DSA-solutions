#include <bits/stdc++.h>
using namespace std;

// This function returns the maximum product subarray
// using prefix and suffix traversal
class Solution {
public:
    int maxProductSubArray(vector<int>& arr) {
        // Store size of array
        int n = arr.size();

        // Initialize prefix and suffix product
        int pre = 1, suff = 1;

        // Initialize answer to negative infinity
        int ans = INT_MIN;

        // Traverse from both left and right
        for (int i = 0; i < n; i++) {
            // Reset prefix if zero
            if (pre == 0) pre = 1;

            // Reset suffix if zero
            if (suff == 0) suff = 1;

            // Multiply prefix with current element from front
            pre *= arr[i];

            // Multiply suffix with current element from back
            suff *= arr[n - i - 1];

            // Update the maximum of all products seen so far
            ans = max(ans, max(pre, suff));
        }

        // Return the final answer
        return ans;
    }
};

int main() {
    // Sample input
    vector<int> arr = {2, 3, -2, 4};

    // Create object of solution
    Solution obj;

    // Call the function and print the result
    cout << obj.maxProductSubArray(arr) << endl;

    return 0;
}
