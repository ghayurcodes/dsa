#include<iostream>


using namespace std;
//simple binary tree
class node{
    public:
    int val;
    node* left;
    node* right;


    node(int v){
        this->val=v;
        left=nullptr;
        right=nullptr;
    }
    node(){
        left=nullptr;
        right=nullptr;
    }

    
};

node* add(){

    int val;
    cout<<"enter val:(-1 to exit)\n";
    cin>>val;
    if(val==-1){
        return nullptr;
    }
    node* n=new node(val);
    
    cout<<"enter for left of "<<val<<endl;
    n->left=add();
    cout<<"enter for right of "<<val<<endl;
    n->right=add();



    return n;
    }



void view(node* root){

    if(root==nullptr){
        return;
    }

    if(root->left){
        view(root->left);
    }
    cout<<root->val<<" ";

    if(root->right){
        view(root->right);
    }

}

int main(){
    node* root=nullptr;
    while (true)
    {
        
        cout<<"\nWelcome\n";
        cout<<"1 to add\n2 to view\n3 to exit";
        int opt;
        cin>>opt;
        if(opt==3){
            exit(0);
        }
        else{
            if (opt==1)
            {
                root=add();
            }
            if(opt==2){
                view(root);
            }
            
        }

    }
    
    



}