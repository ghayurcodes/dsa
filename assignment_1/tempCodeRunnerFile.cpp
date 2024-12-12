#include <iostream>
using namespace std;

class EmployeeNode {
public:
    int id;  // Employee ID
    string name;  // Employee Name
    EmployeeNode* left;
    EmployeeNode* right;

    EmployeeNode(int id, const string& name) : id(id), name(name), left(nullptr), right(nullptr) {}
};

class EmployeeBST {
private:
    EmployeeNode* root;

    EmployeeNode* insert(EmployeeNode* node, int id, const string& name) {
        if (node == nullptr) {
            return new EmployeeNode(id, name);
        }

        if (id < node->id) {
            node->left = insert(node->left, id, name);
        } else if (id > node->id) {
            node->right = insert(node->right, id, name);
        }

        return node;
    }

    EmployeeNode* search(EmployeeNode* node, int id) {
        if (node == nullptr || node->id == id) {
            return node;
        }

        if (id < node->id) {
            return search(node->left, id);
        }

        return search(node->right, id);
    }

    EmployeeNode* findMin(EmployeeNode* node) {
        while (node && node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    EmployeeNode* deleteNode(EmployeeNode* node, int id) {
        if (node == nullptr) return node;

        if (id < node->id) {
            node->left = deleteNode(node->left, id);
        } else if (id > node->id) {
            node->right = deleteNode(node->right, id);
        } else {
            if (node->left == nullptr) {
                EmployeeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                EmployeeNode* temp = node->left;
                delete node;
                return temp;
            }

            EmployeeNode* temp = findMin(node->right);
            node->id = temp->id;
            node->name = temp->name;
            node->right = deleteNode(node->right, temp->id);
        }

        return node;
    }

public:
    EmployeeBST() : root(nullptr) {}

    void insert(int id, const string& name) {
        root = insert(root, id, name);
    }

    EmployeeNode* search(int id) {
        return search(root, id);
    }

    void deleteNode(int id) {
        root = deleteNode(root, id);
    }

    void printInOrder(EmployeeNode* node) {
        if (node) {
            printInOrder(node->left);
            cout << "Employee ID: " << node->id << ", Name: " << node->name << endl;
            printInOrder(node->right);
        }
    }

    EmployeeNode* getRoot() {
        return root;
    }
};

int main() {
    EmployeeBST bst;

    bst.insert(101, "ghayur");
    bst.insert(102, "ali");
    bst.insert(100, "ahmed");
    bst.insert(103, "jamshed");

    cout << "In-order traversal of BST:" << endl;
    bst.printInOrder(bst.getRoot());

    int searchId = 102;
    EmployeeNode* employee = bst.search(searchId);
    if (employee) {
        cout << "Employee found: ID: " << employee->id << ", Name: " << employee->name << endl;
    } else {
        cout << "Employee with ID " << searchId << " not found." << endl;
    }

    bst.deleteNode(102);

    cout << "In-order traversal after deletion:" << endl;
    bst.printInOrder(bst.getRoot());

    return 0;
}
