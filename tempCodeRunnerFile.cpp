#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to find the second smallest element in a BST
int findSecondSmallest(Node* root) {
    if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
        throw runtime_error("Tree must have at least two nodes");
    }

    stack<Node*> st;
    Node* current = root;
    int count = 0;

    while (!st.empty() || current != nullptr) {
        while (current != nullptr) {
            st.push(current);
            current = current->left;
        }

        current = st.top();
        st.pop();

        count++;
        if (count == 2) {
            return current->data;
        }

        current = current->right;
    }

    throw runtime_error("Tree does not have enough elements");
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right = new Node(7);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    try {
        cout << "Second smallest element: " << findSecondSmallest(root) << endl;
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }

    return 0;
}
