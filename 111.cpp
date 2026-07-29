#include <bits/stdc++.h>
using namespace std;

// Structure representing each node of the binary tree
struct Node {
    // Value stored in the node
    int data;
    // Pointer to the left child
    Node* left;
    // Pointer to the right child
    Node* right;
    // Constructor to initialize a node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Class containing the logic for top view
class Solution {
public:
    // Function to return the top view of the binary tree
    vector<int> topView(Node* root) {
        // Create a vector to store the final answer
        vector<int> ans;

        // If the tree is empty, return an empty result
        if (root == NULL) {
            return ans;
        }

        // Create a map to store vertical level -> node value (only first encountered)
        map<int, int> mpp;

        // Create a queue for BFS that stores {node, vertical_level}
        queue<pair<Node*, int>> q;

        // Push the root node with vertical level 0
        q.push({root, 0});

        // Start BFS traversal
        while (!q.empty()) {
            // Extract the front element of the queue
            auto it = q.front();
            q.pop();

            // Get the node and its vertical position
            Node* node = it.first;
            int line = it.second;

            // If this vertical position is being visited for the first time, store it
            if (mpp.find(line) == mpp.end()) {
                mpp[line] = node->data;
            }

            // If there is a left child, push it with vertical level - 1
            if (node->left != NULL) {
                q.push({node->left, line - 1});
            }

            // If there is a right child, push it with vertical level + 1
            if (node->right != NULL) {
                q.push({node->right, line + 1});
            }
        }

        // Traverse the map and store values in the answer vector
        for (auto it : mpp) {
            ans.push_back(it.second);
        }

        // Return the result
        return ans;
    }
};

// Driver code
int main() {
    // Create the sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(10);
    root->right->left = new Node(9);

    // Create a Solution object
    Solution solution;

    // Get the top view
    vector<int> result = solution.topView(root);

    // Print the top view traversal
    cout << "Top View Traversal: ";
    for (auto node : result) {
        cout << node << " ";
    }
    return 0;
}
