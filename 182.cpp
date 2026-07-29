#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    int minCut(std::string s) {
        int n = s.length();
        if (n <= 1) return 0;

        // dp[i] stores the minimum cuts needed for the prefix s[0...i]
        std::vector<int> dp(n);
        for (int i = 0; i < n; ++i) {
            dp[i] = i; // Maximum possible cuts (cut after every character)
        }

        // Helper lambda to expand around a center and update min cuts
        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (left == 0) {
                    dp[right] = 0; // s[0...right] is a complete palindrome, 0 cuts needed
                } else {
                    dp[right] = std::min(dp[right], dp[left - 1] + 1);
                }
                left--;
                right++;
            }
        };

        // Iterate through all possible palindrome centers
        for (int i = 0; i < n; ++i) {
            expandAroundCenter(i, i);     // Odd-length palindromes (e.g., "aba")
            expandAroundCenter(i, i + 1); // Even-length palindromes (e.g., "abba")
        }

        return dp[n - 1];
    }
};

int main() {
    Solution solver;
    std::string s = "aab";
    std::cout << "Minimum cuts needed for '" << s << "': " << solver.minCut(s) << std::endl; // Output: 1
    return 0;
}
