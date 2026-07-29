#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Rabin-Karp string matching function
    vector<int> rabinKarp(string text, string pattern) {
        vector<int> result;

        int n = text.length();
        int m = pattern.length();
        if (m > n) return result;

        // Base for the rolling hash (number of possible characters)
        int base = 256;
        // A large prime number for modulus to avoid overflow and reduce collisions
        int mod = 101;

        int patternHash = 0;
        int windowHash = 0;
        int h = 1;

        // Precompute the value of base^(m-1) % mod
        for (int i = 0; i < m - 1; i++) {
            h = (h * base) % mod;
        }

        // Compute initial hash values for pattern and first window of text
        for (int i = 0; i < m; i++) {
            patternHash = (base * patternHash + pattern[i]) % mod;
            windowHash = (base * windowHash + text[i]) % mod;
        }

        // Slide the window over the text
        for (int i = 0; i <= n - m; i++) {
            // If the hash values match, check characters one by one
            if (patternHash == windowHash) {
                bool match = true;
                for (int j = 0; j < m; j++) {
                    if (text[i + j] != pattern[j]) {
                        match = false;
                        break;
                    }
                }
                if (match) result.push_back(i);
            }

            // Calculate hash for next window using rolling hash
            if (i < n - m) {
                windowHash = (base * (windowHash - text[i] * h) 
                                             + text[i + m]) % mod;

                // Ensure non-negative hash
                if (windowHash < 0) windowHash += mod;
            }
        }

        return result;
    }
};

int main() {
    string text = "ababcabdababc";
    string pattern = "abc";

    Solution sol;
    vector<int> indices = sol.rabinKarp(text, pattern);

    cout << "Pattern found at indices: ";
    for (int index : indices) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}