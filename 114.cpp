#include <bits/stdc++.h>
using namespace std;

// Structure for a binary tree node
struct TreeNode {
    // Value of the node
    int val;

    // Pointers to left and right children
    TreeNode* left;
    TreeNode* right;

    // Constructor to initialize the node
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Class containing the solution
class Solution {
public:
    // Function to find the path from root to node with value x
    bool getPath(TreeNode* root, vector<int>& arr, int x) {
        // If current node is NULL, return false
        if (!root) {
            return false;
        }

        // Add current node's value to the path
        arr.push_back(root->val);

        // If current node's value is equal to x, return true
        if (root->val == x) {
            return true;
        }

        // Recursively search in left or right subtree
        if (getPath(root->left, arr, x) ||
            getPath(root->right, arr, x)) {
            return true;
        }

        // If not found, backtrack and remove current node
        arr.pop_back();
        return false;
    }

    // Function to get the path from root to node with value B
    vector<int> solve(TreeNode* A, int B) {
        // Vector to store the path
        vector<int> arr;

        // If root is NULL, return empty path
        if (A == NULL) {
            return arr;
        }

        // Call helper function to fill the path
        getPath(A, arr, B);

        // Return the resulting path
        return arr;
    }
};

// Main function to run the code
int main() {
    // Creating the binary tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    // Create an instance of the solution class
    Solution sol;

    // Value of the target node
    int targetLeafValue = 7;

    // Get the path from root to the target node
    vector<int> path = sol.solve(root, targetLeafValue);

    // Print the path
    cout << "Path from root to node with value ";
    cout << targetLeafValue << ": ";

    for (int i = 0; i < path.size(); ++i) {
        cout << path[i];
        if (i < path.size() - 1) {
            cout << " -> ";
        }
    }

    return 0;
}
