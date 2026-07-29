#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minCut(std::string s) {
        int n = s.length();
        if (n <= 1) return 0;

        // isPalin[i][j] will be true if substring s[i..j] is a palindrome
        std::vector<std::vector<bool>> isPalin(n, std::vector<bool>(n, false));
        
        // dp[i] stores the minimum cuts needed for the prefix s[0..i]
        std::vector<int> dp(n, 0);

        for (int i = 0; i < n; ++i) {
            // Maximum cuts needed for s[0..i] is i cuts (cutting every single character)
            int minCuts = i; 
            
            for (int j = 0; j <= i; ++j) {
                // Check if s[j..i] is a palindrome
                // Condition 1: Characters at bounds must match (s[i] == s[j])
                // Condition 2: The inner substring must be a palindrome (isPalin[j+1][i-1]) 
                //              OR the distance between bounds is less than 2 (e.g., "a", "aa")
                if (s[i] == s[j] && (i - j < 2 || isPalin[j + 1][i - 1])) {
                    isPalin[j][i] = true;
                    
                    // If the entire prefix s[0..i] is a palindrome, 0 cuts are needed
                    if (j == 0) {
                        minCuts = 0;
                    } else {
                        // Otherwise, take 1 cut plus the minimum cuts needed for s[0..j-1]
                        minCuts = std::min(minCuts, dp[j - 1] + 1);
                    }
                }
            }
            dp[i] = minCuts;
        }

        return dp[n - 1];
    }
};

int main() {
    Solution solver;
    std::string s = "aab";
    std::cout << "Minimum cuts needed: " << solver.minCut(s) << std::endl; // Output: 1
    return 0;
}
