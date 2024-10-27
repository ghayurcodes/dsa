#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

void reverse_level_order_traversal(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    stack<int> s;

    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        // Push the current node's data into the stack
        s.push(temp->data);

        // Enqueue right child before left to ensure reverse order
        if (temp->right) {
            q.push(temp->right);
        }
        if (temp->left) {
            q.push(temp->left);
        }
    }

    // Print the nodes in reverse level order
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}

int main() {
    // Example usage
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Reverse Level Order Traversal: ";
    reverse_level_order_traversal(root);

    return 0;
}
