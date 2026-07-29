#include <bits/stdc++.h>
using namespace std;

// Structure for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize node
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Function to perform inorder traversal and store elements
    void inorderTraversal(Node* root, vector<int>& arr) {
        // Base case
        if (!root) return;
        // Traverse left subtree
        inorderTraversal(root->left, arr);
        // Store current node data
        arr.push_back(root->data);
        // Traverse right subtree
        inorderTraversal(root->right, arr);
    }

    // Function to merge two sorted arrays
    vector<int> mergeArrays(vector<int>& arr1, vector<int>& arr2) {
        // Initialize result array
        vector<int> merged;
        // Initialize pointers
        int i = 0, j = 0;
        // Merge until one array ends
        while (i < arr1.size() && j < arr2.size()) {
            if (arr1[i] < arr2[j]) merged.push_back(arr1[i++]);
            else merged.push_back(arr2[j++]);
        }
        // Add remaining elements
        while (i < arr1.size()) merged.push_back(arr1[i++]);
        while (j < arr2.size()) merged.push_back(arr2[j++]);
        return merged;
    }

    // Function to merge two BSTs in sorted order
    vector<int> mergeBSTs(Node* root1, Node* root2) {
        // Arrays to store inorder traversals
        vector<int> arr1, arr2;
        // Perform inorder traversal on first BST
        inorderTraversal(root1, arr1);
        // Perform inorder traversal on second BST
        inorderTraversal(root2, arr2);
        // Merge and return the result
        return mergeArrays(arr1, arr2);
    }
};

// Driver code
int main() {
    // Create first BST
    Node* root1 = new Node(3);
    root1->left = new Node(1);
    root1->right = new Node(5);

    // Create second BST
    Node* root2 = new Node(4);
    root2->left = new Node(2);
    root2->right = new Node(6);

    // Create Solution object
    Solution sol;
    // Merge the BSTs
    vector<int> result = sol.mergeBSTs(root1, root2);

    // Print result
    for (int val : result) cout << val << " ";
    return 0;
}
