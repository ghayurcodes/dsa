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
            
            delete current;
            noV--;
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


            case 7:


            case 8:



            case 9:



            case 10:
                myList.display();
                
                break;

            case 11:
                exit(0);
                break;
        }
    }
}
