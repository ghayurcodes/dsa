#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* nxtadr;

    Node(int data) {
        this->data = data;
        nxtadr = NULL;
    }
};

class SLL {
    Node* head;
    Node* current;
    

public:
int noV;
    SLL() : head(NULL), current(NULL), noV(0) {}
     
    void insertatstart(int d) {
        Node* newnode = new Node(d);
        newnode->nxtadr = head;
        head = newnode;
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
            delete current;
            noV--;
        }
    }

    void deleteatend() {
        if (head == NULL) {
            cout << "\n\tList empty";
        } else if (head->nxtadr == NULL) { // Only one node
            delete head;
            head = NULL;
            noV--;
        } else {
            current = head;
            while (current->nxtadr->nxtadr != NULL) {
                current = current->nxtadr;
            }
            delete current->nxtadr;
            current->nxtadr = NULL;
            noV--;
        }
    }

    void insertatlocation(int index, int val) {
        if (index < 0 || index > noV) {
            cout << "Invalid index" << endl;
            return;
        }
        Node* newnode = new Node(val);
        if (index == 0) {
            newnode->nxtadr = head;
            head = newnode;
        } else {
            current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->nxtadr;
            }
            newnode->nxtadr = current->nxtadr;
            current->nxtadr = newnode;
        }
        noV++;
    }

    void delatlocation(int index) {
        if (index < 0 || index >= noV) {
            cout << "Invalid index" << endl;
            return;
        }
        if (index == 0) {
            deleteatstart();
        } else {
            current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->nxtadr;
            }
            Node* todel = current->nxtadr;
            current->nxtadr = todel->nxtadr;
            delete todel;
            noV--;
        }
    }

    void searchvalue(int val) {
        current = head;
        int index = 0;
        while (current != NULL) {
            if (current->data == val) {
                cout << val << " found at index: " << index << endl;
                return;
            }
            current = current->nxtadr;
            index++;
        }
        cout << "No such element exists\n";
    }

    void modifylocation(int index) {
        if (head == NULL || index < 0 || index >= noV) {
            cout << "Index does not exist\n";
            return;
        }
        current = head;
        for (int i = 0; i < index; i++) {
            current = current->nxtadr;
        }
        cout << "Enter new value: ";
        cin >> current->data;
    }

    void modifyvalue(int val) {
        current = head;
        int count = 0;
        while (current != NULL) {
            if (current->data == val) {
                cout << "Enter value for the " << count + 1 << " value found: ";
                cin >> current->data;
                count++;
            }
            current = current->nxtadr;
        }
        if (count == 0) cout << "Value not found.\n";
    }

    void display() {
        if (head == NULL) {
            cout << "\n\tEmpty List";
        } else {
            current = head;
            while (current != NULL) {
                cout << current->data << " ";
                current = current->nxtadr;
            }
            cout << endl;
        }
    }
};

int main() {
    int choice, value, index;
    SLL myList;

    while (true) {
        cout << "\n\t=== Menu ===";
        cout << "\n\t1. Insert at start";
        cout << "\n\t2. Insert at end";
        cout << "\n\t3. Insert at specific location";
        cout << "\n\t4. Delete at start";
        cout << "\n\t5. Delete at end";
        cout << "\n\t6. Delete at specific location";
        cout << "\n\t7. Search value";
        cout << "\n\t8. Modify by location";
        cout << "\n\t9. Modify by value";
        cout << "\n\t10. Display";
        cout << "\n\t11. Exit";
        cout << "\n\tEnter choice: ";
        cout<<"\n\t12: get noV:\n" ;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                myList.insertatstart(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                myList.insertatend(value);
                break;

            case 3:
                cout << "Enter index: ";
                cin >> index;
                cout << "Enter value: ";
                cin >> value;
                myList.insertatlocation(index, value);
                break;

            case 4:
                myList.deleteatstart();
                break;

            case 5:
                myList.deleteatend();
                break;

            case 6:
                cout << "Enter index: ";
                cin >> index;
                myList.delatlocation(index);
                break;

            case 7:
                cout << "Enter value: ";
                cin >> value;
                myList.searchvalue(value);
                break;

            case 8:
                cout << "Enter index: ";
                cin >> index;
                myList.modifylocation(index);
                break;

            case 9:
                cout << "Enter value: ";
                cin >> value;
                myList.modifyvalue(value);
                break;

            case 10:
                myList.display();
                break;

            case 11:
                exit(0);
            case 12:
            cout<<myList.noV<<endl;
            default:
                cout << "Invalid choice.\n";
        }
    }
}
