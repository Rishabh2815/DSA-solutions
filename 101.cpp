#include <bits/stdc++.h>
using namespace std;

// Function to check if two strings are anagrams
bool CheckAnagrams(string str1, string str2) {
    // Case: when both of the strings have different lengths
    if (str1.length() != str2.length()) 
        return false;

    // Initialize a frequency array to store character counts
    int freq[26] = {0};

    // Count frequency of each character in str1
    for (int i = 0; i < str1.length(); i++) {
        freq[str1[i] - 'A']++;  // Increment frequency for each character in str1
    }

    // Decrement frequency for each character in str2
    for (int i = 0; i < str2.length(); i++) {
        freq[str2[i] - 'A']--;  // Decrement frequency for each character in str2
    }

    // Check if all frequencies are zero, meaning both strings have the same characters
    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0)  // If any frequency is non-zero, they are not anagrams
            return false;
    }

    return true;  // The strings are anagrams
}

int main() {
    string Str1 = "INTEGER";
    string Str2 = "TEGERNI";

    // Check if the strings are anagrams and output the result
    if (CheckAnagrams(Str1, Str2))
        cout << "True" << endl;  // Output "True" if they are anagrams
    else
        cout << "False" << endl;  // Output "False" if they aren't anagrams

    return 0;
}
