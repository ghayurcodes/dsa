#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Node class for the binary tree
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int value) {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

// Perform BFS on the binary tree
void bfs(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    cout << "BFS Traversal: ";
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->val << " ";

        // Enqueue left and right children
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
    cout << endl;
}

// Perform DFS on the binary tree using an iterative approach
void dfsIterative(Node* root) {
    if (!root) return;

    stack<Node*> st;
    st.push(root);

    cout << "DFS Traversal (Iterative): ";
    while (!st.empty()) {
        Node* current = st.top();
        st.pop();
        cout << current->val << " ";

        // Push right and then left to stack to process left before right
        if (current->right) st.push(current->right);
        if (current->left) st.push(current->left);
    }
    cout << endl;
}

int main() {
    // Create a binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Perform BFS and DFS
    bfs(root);
    dfsIterative(root);

    return 0;
}
