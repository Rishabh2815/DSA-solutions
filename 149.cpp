#include <bits/stdc++.h>
using namespace std;

vector<int> countDistinct(vector<int>& arr, int k) {
    vector<int> result;
    unordered_map<int, int> mp;

    // Store frequency for the first window
    for (int i = 0; i < k; i++) {
        mp[arr[i]]++;
    }
    result.push_back(mp.size());

    // Traverse for the rest of the array
    for (int i = k; i < arr.size(); i++) {
        // Remove the element going out of the window
        int removeElement = arr[i - k];
        if (mp[removeElement] == 1) {
            mp.erase(removeElement);
        } else {
            mp[removeElement]--;
        }

        // Add the new element entering the window
        mp[arr[i]]++;
        result.push_back(mp.size());
    }
    return result;
}
