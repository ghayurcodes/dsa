#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* right;
    Node* left;

    public:
    Node(int val){
        this->data=val;
        right=nullptr;
        left=nullptr;
    }

};


class Binarytree{
    Node* Root;
    public:
    Binarytree(){
        Root=nullptr;
    }


    void add(){
        Root=add_Node();
    }
    Node* add_Node(){
        cout<<"Enter value:";
        int val;
        cin>>val;
        Root=new Node(val);

        if(val==-1){
            return;
        }
        
        cout<<"Enter data fore inserting at left\n";
        Root->left=add_Node();
        cout<<"Enter data fore inserting at right\n";
        Root->right=add_Node();

        return Root;

    }


    void display(Node* root){
        cout<<Root->data<<endl;
        display(Root->left);
        display(root->right);
    }

    

};












int main(){
   
}   