#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        // Ensure nums1 is the smaller array to optimize binary search runtime
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int low = 0, high = m;
        
        while (low <= high) {
            int partitionX = low + (high - low) / 2;
            int partitionY = (m + n + 1) / 2 - partitionX;
            
            // Edge cases: if partition is 0, use INT_MIN. If partition is at the end, use INT_MAX.
            int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int minRightX = (partitionX == m) ? INT_MAX : nums1[partitionX];
            
            int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minRightY = (partitionY == n) ? INT_MAX : nums2[partitionY];
            
            // Check if we found the correct partition
            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                // If total elements are odd
                if ((m + n) % 2 != 0) {
                    return std::max(maxLeftX, maxLeftY);
                }
                // If total elements are even
                return (std::max(maxLeftX, maxLeftY) + std::min(minRightX, minRightY)) / 2.0;
            }
            // Move left in nums1
            else if (maxLeftX > minRightY) {
                high = partitionX - 1;
            }
            // Move right in nums1
            else {
                low = partitionX + 1;
            }
        }
        
        return 0.0; // Input arrays were not sorted or invalid
    }
};

int main() {
    Solution solution;
    std::vector<int> nums1 = {1, 3};
    std::vector<int> nums2 = {2};
    
    std::cout << "Median: " << solution.findMedianSortedArrays(nums1, nums2) << std::endl;
    return 0;
}
