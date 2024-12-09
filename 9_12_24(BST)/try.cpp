#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data=d;
        left=nullptr;
        right=nullptr;
    }
};







node* insert(node* root,int val){
    if(root==nullptr){
        return new node(val);
    }

    if(val<root->data){
        root->left=insert(root->left,val);
    }
    else if(val>root->data){
        root->right=insert(root->right,val);
    }

    return root;
}


void display(node*root){//inorder vire
    if(root==nullptr){
        return;
    }
    display(root->left);
    cout<<root->data<<" ";
    display(root->right);
}


int main(){
    
    node* root=nullptr;

    int a[7]={22,44,23,14,5,7,99};
    for(int i:a){
        root=insert(root,i);
    }
    cout<<"data added\n";
    cout<<"\tDisplaying:\n";
    display(root);
    

}