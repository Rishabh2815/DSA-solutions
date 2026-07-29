#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int findKthLargest(vector<int>& arr, int k) {
    // Min-heap declaration using priority_queue
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Step 1: Push the first k elements into the min-heap
    for (int i = 0; i < k; i++) {
        minHeap.push(arr[i]);
    }

    // Step 2: Loop through the remaining elements of the array
    for (int i = k; i < arr.size(); i++) {
        // If current element is greater than the smallest in the heap
        if (arr[i] > minHeap.top()) {
            minHeap.pop();      // Remove the smallest element
            minHeap.push(arr[i]); // Add the larger element
        }
    }

    // The top of the min-heap is now the k-th largest element
    return minHeap.top();
}

int main() {
    vector<int> arr = {3, 5, 4, 2, 9};
    int k = 3;
    
    cout << "The " << k << "-th largest element is: " << findKthLargest(arr, k) << endl;
    
    return 0;
}
