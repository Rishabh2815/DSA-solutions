#include <iostream>
#include <string>
#include <algorithm>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.empty()) return "";
        
        int start = 0;
        int maxLen = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            // Case 1: Odd length palindromes (e.g., "aba", center is 'b')
            int len1 = expandFromCenter(s, i, i);
            
            // Case 2: Even length palindromes (e.g., "bbaa", center is between 'b' and 'a')
            int len2 = expandFromCenter(s, i, i + 1);
            
            int len = std::max(len1, len2);
            
            // Update the boundaries of the longest palindrome found so far
            if (len > maxLen) {
                maxLen = len;
                // Calculate starting index based on the length and center position
                start = i - (len - 1) / 2;
            }
        }
        
        return s.substr(start, maxLen);
    }

private:
    int expandFromCenter(const std::string& s, int left, int right) {
        // Expand outwards as long as characters match and indices are valid
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        // Return the total length of the valid palindrome found
        return right - left - 1;
    }
};

int main() {
    Solution solver;
    std::string input = "babad";
    std::string result = solver.longestPalindrome(input);
    
    std::cout << "Longest Palindromic Substring: " << result << std::endl; 
    // Output will be "bab" or "aba"
    
    return 0;
}
