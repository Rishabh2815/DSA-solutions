#include <bits/stdc++.h>
using namespace std;

class Solution {

public:

    // Function to compute LCS using 2-row DP
    int lcs(string s1, string s2) {

        // Get sizes
        int n = s1.size();
        int m = s2.size();

        // Initialize prev and cur rows
        vector<int> prev(m + 1, 0), cur(m + 1, 0);

        // Fill rows
        for (int ind1 = 1; ind1 <= n; ind1++) {
            for (int ind2 = 1; ind2 <= m; ind2++) {

                // If characters match
                if (s1[ind1 - 1] == s2[ind2 - 1])
                    cur[ind2] = 1 + prev[ind2 - 1];

                // Else take max from prev row or left
                else
                    cur[ind2] = max(prev[ind2], cur[ind2 - 1]);
            }

            // Move cur to prev
            prev = cur;
        }

        // Return result
        return prev[m];
    }

    // Function to compute LPS
    int longestPalindromeSubsequence(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        return lcs(s, t);
    }

    // Function to compute min insertions
    int minInsertion(string s) {
        int n = s.size();
        int k = longestPalindromeSubsequence(s);
        return n - k;
    }
};

int main() {
    Solution sol;
    string s = "abcaa";
    cout << "The Minimum insertions required to make string palindrome: "
         << sol.minInsertion(s) << endl;
    return 0;
}