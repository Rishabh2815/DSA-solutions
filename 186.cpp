#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Trie Node Definition
struct Node {
    Node* links[26] = {nullptr};
    bool isEnd = false;

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        isEnd = true;
    }

    bool checkEnd() {
        return isEnd;
    }
};

// Trie Class Configuration
class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    // Inserts a word into the trie
    void insert(const string& word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }

    // Checks if all prefixes of the word exist in the trie
    bool checkIfAllPrefixesExist(const string& word) {
        Node* node = root;
        for (char ch : word) {
            if (node->containsKey(ch)) {
                node = node->get(ch);
                if (!node->checkEnd()) {
                    return false;
                }
            } else {
                return false;
            }
        }
        return true;
    }
};

string longestWordWithAllPrefixes(vector<string>& words) {
    Trie trie;
    
    // Step 1: Insert all words into the Trie
    for (const string& word : words) {
        trie.insert(word);
    }

    string longest = "";

    // Step 2: Validate each word against its prefixes
    for (const string& word : words) {
        if (trie.checkIfAllPrefixesExist(word)) {
            // Tie-breaking: Longest string, or lexicographically smaller if lengths match
            if (word.length() > longest.length()) {
                longest = word;
            } else if (word.length() == longest.length() && word < longest) {
                longest = word;
            }
        }
    }

    return longest.empty() ? "None" : longest;
}

int main() {
    vector<string> words = {"n", "ni", "nin", "ninj", "ninja", "nil"};
    cout << "Longest complete word: " << longestWordWithAllPrefixes(words) << endl; 
    // Output: ninja
    return 0;
}
