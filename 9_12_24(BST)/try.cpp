#include<iostream>
#include<queue>
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
      queue<node*> q;
        // stack<int> s;
        q.push(root);
        q.push(NULL);



        while(!q.empty()){
            node* temp=q.front();
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