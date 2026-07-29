#include <bits/stdc++.h>
using namespace std;

// Class to solve 0/1 Knapsack using space optimization
class Solution {
public:
    // Function to compute maximum value
    int knapSack(int W, vector<int>& wt, vector<int>& val, int n) {
        // Create prev array to store previous row values
        vector<int> prev(W + 1, 0);
        
        // Base case: fill first row
        for (int w = wt[0]; w <= W; w++) {
            prev[w] = val[0];
        }
        
        // Iterate for each item
        for (int ind = 1; ind < n; ind++) {
            // Create current row
            vector<int> curr(W + 1, 0);
            for (int w = 0; w <= W; w++) {
                // Exclude current item
                int notTaken = prev[w];
                
                // Include current item if possible
                int taken = INT_MIN;
                if (wt[ind] <= w) 
                    taken = val[ind] + prev[w - wt[ind]];
                
                // Store max
                curr[w] = max(notTaken, taken);
            }
            // Update prev row
            prev = curr;
        }
        // Final answer
        return prev[W];
    }
};

// Driver code
int main() {
    int n = 4, W = 7;
    vector<int> wt = {1, 3, 4, 5};
    vector<int> val = {1, 4, 5, 7};
    Solution obj;
    cout << obj.knapSack(W, wt, val, n) << endl;
    return 0;
}