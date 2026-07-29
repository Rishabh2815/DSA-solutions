#include <bits/stdc++.h>
using namespace std;

// Class definition for a binary tree node
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    // Constructor to initialize the node value
    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

// Class containing the method to find maximum width
class Solution {
public:
    // Function to compute the maximum width of binary tree
    int widthOfBinaryTree(TreeNode* root) {

        // If the tree is empty, return 0
        if (!root)
            return 0;

        // Initialize maximum width as 0
        int maxWidth = 0;

        // Queue to perform level-order traversal
        // Each element is a pair of node and its index
        queue<pair<TreeNode*, int>> q;

        // Push root node with index 0
        q.push({root, 0});

        // Continue BFS until queue becomes empty
        while (!q.empty()) {

            // Get the number of nodes at current level
            int size = q.size();

            // Store the index of the first node at this level
            int minIndex = q.front().second;

            // Initialize variables to track first and last index
            int first = 0;
            int last = 0;

            // Traverse all nodes at the current level
            for (int i = 0; i < size; i++) {

                // Get the current node and its relative index
                int currIndex = q.front().second - minIndex;
                TreeNode* node = q.front().first;

                // Pop the current node from the queue
                q.pop();

                // Update the first index if it's the first node
                if (i == 0)
                    first = currIndex;

                // Update the last index if it's the last node
                if (i == size - 1)
                    last = currIndex;

                // If left child exists, push it with calculated index
                if (node->left)
                    q.push({node->left, 2 * currIndex + 1});

                // If right child exists, push it with calculated index
                if (node->right)
                    q.push({node->right, 2 * currIndex + 2});
            }

            // Update the maximum width if needed
            maxWidth = max(maxWidth, last - first + 1);
        }

        // Return the result
        return maxWidth;
    }
};

// Main driver function
int main() {

    // Create a sample tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);

    // Create solution object
    Solution sol;

    // Call the function and print the result
    cout << "Maximum width: " << sol.widthOfBinaryTree(root) << endl;

    return 0;
}
