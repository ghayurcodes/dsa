#include <iostream>
using namespace std;

// Node structure for the BST
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Function to insert a node into the BST
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to search for an element in the BST
bool search(Node* root, int value) {
    if (root == nullptr) {
        return false;
    }

    if (root->data == value) {
        return true;
    }

    if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

// Inorder traversal function (for displaying BST elements)
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Main function to test the BST implementation
int main() {
    Node* root = nullptr;
    int elements[] = {50, 30, 70, 20, 40, 60, 80};
    
    // Insert elements into the BST
    for (int val : elements) {
        root = insert(root, val);
    }

    cout << "Inorder traversal of the BST: ";
    inorder(root);
    cout << endl;

    // Search for elements
    int searchValue;
    cout << "Enter a value to search: ";
    cin >> searchValue;

    if (search(root, searchValue)) {
        cout << "Element " << searchValue << " is found in the BST." << endl;
    } else {
        cout << "Element " << searchValue << " is NOT found in the BST." << endl;
    }

    return 0;
}
