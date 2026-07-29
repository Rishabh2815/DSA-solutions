#include <bits/stdc++.h>
using namespace std;
class Solution {
    // Min-heap to store the top k largest elements
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int size;

public:
    // Constructor to initialize the heap with initial elements
    Solution(int k, vector<int>& nums) {
        size = k;

        // Add each number to the heap
        for (int num : nums) {
            minHeap.push(num);

            // If heap exceeds size k, remove the smallest element
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
    }

    // Adds a new value to the stream and returns the k-th largest
    int add(int val) {
        // Insert the new element
        minHeap.push(val);

        // If size exceeds k, remove the smallest (to maintain top k largest)
        if (minHeap.size() > size) {
            minHeap.pop();
        }

        // The top of min-heap is the k-th largest
        return minHeap.top();
    }
};

// Driver code
int main() {
    vector<int> nums = {4, 5, 8, 2};
    Solution kthLargest(3, nums);
    cout << kthLargest.add(3) << endl;  // Output: 4
    cout << kthLargest.add(5) << endl;  // Output: 5
    cout << kthLargest.add(10) << endl; // Output: 5
    cout << kthLargest.add(9) << endl;  // Output: 8
    cout << kthLargest.add(4) << endl;  // Output: 8
    return 0;
}
