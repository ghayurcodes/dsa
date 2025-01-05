#include <iostream>

using namespace std;

// Simple binary tree node class
class node {
public:
    int val;
    node* left;
    node* right;

    node(int v) {
        this->val = v;
        left = nullptr;
        right = nullptr;
    }
};

// Function to add nodes to the binary tree
node* add() {
    int val;
    cout << "Enter value (-1 for no node): ";
    cin >> val;

    if (val == -1) {
        return nullptr;
    }

    node* newNode = new node(val);
    cout << "Adding left child of " << val << endl;
    newNode->left = add();
    cout << "Adding right child of " << val << endl;
    newNode->right = add();

    return newNode;
}

// Function to view the tree (inorder traversal)
void view(node* root) {
    if (root == nullptr) {
        return;
    }

    view(root->left);
    cout << root->val << " ";
    view(root->right);
}

int main() {
    node* root = nullptr;

    while (true) {
        cout << "\nWelcome\n";
        cout << "1 to add\n2 to view\n3 to exit\n";
        int opt;
        cin >> opt;

        if (opt == 3) {
            exit(0);
        } else if (opt == 1) {
            if (root == nullptr) {
                cout << "Creating a new tree.\n";
                root = add();
            } else {
                cout << "Tree already exists. Cannot add root again.\n";
            }
        } else if (opt == 2) {
            if (root == nullptr) {
                cout << "Tree is empty. Nothing to view.\n";
            } else {
                cout << "Tree (inorder traversal): ";
                view(root);
                cout << endl;
            }
        } else {
            cout << "Invalid option. Try again.\n";
        }
    }

    return 0;
}
