#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int largestRectangleArea(vector<int> &histo) {
        stack<int> st; // Stack to store indices of the histogram bars
        int maxA = 0;  // Variable to keep track of the maximum area
        int n = histo.size();

        // Loop through each bar including an imaginary bar at the end
        for (int i = 0; i <= n; i++) {
            // While current bar is smaller than the top of the stack or we reached the end
            while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
                int height = histo[st.top()]; // Get the height of the bar at top of the stack
                st.pop(); // Remove that bar

                int width;
                if (st.empty()) {
                    width = i; // All bars before were higher
                } else {
                    width = i - st.top() - 1; // Width between current index and index at top of stack
                }

                // Calculate area and update maximum area
                maxA = max(maxA, width * height);
            }
            // Push current index into stack
            st.push(i);
        }
        return maxA;
    }
};

int main() {
    vector<int> histo = {2, 1, 5, 6, 2, 3, 1}; // Input histogram
    Solution obj;
    cout << "The largest area in the histogram is " << obj.largestRectangleArea(histo) << endl;
    return 0;
}
