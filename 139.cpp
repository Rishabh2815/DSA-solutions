#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Helper function to find ceil of a given key in BST
int findCeil(Node* root, int x) {
  
    int ceil = -1; 
    
    while (root) {
      
        // If root itself is ceil
        if (root->data == x) {
            return root->data; 
        }
     
        // If root is smaller, the ceil
        // must be in the right subtree
        if (x > root->data) {
            root = root->right; 
        } 
      
        // Else either root can be ceil
        // or a node in the left child
        else {
            ceil = root->data; 
            root = root->left; 
        }
    }
    return ceil; 
}

// Driver code
int main() {
    Node* root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(12);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->right->left = new Node(10);
    root->right->right = new Node(14);

    int x=11;
    cout<<findCeil(root,x);

    return 0;
}#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Helper function to find ceil of a given key in BST
int findCeil(Node* root, int x) {
  
    int ceil = -1; 
    
    while (root) {
      
        // If root itself is ceil
        if (root->data == x) {
            return root->data; 
        }
     
        // If root is smaller, the ceil
        // must be in the right subtree
        if (x > root->data) {
            root = root->right; 
        } 
      
        // Else either root can be ceil
        // or a node in the left child
        else {
            ceil = root->data; 
            root = root->left; 
        }
    }
    return ceil; 
}

// Driver code
int main() {
    Node* root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(12);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->right->left = new Node(10);
    root->right->right = new Node(14);

    int x=11;
    cout<<findCeil(root,x);

    return 0;
}