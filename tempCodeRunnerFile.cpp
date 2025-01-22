#include <iostream>
using namespace std;

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

class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = nullptr;
    }

    // Function to insert a node in the binary tree
    Node* insert(Node* node, int val) {
        if (node == nullptr) {
            return new Node(val);
        }

        // Simple level-order insertion for demonstration purposes
        if (val < node->data) {
            node->left = insert(node->left, val);
        } else {
            node->right = insert(node->right, val);
        }

        return node;
    }

    // Delete operation for the binary tree
    Node* deleteNode(Node* root, int val) {
        if (root == nullptr) {
            return root;
        }

        // If the value is smaller than the root's data, move to the left subtree
        if (val < root->data) {
            root->left = deleteNode(root->left, val);
        }
        // If the value is greater than the root's data, move to the right subtree
        else if (val > root->data) {
            root->right = deleteNode(root->right, val);
        }
        // If root is the node to be deleted
        else {
            // Case 1: Node has no children (leaf node)
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            }
            // Case 2: Node has one child
            else if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            // Case 3: Node has two children
            else {
                // Find the inorder successor (smallest node in the right subtree)
                Node* temp = findInorderSuccessor(root->right);
                root->data = temp->data;  // Replace data with the inorder successor's data
                root->right = deleteNode(root->right, temp->data);  // Delete the inorder successor
            }
        }
        return root;
    }

    // Function to find the inorder successor (smallest node in the right subtree)
    Node* findInorderSuccessor(Node* root) {
        while (root && root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

    // Inorder traversal to print the tree
    void inorder(Node* root) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
};

int main() {
    BinaryTree tree;

    // Building the tree
    tree.root = tree.insert(tree.root, 50);
    tree.insert(tree.root, 30);
    tree.insert(tree.root, 20);
    tree.insert(tree.root, 40);
    tree.insert(tree.root, 70);
    tree.insert(tree.root, 60);
    tree.insert(tree.root, 80);

    // Print the tree before deletion
    cout << "Original Tree (Inorder): ";
    tree.inorder(tree.root);
    cout << endl;

    // Delete a node
    int valueToDelete = 20;
    tree.root = tree.deleteNode(tree.root, valueToDelete);

    // Print the tree after deletion
    cout << "Tree after deleting " << valueToDelete << " (Inorder): ";
    tree.inorder(tree.root);
    cout << endl;

    return 0;
}
