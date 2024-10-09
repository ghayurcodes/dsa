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



    void middle(){
       
        Node* temp=head;
        for(int i=0;i<size()/2;i++){
            temp=temp->next;
        }
        cout<<"middel element at index: "<<size()/2<<" Element: "<<temp->data<<endl;



    }

    bool exists(int element){
        Node* temp=head;
        bool exists=false;

        while(temp!=nullptr){
            if(temp->data==element){
                exists=true;
                return exists;
                break;
            }
            else{
                temp=temp->next;
            }
            

        }
      

        return exists;
        
    }


    void remove(int element){
        Node* temp=head;

        while(temp->next->data!=element){
            temp=temp->next;

        }
        Node* To_delete=temp->next;
        temp->next=temp->next->next;
        delete To_delete;


    }
    



    void join(LinkedList* list1,LinkedList* list2){
        Node* temp1=list1->head;
         Node*temp2=list2->head;

         while(temp1->next!=nullptr){
            temp1=temp1->next;

         }
         temp1->next=temp2;

         

    }


};

int main(){
LinkedList list;

list.append(3);
list.append(4);
list.append(9);
list.append(7);
list.append(12);
list.append(90);
list.append(142);

LinkedList list2;
list2.append(88);
list2.append(99);


//displaying
list.display();
cout<<endl;


// Node* curr=list.head;
// Node*prev= nullptr;
// list.reverse_recurcion(prev,curr); recursive call



// list.middle();


// cout<<list.exists(122);
// cout<<endl;
// list.remove(12);
// list.display();
// list.join(&list,&list2);
// list.display();

cout<<endl;
    
}

