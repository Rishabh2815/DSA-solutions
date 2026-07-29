#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to calculate trapped rainwater using the optimal two-pointer approach
    int trap(vector<int>& height) {
        int n = height.size();
        
        // Initialize two pointers at both ends of the array
        int left = 0;
        int right = n - 1;
        
        // Variables to track the maximum height to the left and right
        int maxLeft = 0;
        int maxRight = 0;
        
        // Variable to store total trapped water
        int totalWater = 0;
        
        // Iterate until left pointer meets right pointer
        while (left <= right) {
            // If left bar is smaller or equal to right bar
            if (height[left] <= height[right]) {
                // If current left bar is higher than maxLeft, update maxLeft
                if (height[left] >= maxLeft) {
                    maxLeft = height[left];
                } else {
                    // Water trapped on left is difference between maxLeft and current height
                    totalWater += maxLeft - height[left];
                }
                left++; // Move left pointer to the right
            } else {
                // If current right bar is higher than maxRight, update maxRight
                if (height[right] >= maxRight) {
                    maxRight = height[right];
                } else {
                    // Water trapped on right is difference between maxRight and current height
                    totalWater += maxRight - height[right];
                }
                right--; // Move right pointer to the left
            }
        }
        
        // Return total trapped water
        return totalWater;
    }
};

// Driver code
int main() {
    // Input elevation map
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    
    // Create Solution object
    Solution sol;
    
    // Calculate trapped water
    int result = sol.trap(height);
    
    // Print the result
    cout << "Trapped Rainwater: " << result << endl;
    
    return 0;
}
