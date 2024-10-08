#include<iostream>

using namespace std;



class Node {
public:
    int data;
    Node* next;
   

    Node(int data) {
       this->data = data;
        this->next = nullptr;
        
    }

    ~Node(){
        cout<<"index deleted with value :"<<this->data<<endl;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

     void append(int data) {
        if (head == nullptr) {
            head = new Node(data);
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new Node(data);
        
    }

    void display(){
        Node* temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }

    int size(){
        Node* temp=head;
        int count=0;
        while(temp!=nullptr){
            temp=temp->next;
            count++;


        }
     
        return count;
    }


    void reverse(){
        Node* curr=head;
        Node* prev=nullptr;
        Node* next=nullptr;

        while(curr!=nullptr){
            next=curr->next; //most basic code
            curr->next=prev;
            prev=curr; 
            curr=next;
        
        }
        head=prev;


    }


    void reverse_recurcion(Node*& prev,Node*& curr){//pasing by referanec tahts why using & sign
            if(curr==NULL){
                head=prev;
                return;
            }
            Node* next=curr->next;
            reverse_recurcion(curr,next);
            curr->next=prev;
        

    }



    void middle(int){
        int index=0;
        int middle_element=0;
        cout<<size()/2;


    }


};

int main(){
LinkedList list;

list.append(3);
list.append(4);
list.append(9);
list.append(7);
list.append(2);

//displaying
list.display();
cout<<endl;


// Node* curr=list.head;
// Node*prev= nullptr;
// list.reverse_recurcion(prev,curr); recursive call


list.display();



cout<<endl;
    
}

