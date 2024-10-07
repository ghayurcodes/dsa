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

    

};

int main(){

    
}

