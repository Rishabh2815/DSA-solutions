#include <iostream>
using namespace std;

// Node structure
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

Node* LCA(Node* root, Node* n1, Node* n2) {

    while (root != nullptr) {
      
        // If both n1 and n2 are smaller than root,
        // then LCA lies in left
        if (root->data > n1->data && root->data > n2->data)
            root = root->left;

        // If both n1 and n2 are greater than root,
        // then LCA lies in right
        else if (root->data < n1->data && root->data < n2->data)
            root = root->right;
        
        // Else Ancestor is found
        else
            break;
    }

    return root;
}

int main() {
  	
  	// Representation of input BST:
    //            20
    //           /  \
    //          8    22
    //        /   \     
    //       4    12   
    //           /   \   
    //         10    14  
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    // Node 4
    Node* n1 = root->left->left; 
    
    // Node 14
    Node* n2 = root->left->right->right; 

    Node* res = LCA(root, n1, n2);
    cout << res->data << endl;

    return 0;
}
v