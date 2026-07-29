#include <iostream>
#include <climits>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Function to check if the binary tree 
// is a BST using Morris Traversal
bool isBST(Node* root) {
    Node* curr = root;
    Node* pre = nullptr;
    int prevValue = INT_MIN; 

    while (curr != nullptr) {
        if (curr->left == nullptr) {
            if (curr->data <= prevValue) {
                
                // Not in ascending order
                return false; 
            }
            prevValue = curr->data;
            curr = curr->right;
        } else {
            
            // Find the inorder predecessor of curr
            pre = curr->left;
            while (pre->right != nullptr && pre->right != curr) {
                pre = pre->right;
            }

            if (pre->right == nullptr) {
                
                // Create a temporary 
                // thread to the curr node
                pre->right = curr;
                curr = curr->left;
            } else {
                
                pre->right = nullptr;

                if (curr->data <= prevValue) {
                    
                    // Not in ascending order
                    return false; 
                }
                prevValue = curr->data;
                curr = curr->right;
            }
        }
    }

    return true; 
}

int main() {
  
    // Create a sample binary tree
    //     10
    //    /  \
    //   5    20
    //        / \
    //       9   25

    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(9);
    root->right->right = new Node(25);

    if (isBST(root))
        cout << "true" << endl;
    else 
        cout << "false" << endl;

    return 0;
}
