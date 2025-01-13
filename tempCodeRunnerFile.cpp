#include <iostream>
#include <queue>
#include<stack>
using namespace std;

// Node class to represent each node in the binary tree
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

// Function to perform Preorder Traversal (Root, Left, Right)
void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

// Function to perform Inorder Traversal (Left, Root, Right)
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Function to perform Postorder Traversal (Left, Right, Root)
void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

// Function to insert elements into the tree level by level
Node* insertLevelOrder(int arr[], Node* root, int i, int n) {
    if (i < n) {
        Node* temp = new Node(arr[i]);
        root = temp;

        // Insert left child
        root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);

        // Insert right child
        root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
    }
    return root;
}



void dfs(Node* root){
    stack<Node*> s;
    s.push(root);

    while(!s.empty()){
        Node* temp=s.top();
        s.pop();

        cout<<temp->val<<" ";

        if(temp->right){
            s.push(temp->right);
        }
        if(temp->left){
            s.push(temp->left);
        }
    }

}

// Function to display the tree traversals
void displayTraversals(Node* root) {
    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;


    cout<<" DFS: ";
    dfs(root);
    cout<<endl;
}

int main() {
    // 10 elements given for the tree
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Insert elements into the binary tree
    Node* root = nullptr;
    root = insertLevelOrder(arr, root, 0, 10);

    // Display the three traversals
    displayTraversals(root);

    return 0;
}
