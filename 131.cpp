/* Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) {
            return NULL;
        }
        
        Node* curr = root;
        Node* nextLevelHead = root->left;

        while (curr != NULL && nextLevelHead != NULL) {
            // 1. Connect left child to right child of the same parent
            curr->left->next = curr->right;

            // 2. Connect right child to the left child of the next tree node
            if (curr->next != NULL) {
                curr->right->next = curr->next->left;
            }

            // Move to the next node in the same level
            curr = curr->next;

            // If we reach the end of the level, jump to the next level
            if (curr == NULL) {
                curr = nextLevelHead;
                nextLevelHead = curr->left;
            }
        }

        return root;
    }
};
/* Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) {
            return NULL;
        }
        
        Node* curr = root;
        Node* nextLevelHead = root->left;

        while (curr != NULL && nextLevelHead != NULL) {
            // 1. Connect left child to right child of the same parent
            curr->left->next = curr->right;

            // 2. Connect right child to the left child of the next tree node
            if (curr->next != NULL) {
                curr->right->next = curr->next->left;
            }

            // Move to the next node in the same level
            curr = curr->next;

            // If we reach the end of the level, jump to the next level
            if (curr == NULL) {
                curr = nextLevelHead;
                nextLevelHead = curr->left;
            }
        }

        return root;
    }
};
