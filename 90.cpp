#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// Function to find the maximum of minimums for every window size
vector<int> maxOfMin(const vector<int>& arr) {
    int n = arr.size();
    
    // Arrays to store indices of nearest smaller elements
    vector<int> left(n, -1);
    vector<int> right(n, n);
    stack<int> s;

    // Step 1: Find nearest smaller element on the left
    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        if (!s.empty()) {
            left[i] = s.top();
        }
        s.push(i);
    }

    // Clear stack to reuse for right bounds
    while (!s.empty()) {
        s.pop();
    }

    // Step 2: Find nearest smaller element on the right
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        if (!s.empty()) {
            right[i] = s.top();
        }
        s.push(i);
    }

    // Step 3: Populate the max of mins for unique maximum window sizes
    // ans[i] will store the result for window size i (1-indexed)
    vector<int> ans(n + 1, 0); 

    for (int i = 0; i < n; i++) {
        // Max length of the window where arr[i] is the minimum
        int len = right[i] - left[i] - 1;

        // Update the answer for this specific window length
        ans[len] = max(ans[len], arr[i]);
    }

    // Step 4: Fill entries that don't have a direct mapping.
    // If a value is a min for a window of size x, it can also be a min for size x-1.
    for (int i = n - 1; i >= 1; i--) {
        ans[i] = max(ans[i], ans[i + 1]);
    }

    // Remove the 0-th dummy index and return 1-based size mappings
    ans.erase(ans.begin());
    return ans;
}

int main() {
    vector<int> arr = {10, 20, 30, 50, 10, 70, 30};
    
    vector<int> result = maxOfMin(arr);
    
    cout << "Window Size:    ";
    for (int i = 1; i <= arr.size(); i++) cout << i << "  ";
    cout << "\nMax of Mins:    ";
    for (int val : result) cout << val << " ";
    cout << endl;

    return 0;
}
