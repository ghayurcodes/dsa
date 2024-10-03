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
    ~Node() {
        cout << "Node deleted with value: " << this->data << endl;
    }
};


class circular_linked_list{
    public:
    Node* head;

    circular_linked_list(){
        head=nullptr;
    }

    void add(int val){
        if(head==NULL){
            head=new Node(val);
            head->next = head;
        }

        Node* temp=head;
        while(temp->next!=head){
            temp=temp->next;

        }
        temp->next=new Node(val);
        temp->next->next=head;

        
    }

   void print() {
        if (head == nullptr) {
            return;  // Empty list
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);  // Stop when we circle back to the head
        cout << endl;
    }

};

 main(){
    circular_linked_list list;

    list.add(3);
    list.add(6);
    list.add(8);
    list.add(11);
    list.add(22);

    list.print();




}