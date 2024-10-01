#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev

    Node(int data){
        this->data=data;
        this->next=nullptr;
    }

    ~Node(){
        cout<<"index deleted with value :"<<this->data<<endl;
    }
};

class Linked_list{
    public:
    Node* head;

    Linked_list(){
        head=nullptr;
    }

    void add(int val){
        if(head==nullptr){
            head=new Node(val);
        }
        else{
            Node* temp=head;

            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=new Node(val);
            temp->next.

        }
    }


    void print(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    
};

int main(){
    Linked_list list;
    list.add(3);
    list.add(6);
    list.add(9);
    list.add(12);
    list.add(14);

    //printing
    list.print();

}