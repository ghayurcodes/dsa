#include<iostream>
#include<queue>
#include<stack>
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



    void level_oder_trasversal(Node* root){                     //also caleed breadth first search
        queue<Node*> q;
        // stack<int> s;
        q.push(root);
        q.push(NULL);



        while(!q.empty()){
            Node* temp=q.front();
            q.pop();
           

            if(temp==NULL){
                // s.push(-1);
                cout<<endl;
                if(!q.empty()){
                    q.push(NULL);
                }
            }

            else{
                 cout<<temp->data<<" ";       //sment tghis line and store teh data to stack then print teh data to get in reverse order
                // s.push(temp->data);
                 if(temp->left){
                    q.push(temp->left);
                 }
                 if(temp->right){
                    q.push(temp->right);
                 }
            }
        }

        // while (!s.empty())
        // {
        //     if(s.top()!=-1){
        //         cout<<s.top();
        //     }else{
        //         cout<<endl;
        //     }
           
        //    s.pop();
        // }
        

    }


    void inorder(Node* root){
        if(root==NULL){
            return;
        }

        inorder(root->left);
        cout<<root->data<<" ";          //LNR
        inorder(root->right);
    }

    void preorder(Node* root){
        if(root==NULL){
            return;
        }
        cout<<root->data<<" ";          //NLR
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(Node* root){
        if(root==NULL){
            return;
        }

        postorder(root->left);          //LRN
        postorder(root->right);
        cout<<root->data<<" ";
    }




    void build_from_lvl_order(Node*& root){
        queue<Node*> q;
        cout<<"\nenter data for root: ";
        int data;
        cin>>data;
        root=new Node(data);
        q.push(root);
     
        while(!q.empty()){
            
            Node* temp=q.front();
            q.pop();

            cout<<"Enter leftnode for: "<<temp->data<<endl;
            int leftdata;
            cin>>leftdata;

            if(leftdata!=-1){
                temp->left=new Node(leftdata);
                q.push(temp->left);
            }

            cout<<"Enter rightnode for: "<<temp->data<<endl;
            int rightdata;
            cin>>rightdata;

            if(rightdata!=-1){
                temp->right=new Node(rightdata);
                q.push(temp->right);
            }


        }

        cout<<endl;
       


    }



    int countleaf_node(Node* root,int count){
        countin(root,count);
        return count;
    }

    void countin(Node* root,int& count){
         if(root==NULL){
            return;
        }

        countin(root->left,count);

        if(root->left==NULL && root->right==NULL) {
            count++;
        }       
                                                                             //any trasversing can be suse pre podt or in or level
        countin(root->right,count);
    }


  void inorderMorrisTraversal(Node* root) {
    Node* current = root;

    while (current != nullptr) {
        if (current->left == nullptr) {
            // If there is no left subtree, print the current node and move to the right
            cout << current->data << " ";
            current = current->right;
        } else {
            // Find the inorder predecessor of the current node
            Node* predecessor = current->left;
            while (predecessor->right != nullptr && predecessor->right != current) {
                predecessor = predecessor->right;
            }

            // Make current the right child of its inorder predecessor
            if (predecessor->right == nullptr) {
                predecessor->right = current;
                current = current->left;
            }
            // Revert the changes made (restore the tree structure)
            else {
                predecessor->right = nullptr;
                cout << current->data << " ";
                current = current->right;
            }
        }
    }
}

};

int main() {
    BinaryTree b;
    b.build_from_lvl_order(b.Root);

    cout << "Displaying tree:" << endl;
    b.level_oder_trasversal(b.Root);//also called breadth first search

    // cout<<"leaf nodes :\n";
    // int count=0;
    // count=b.countleaf_node(b.Root,count);
    // cout<<count<<endl;
    cout<<"inorder: \n";
    b.inorder(b.Root);
     cout<<"\ninorder: \n";
    b.inorderMorrisTraversal(b.Root);
    return 0;
}
