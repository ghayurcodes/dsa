#include<iostream>

using namespace std;

class Node {
public:
    int data;
    Node* nxtadr;

    Node(int data){
        this->data=data;
        nxtadr=NULL;
    }
};

class SLL {
    Node* head;
    Node* current;
    int locCounter;
    int noV;

public:
    SLL() : head(NULL), current(NULL), noV(0), locCounter(0) {}

    void insertatstart(int d) {
        Node* newnode = new Node(d);
        if (head == NULL) {
            head = newnode;
        } else {
            newnode->nxtadr = head;
            head = newnode;
        }
        noV++;
    }

    void insertatend(int d) {
        Node* newnode = new Node(d);
       
        if (head == NULL) {
            head = newnode;
        } else {
            current = head;
            while (current->nxtadr != NULL) {
                current = current->nxtadr;
            }
            current->nxtadr = newnode;
        }
        noV++;
    }

    void deleteatstart() {
        if (head == NULL) {
            cout << "\n\tList empty";
        } else {
            current = head;
            head = head->nxtadr;
            current->nxtadr = NULL;//optional
            delete current;
            noV--;
        }
    }

    void display() {
        if (head == NULL) {
            cout << "\n\tEmpty List";
        } else {
            current = head;
            while (current != NULL) {
                cout << endl << current->data;
                current = current->nxtadr;
            }
        }
    }

    void insertatlocation(int index, int val) {
    Node* newnode = new Node(val);

    if (index < 0 || index > noV) {
        cout << "Invalid index" << endl;
        delete newnode;
        return;
    }

    if (index == 0) {
        newnode->nxtadr = head;
        head = newnode;
    } else {
        Node* current = head;
        int locCounter = 0;

        while (locCounter < index - 1) {
            current = current->nxtadr;
            locCounter++;
        }

        newnode->nxtadr = current->nxtadr;
        current->nxtadr = newnode;
    }

    noV++;
}




void deleteatend(){
     if (head == NULL) {
            cout << "\n\tList empty";
        } else {
            current = head;

            while(current->nxtadr->nxtadr!=NULL){
                current=current->nxtadr;
            }
            Node* todel=current->nxtadr;
            current->nxtadr=NULL;
            delete todel;
            
            noV--;
        }

}



void delatlocation(int index) {
    if (index < 0 || index >= noV) {
        cout << "Invalid index" << endl;
        return;
    }

    if (index == 0) {
       current = head;
        head = head->nxtadr;
        delete current;
    } else {
       current = head;
        int locCounter = 0;

        while (locCounter < index - 1) {
            current = current->nxtadr;
            locCounter++;
        }

        Node* todel = current->nxtadr;
        current->nxtadr = current->nxtadr->nxtadr;
        delete todel;
    }

    noV--;
}

void searchvalue(int val) {
    if (head == NULL) {
        cout << "Empty list\n";
        return;
    } else {
        current = head;
        int index = 0;
        bool found = false;

        while (current != NULL) {
            if (current->data == val) {
                found = true;
                break;
            }
            current = current->nxtadr;
            index++;
        }

        if (found) {
            cout << val << " found at index: " << index << endl;
        } else {
            cout << "No such element exists\n";
        }
    }
}


void modifylocation(int index){
    if(head==NULL){
        cout << "Empty list\n";
        return;
    }
    else if(index<0 || index>noV){
        cout<<"Index does not exists\n";
        return;
    }
    else{
        current=head;
        locCounter=0;
        while(locCounter<index){
            current=current->nxtadr;
            locCounter++;
        }
        cout<<"enter new value:";
        cin>>current->data;

    }
}

void modifyvalue(int val){
    if(head==NULL){
        cout << "Empty list\n";
        return;
    }
    else{
        current=head;
        int count=0;
        while(current!=NULL){
            if(current->data==val){
                cout<<"enter value for the "<<count+1<<" value found: ";
                cin>>current->data;
                count++;
            }
            current=current->nxtadr;
            
        }
    }
}



};

int main() {
    int choice, value,index;
    SLL myList;

    while (true) {
        
        cout << "\n\t=== Menu ===";
        cout << "\n\t1. Insert at start";
        cout << "\n\t2. Insert at end";
        cout << "\n\t3. Insert at specific location";
        cout << "\n\t4. Delete at Start";
        cout << "\n\t5. Delete at End";
        cout << "\n\t6. Delete at specific location";
        cout << "\n\t7. Search value";
        cout << "\n\t8. Modify by location";
        cout << "\n\t9. Modify by value";
        cout << "\n\t10. Display";
        cout << "\n\t11. Exit";
        cout << "\n\tEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\n\tEnter value: ";
                cin >> value;
                myList.insertatstart(value);
                cout << "\n\tValue inserted successfully";
                
                break;

            case 2:
                cout << "\n\tEnter value: ";
                cin >> value;
                myList.insertatend(value);
                cout << "\n\tValue inserted successfully";
            
                break;

            case 3:
                cout << "\n\tEnter index: ";
                cin>>index;
                cout << "\n\tEnter value: ";
                cin >> value;
                myList.insertatlocation(index,value);
                cout << "\n\tValue inserted successfully";
               
                break;

            case 4:
                myList.deleteatstart();
                cout << "\n\tValue deleted";
                break;

            case 5:
               myList.deleteatend();
                cout << "\n\tValue deleted";
                break;
            case 6:
                cout << "\n\tEnter index: ";
                cin>>index;
                myList.delatlocation(index);
                cout << "\n\tValue deleted successfully\n";
                break;

            case 7:
                cout << "\n\tEnter value: ";
                cin >> value;
                myList.searchvalue(value);
                break;

            case 8:
                cout << "\n\tEnter index: ";
                cin>>index;
                myList.modifylocation(index);
                cout << "\n\tValue updated successfully\n";
               
                break;


            case 9:
                cout << "\n\tEnter value: ";
                cin >> value;
                myList.modifyvalue(value);
                 cout << "\n\tValue updated successfully\n";
                break;


            case 10:
                myList.display();
                
                break;

            case 11:
                exit(0);
                break;
        }
    }
}
