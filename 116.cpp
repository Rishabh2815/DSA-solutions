// C++ program to illustrate how to implement
#include <iostream>
#include <queue>
using namespace std;

// treenode
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value): data(value),
    left(nullptr), right(nullptr){}
};

// function for level order traversal
void levelOrderTraversal(Node* root)
{
    // checking if the tree is empty or not
    if (root == nullptr)
        return;

    // creating and initializing queue with root as first
    // element
    queue<Node*> q;
    q.push(root);

    // loop that will run till the q is empty
    while (!q.empty()) {

        // visiting current node which is nothing but
        // q.front()
        Node* node = q.front();
        q.pop();
        cout << node->data << " ";

        // pushing left child and rightchild if they exists.
        if (node->left != nullptr)
            q.push(node->left);
        if (node->right != nullptr)
            q.push(node->right);
    }
}

// driver code
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    cout << "Level Order Traversal of Binary Tree: ";
    levelOrderTraversal(root);
    return 0;
}