#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to solve the rod cutting problem
    int rodCutting(vector<int>& price, int n) {
        // Initialize DP table with dimensions [n + 1]
        vector<int> prev(n+1, 0), cur(n+1, 0);
        
        for(int length = 0; length <= n; length++){
            prev[length] = price[0]*length;
        }
        
        // Fill the DP table
        for (int ind = 1; ind < n; ++ind) { 
            for (int length = 1; length <= n; ++length) { 
                
                // Case when the piece is not taken
                int notTaken = 0+prev[length];
                
                // Case when the piece is taken
                int taken = INT_MIN;
                
                /* Length of the rod piece 
                corresponding to the current index*/
                int rodLength = ind + 1;
                
                // Check if the piece can be taken
                if (rodLength <= length) {
                    taken = price[ind] + cur[length - rodLength];
                }
                
                /* Update cur[length] with the maximum of 
                including or not including the current piece*/
                cur[length] = max(notTaken, taken);
            }
            prev = cur;
        }
        
        // Return the result 
        return prev[n];
    }
};

int main() {
    vector<int> price = {2, 4, 6, 8};
    int n = price.size();

    // Create an instance of Solution class
    Solution sol;

    // Print the result
    cout << "The Maximum value is " << sol.rodCutting(price, n) << endl;

    return 0;
}