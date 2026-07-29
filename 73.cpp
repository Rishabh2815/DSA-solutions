#include <iostream>
#include <vector>
#include <queue>

// Structure to store element info: {value, array_index, element_index}
struct HeapNode {
    int value;
    int arrayIdx;
    int elementIdx;

    // Custom constructor
    HeapNode(int v, int a, int e) : value(v), arrayIdx(a), elementIdx(e) {}

    // Greater-than operator to turn max-heap into a min-heap
    bool operator>(const HeapNode& other) const {
        return value > other.value;
    }
};

std::vector<int> mergeKSortedArrays(const std::vector<std::vector<int>>& arrays) {
    std::vector<int> result;
    
    // Min-heap tracking the smallest active element of each array
    std::priority_queue<HeapNode, std::vector<HeapNode>, std::greater<HeapNode>> minHeap;

    // Step 1: Insert the first element of each non-empty array into the min-heap
    for (int i = 0; i < arrays.size(); ++i) {
        if (!arrays[i].empty()) {
            minHeap.push(HeapNode(arrays[i][0], i, 0));
        }
    }

    // Step 2: Process elements until the heap is empty
    while (!minHeap.empty()) {
        HeapNode current = minHeap.top();
        minHeap.pop();

        // Append the smallest extracted element to our result
        result.push_back(current.value);

        // If the same array has a next element, push it into the heap
        int nextElementIdx = current.elementIdx + 1;
        if (nextElementIdx < arrays[current.arrayIdx].size()) {
            minHeap.push(HeapNode(
                arrays[current.arrayIdx][nextElementIdx], 
                current.arrayIdx, 
                nextElementIdx
            ));
        }
    }

    return result;
}

int main() {
    std::vector<std::vector<int>> arrays = {
        {1, 5, 9},
        {2, 6, 8},
        {3, 7, 10}
    };

    std::vector<int> mergedArray = mergeKSortedArrays(arrays);

    std::cout << "Merged Array: ";
    for (int num : mergedArray) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
