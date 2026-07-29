#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find k maximum sum combinations
    vector<int> maxCombinations(vector<int>& nums1, vector<int>& nums2, int k) {

        // Sort both arrays in descending order
        sort(nums1.begin(), nums1.end(), greater<int>());
        sort(nums2.begin(), nums2.end(), greater<int>());

        // Max-heap to store pairs with their indices
        priority_queue<tuple<int, int, int>> maxHeap;

        // Set to keep track of visited index pairs
        set<pair<int, int>> visited;

        // Push the initial maximum pair (nums1[0] + nums2[0])
        maxHeap.push({nums1[0] + nums2[0], 0, 0});
        visited.insert({0, 0});

        // Vector to store the result
        vector<int> result;

        // Extract top k elements from the heap
        while(k-- && !maxHeap.empty()) {

            // Get the current maximum sum and its indices
            auto [sum, i, j] = maxHeap.top();
            maxHeap.pop();

            // Add this sum to the result
            result.push_back(sum);

            // If (i + 1, j) is valid and not visited, add it to the heap
            if(i + 1 < nums1.size() && !visited.count({i + 1, j})) {
                maxHeap.push({nums1[i + 1] + nums2[j], i + 1, j});
                visited.insert({i + 1, j});
            }

            // If (i, j + 1) is valid and not visited, add it to the heap
            if(j + 1 < nums2.size() && !visited.count({i, j + 1})) {
                maxHeap.push({nums1[i] + nums2[j + 1], i, j + 1});
                visited.insert({i, j + 1});
            }
        }

        // Return the final k max combinations
        return result;
    }
};

// Driver code
int main() {
    Solution sol;
    vector<int> nums1 = {7, 3};
    vector<int> nums2 = {1, 6};
    int k = 2;
    vector<int> result = sol.maxCombinations(nums1, nums2, k);
    for(int val : result) cout << val << " ";
    return 0;
}
