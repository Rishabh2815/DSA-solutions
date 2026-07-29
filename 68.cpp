#include <bits/stdc++.h>
using namespace std;

// Class to solve Aggressive Cows problem
class Solution {
public:
    // Function to check if we can place all cows with at least 'd' distance
    bool canPlace(vector<int>& stalls, int cows, int d) {
        // Place first cow at the first stall
        int count = 1;
        int lastPos = stalls[0];

        // Loop through all stalls
        for (int i = 1; i < stalls.size(); i++) {
            // Check if this stall is at least 'd' away from last placed cow
            if (stalls[i] - lastPos >= d) {
                // Place the cow here
                count++;
                // Update last placed cow position
                lastPos = stalls[i];
            }
            // If all cows are placed successfully
            if (count >= cows) return true;
        }
        // Return false if we could not place all cows
        return false;
    }

    // Function to maximize minimum distance between cows
    int aggressiveCows(vector<int>& stalls, int cows) {
        // Sort the stalls
        sort(stalls.begin(), stalls.end());

        // Define search space
        int low = 1;
        int high = stalls.back() - stalls.front();
        int ans = 0;

        // Apply binary search
        while (low <= high) {
            // Find mid distance
            int mid = low + (high - low) / 2;

            // If placing cows is possible with mid distance
            if (canPlace(stalls, cows, mid)) {
                // Store this as potential answer
                ans = mid;
                // Try to find larger minimum distance
                low = mid + 1;
            }
            else {
                // Otherwise try smaller distance
                high = mid - 1;
            }
        }
        // Return the largest minimum distance
        return ans;
    }
};

// Driver function
int main() {
    // Input stalls
    vector<int> stalls = {1, 2, 8, 4, 9};
    // Number of cows
    int cows = 3;

    // Create object
    Solution obj;
    // Print result
    cout << obj.aggressiveCows(stalls, cows) << endl;
    return 0;
}


