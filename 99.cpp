#include <string>
#include <vector>

class Solution {
private:
    // Helper function to build the Longest Proper Prefix which is also Suffix array
    std::vector<int> computeLPS(const std::string& pattern) {
        int m = pattern.length();
        std::vector<int> lps(m, 0);
        int len = 0; // Length of the previous longest prefix suffix
        int i = 1;

        while (i < m) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    // Fall back to the previous longest prefix suffix match
                    len = lps[len - 1];
                } else {
                    // No prefix suffix match exists for this position
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

public:
    int strStr(std::string haystack, std::string needle) {
        if (needle.empty()) return 0;
        
        int n = haystack.length();
        int m = needle.length();
        
        // Base constraint exit condition
        if (n < m) return -1;

        // Step 1: Preprocess the pattern to get the LPS array
        std::vector<int> lps = computeLPS(needle);

        int i = 0; // Pointer for haystack
        int j = 0; // Pointer for needle

        // Step 2: Search the pattern in the haystack
        while (i < n) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }

            if (j == m) {
                // Entire pattern matched successfully
                return i - m; 
            } else if (i < n && haystack[i] != needle[j]) {
                // Mismatch occurred after j matches
                if (j != 0) {
                    j = lps[j - 1]; // Skip redundant checking
                } else {
                    i++; // No match at all, move to next haystack character
                }
            }
        }
        return -1;
    }
};
