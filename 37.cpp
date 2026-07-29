#include <bits/stdc++.h>
using namespace std;

// Definition of a singly linked list node
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    // Function to rotate the linked list to the right by k places
    ListNode* rotateRight(ListNode* head, int k) {
        // If list is empty or has only one node, or no rotation is needed
        if (!head || !head->next || k == 0)
            return head;

        // Initialize length and tail pointer
        int length = 1;
        ListNode* tail = head;

        // Traverse to find the tail and length
        while (tail->next) {
            tail = tail->next;
            length++;
        }

        // Make it a circular linked list
        tail->next = head;

        // Effective rotations needed
        k = k % length;

        // Traverse to the new tail (length - k - 1 steps from head)
        int stepsToNewTail = length - k;
        ListNode* newTail = head;
        for (int i = 1; i < stepsToNewTail; i++) {
            newTail = newTail->next;
        }

        // Set the new head
        ListNode* newHead = newTail->next;

        // Break the circle
        newTail->next = NULL;

        return newHead;
    }
};

// Driver code
int main() {
    // Create linked list: 1->2->3->4->5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;

    Solution obj;
    ListNode* newHead = obj.rotateRight(head, k);

    // Print the rotated list
    while (newHead) {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
    cout << endl;

    return 0;
}
