#include <iostream>
#include <string>
using namespace std;

// Structure to represent a node in the tree
struct Node {
    int id;
    string name;
    double price;
    Node* left;
    Node* right;

    Node(int id, const string& name, double price)
        : id(id), name(name), price(price), left(nullptr), right(nullptr) {}
};

// Function prototypes
Node* addItem(Node* root, int id, const string& name, double price);
void viewItems(Node* root);
Node* deleteItem(Node* root, int id);
Node* findMin(Node* root);
Node* updateItem(Node* root, int id, const string& name, double price);

int main() {
    Node* root = nullptr;
    int choice;

    do {
        cout << "\n--- Tree-Based Item Management System ---\n";
        cout << "1. Add Item\n";
        cout << "2. View Items\n";
        cout << "3. Delete Item\n";
        cout << "4. Update Item\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string name;
            double price;
            cout << "Enter item ID: ";
            cin >> id;
            cout << "Enter item name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter item price: ";
            cin >> price;
            root = addItem(root, id, name, price);
        } else if (choice == 2) {
            viewItems(root);
        } else if (choice == 3) {
            int id;
            cout << "Enter item ID to delete: ";
            cin >> id;
            root = deleteItem(root, id);
        } else if (choice == 4) {
            int id;
            string name;
            double price;
            cout << "Enter item ID to update: ";
            cin >> id;
            cout << "Enter new item name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter new item price: ";
            cin >> price;
            root = updateItem(root, id, name, price);
        } else if (choice == 5) {
            freeTree(root);
            cout << "Exiting...\n";
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

// Function to add an item to the tree
Node* addItem(Node* root, int id, const string& name, double price) {
    if (!root) return new Node(id, name, price);
    if (id < root->id)
        root->left = addItem(root->left, id, name, price);
    else if (id > root->id)
        root->right = addItem(root->right, id, name, price);
    else
        cout << "ID already exists. Item not added.\n";
    return root;
}

// Function to view all items in the tree (in-order traversal)
void viewItems(Node* root) {
    if (!root) return;
    viewItems(root->left);
    cout << "ID: " << root->id << ", Name: " << root->name << ", Price: $" << root->price << '\n';
    viewItems(root->right);
}

// Function to delete an item from the tree
Node* deleteItem(Node* root, int id) {
    if (!root) {
        cout << "Item not found.\n";
        return nullptr;
    }
    if (id < root->id)
        root->left = deleteItem(root->left, id);
    else if (id > root->id)
        root->right = deleteItem(root->right, id);
    else {
        // Node with one or no child
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Node with two children
        Node* temp = findMin(root->right);
        root->id = temp->id;
        root->name = temp->name;
        root->price = temp->price;
        root->right = deleteItem(root->right, temp->id);
    }
    return root;
}

// Function to find the node with the minimum value in a tree
Node* findMin(Node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

// Function to update an item's details in the tree
Node* updateItem(Node* root, int id, const string& name, double price) {
    if (!root) {
        cout << "Item not found.\n";
        return nullptr;
    }
    if (id < root->id)
        root->left = updateItem(root->left, id, name, price);
    else if (id > root->id)
        root->right = updateItem(root->right, id, name, price);
    else {
        root->name = name;
        root->price = price;
        cout << "Item updated successfully.\n";
    }
    return root;
}
