#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class TreeNode {
public:
    string data;
    vector<TreeNode*> children;

    TreeNode(string data) {
        this->data = data;
    }

    void addChild(TreeNode* child) {
        children.push_back(child);
    }

  bool removeChild(const string& childName) {
    for (auto it = children.begin(); it != children.end(); it++) {
        if ((*it)->data == childName) {
            children.erase(it);  
            return true; 
        }
    }
    return false;  
}


    ~TreeNode() {
        for (TreeNode* child : children) {
            delete child;
        }
    }
};

void preOrderTraversal(TreeNode* node, int level =0) {
    if (!node) return;
    cout << string(level * 2, ' ') << node->data << endl;
    for (auto child : node->children) {
        preOrderTraversal(child, level + 1);
    }
}

void postOrderTraversal(TreeNode* node, int level = 0) {
    if (!node) return;
    for (auto child : node->children) {
        postOrderTraversal(child, level + 1);
    }
    cout << string(level * 2, ' ') << node->data << endl;
}

void inOrderTraversal(TreeNode* node, int level = 0) {
    if (!node) return;

    int numChildren = node->children.size();
    if (numChildren > 0) {
        inOrderTraversal(node->children[0], level + 1);
    }

    cout << string(level * 2, ' ') << node->data << endl;

    for (int i = 1; i < numChildren; ++i) {
        inOrderTraversal(node->children[i], level + 1);
    }
}

TreeNode* search(TreeNode* node, const string& target) {
    if (!node) return nullptr;
    if (node->data == target) return node;
    for (auto child : node->children) {
        TreeNode* result = search(child, target);
        if (result) return result;
    }
    return nullptr;
}

bool addEmployee(TreeNode* root, const string& teamName, const string& employeeName) {
    TreeNode* teamNode = search(root, teamName);
    if (teamNode) {
        teamNode->addChild(new TreeNode(employeeName));
        cout << "Employee '" << employeeName << "' added to '" << teamName << "'." << endl;
        return true;
    } else {
        cout << "Team '" << teamName << "' not found." << endl;
        return false;
    }
}

bool removeEmployee(TreeNode* node, const string& employeeName) {
    if (!node) return false;
    bool removed = node->removeChild(employeeName);
    if (removed) return true;
    for (auto child : node->children) {
        if (removeEmployee(child, employeeName)) return true;
    }
    return false;
}

int main() {
    TreeNode* root = new TreeNode("Company");

    TreeNode* sales = new TreeNode("Sales");
    TreeNode* teamA = new TreeNode("Team A");
    teamA->addChild(new TreeNode("Employee 1"));
    teamA->addChild(new TreeNode("Employee 2"));

    TreeNode* teamB = new TreeNode("Team B");
    teamB->addChild(new TreeNode("Employee 3"));
    teamB->addChild(new TreeNode("Employee 4"));

    sales->addChild(teamA);
    sales->addChild(teamB);

    TreeNode* it = new TreeNode("IT");
    it->addChild(new TreeNode("Network"));
    it->addChild(new TreeNode("Security"));

    root->addChild(sales);
    root->addChild(it);

    cout << "Initial Organizational Structure (Pre-order Traversal):" << endl;
    preOrderTraversal(root);

    string searchName = "Employee 3";
    TreeNode* found = search(root, searchName);
    if (found) {
        cout << "\nSearch Result: Found '" << found->data << "'" << endl;
    } else {
        cout << "\nSearch Result: '" << searchName << "' not found" << endl;
    }

    cout << "\nAdding 'Employee 5' to 'Team A':" << endl;
    addEmployee(root, "Team A", "Employee 5");
    preOrderTraversal(root);

    cout << "\nRemoving 'Employee 4':" << endl;
    if (removeEmployee(root, "Employee 4")) {
        cout << "'Employee 4' removed successfully." << endl;
    } else {
        cout << "Failed to remove 'Employee 4'." << endl;
    }
    preOrderTraversal(root);

    delete root;
    return 0;
}
