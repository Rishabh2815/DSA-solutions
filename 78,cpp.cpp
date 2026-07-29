#include <bits/stdc++.h>
using namespace std;

class StackQueue {
  public:
    stack<int> input, output;

    // Initialize your data structure here
    StackQueue() {}

    // Push element x to the back of queue
    void push(int x) {
        input.push(x);
    }

    // Removes the element from in front of queue and returns that element
    int pop() {
        // Shift input to output if output is empty
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }

        // If queue is still empty, return -1 (or throw an error if preferred)
        if (output.empty()) {
            cout << "Queue is empty, cannot pop." << endl;
            return -1;
        }

        int x = output.top();
        output.pop();
        return x;
    }

    // Get the front element
    int peek() {
        // Shift input to output if output is empty
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }

        // If queue is still empty, return -1 (or throw an error if preferred)
        if (output.empty()) {
            cout << "Queue is empty, cannot peek." << endl;
            return -1;
        }

        return output.top();
    }

    // Returns true if the queue is empty, false otherwise
    bool isEmpty() {
        return input.empty() && output.empty();
    }
};

int main() {
    StackQueue q;
    q.push(3);
    q.push(4);
    cout << "The element popped is " << q.pop() << endl;
    q.push(5);
    cout << "The front of the queue is " << q.peek() << endl;
    cout << "Is the queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;
    cout << "The element popped is " << q.pop() << endl;
    cout << "The element popped is " << q.pop() << endl;
    cout << "Is the queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
