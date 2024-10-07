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

    
}

