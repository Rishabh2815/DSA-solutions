#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to sort array containing 0s, 1s, and 2s using Dutch National Flag Algorithm
    void sortZeroOneTwo(vector<int>& nums) {
        // Initialize three pointers: low, mid starting from 0, high from end of array
        int low = 0, mid = 0, high = nums.size() - 1;

        // Process elements until mid pointer crosses high pointer
        while (mid <= high) {
            // If current element is 0, swap with low and move both pointers forward
            if (nums[mid] == 0) {
                swap(nums[mid], nums[low]);
                mid++;
                low++;
            }
            // If current element is 1, it's already in correct place → move mid forward
            else if (nums[mid] == 1) {
                mid++;
            }
            // If current element is 2, swap with high and move only high pointer backward
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

// Driver code
int main() {
    Solution obj;
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    obj.sortZeroOneTwo(nums);

    for (int val : nums)
        cout << val << " ";

    return 0;
}