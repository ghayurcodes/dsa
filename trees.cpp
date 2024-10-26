#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* right;
    Node* left;

    Node(int val) {
        this->data = val;
        right = nullptr;
        left = nullptr;
    }
};

class BinaryTree {
public:
    Node* Root;

    BinaryTree() {
        Root = nullptr;
    }

    void add() {
        Root = add_Node();
    }

    Node* add_Node() {
        cout << "Enter value (-1 to indicate no node): ";
        int val;
        cin >> val;

        // If user inputs -1, this branch is null
        if (val == -1) {
            return nullptr;
        }

        Node* newNode = new Node(val);

        cout << "Enter data for inserting at left of " << val << endl;
        newNode->left = add_Node();

        cout << "Enter data for inserting at right of " << val << endl;
        newNode->right = add_Node();

        return newNode;
    }

    void display(Node* root) {
        if (root == nullptr) {
            return;
        }

        cout << root->data << endl;
        
        // Recursively display left and right children
        if (root->left != nullptr) {
            display(root->left);
        }
        if (root->right != nullptr) {
            display(root->right);
        }
    }
};

int main() {
    BinaryTree b;
    b.add();

    cout << "Displaying tree:" << endl;
    b.display(b.Root);

    return 0;
}
