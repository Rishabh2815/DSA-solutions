#include <iostream>
#include <vector>
using namespace std;

int maxSumIS(vector<int>& arr) {
    
    // key = value in arr, value = max sum ending 
    // with that value or less than that value
    map<int, int> dp; 
    int ans = 0;

    for (int val : arr) {
        
        // Find the best sum among 
        // all elements smaller than val
        auto it = dp.lower_bound(val);
        int bestSmaller = 0;
        if (it != dp.begin()) {
            --it;
            bestSmaller = it->second;
        }

        int currSum = bestSmaller + val;

        // If this value gives a 
        // better sum, update TreeMap
        if (dp[val] < currSum) {
            dp[val] = currSum;

            // Remove entries with greater 
            // keys with smaller or equal sums
            auto higher = dp.upper_bound(val);
            while (higher != dp.end() && higher->second <= currSum) {
                higher = dp.erase(higher);
            }
        }

        ans = max(ans, currSum);
    }

    return ans;
}

int main() {
    vector<int> arr = {1, 101, 2, 3, 100};
    cout << maxSumIS(arr);
}