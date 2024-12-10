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

// Helper function to find the minimum value node in the BST
Node* findMin(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}


Node* deleteNode(Node* root, int value) {
    if (root == nullptr) {
        return nullptr;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        // Node with no children (leaf node)
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }

        // Node with one child (right child)
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // Node with one child (left child)
        if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Inorder traversal function (for displaying BST elements)
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Main function to provide an option menu
int main() {
    Node* root = nullptr;
    int choice, value;

    do {
        cout << "\n--- Binary Search Tree Menu ---\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Delete\n";
        cout << "4. Display Inorder Traversal\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
            while(true){
                cout << "Enter value to insert: ";
                cin >> value;
                if(value==-1){
                    break;
                }
                root = insert(root, value);
             
            };
                
                break;

            case 2:
                cout << "Enter value to search: ";
                cin >> value;
                if (search(root, value)) {
                    cout << "Element " << value << " is found in the BST.\n";
                } else {
                    cout << "Element " << value << " is NOT found in the BST.\n";
                }
                break;

            case 3:
                cout << "Enter value to delete: ";
                cin >> value;
                root = deleteNode(root, value);
                cout << "Value deleted (if it existed).\n";
                break;

            case 4:
                cout << "Inorder traversal of the BST: ";
                inorder(root);
                cout << endl;
                break;

            case 5:
                cout << "Exiting the program. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    } while (choice != 5);

    return 0;
}
