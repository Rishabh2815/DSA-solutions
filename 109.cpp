#include <bits/stdc++.h>
using namespace std;

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Recursive function to get left view
    void leftDFS(TreeNode* node, int level, vector<int>& res) {
        // Base case: null node
        if (!node) return;

        // If this is the first node at the current level
        if (res.size() == level)
            res.push_back(node->val);

        // Explore left subtree first
        leftDFS(node->left, level + 1, res);

        // Then explore right subtree
        leftDFS(node->right, level + 1, res);
    }

    // Recursive function to get right view
    void rightDFS(TreeNode* node, int level, vector<int>& res) {
        if (!node) return;

        if (res.size() == level)
            res.push_back(node->val);

        // Explore right subtree first
        rightDFS(node->right, level + 1, res);

        // Then explore left subtree
        rightDFS(node->left, level + 1, res);
    }

    vector<int> leftView(TreeNode* root) {
        vector<int> res;
        leftDFS(root, 0, res);
        return res;
    }

    vector<int> rightView(TreeNode* root) {
        vector<int> res;
        rightDFS(root, 0, res);
        return res;
    }
};

// Driver code
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->right->right = new TreeNode(5);
    root->left->right->right->right = new TreeNode(6);

    Solution sol;
    vector<int> left = sol.leftView(root);
    vector<int> right = sol.rightView(root);

    cout << "Left View: ";
    for (int val : left) cout << val << " ";
    cout << "\nRight View: ";
    for (int val : right) cout << val << " ";
    return 0;
}
