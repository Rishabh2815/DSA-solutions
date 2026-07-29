// C++ program to find all binary trees
// from 1 to n

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

// Function to construct all possible binary trees 
vector<Node*> getTrees(int start, int end) {
    vector<Node*> trees;

    // Base case: If start index is greater than end, 
  	// return empty tree (nullptr)
    if (start > end) {
        trees.push_back(nullptr);
        return trees;
    }

    // Iterate through all values in the array 
  	// and construct left and right subtrees
    for (int i = start; i <= end; ++i) {
        
        // Generate all left subtrees
        vector<Node*> leftTrees = getTrees(start, i - 1);

        // Generate all right subtrees
        vector<Node*> rightTrees = getTrees(i + 1, end);

        // Combine each left and right subtree with 
      	// the current root
        for (Node* left : leftTrees) {
            for (Node* right : rightTrees) {
                
                // Make i as root
                Node* root = new Node(i); 
                root->left = left;
                root->right = right;

                // Add the constructed tree to the list of trees
                trees.push_back(root);
            }
        }
    }
    return trees;
}

void preorder(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
    vector<Node*> trees = getTrees(1, 3);

    for (int i = 0; i < trees.size(); ++i) {
        preorder(trees[i]);
        cout << "\n";
    }

    return 0;
}