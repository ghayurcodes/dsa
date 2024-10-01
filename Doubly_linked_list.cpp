#include<iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev; // Pointer to the previous node

    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr; // Initialize prev as nullptr
    }

    ~Node() {
        cout << "Node deleted with value: " << this->data << endl;
    }
};

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() {
        head = nullptr;
    }

    // Adding node to the end of the list
    void add(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp; // Set the previous pointer
        }
    }

    int size(){
        int size=0;
        Node* temp=head;
        while(temp!=nullptr){
            temp=temp->next;
            size++;

        }
        return size;
    }


    void addat(int val,int index){
        Node* temp=head;
        while(temp){

        }
    }

    // Printing the list from the head to the end
    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Printing the list from the end to the head (reverse print)
    void printReverse() {
        if (head == nullptr) return;

        Node* temp = head;
        // Go to the last node
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        // Traverse backwards using prev pointers
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

    ~DoublyLinkedList() {
        // Destructor to delete all nodes and avoid memory leaks
        Node* temp = head;
        while (temp != nullptr) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }

    
};

int main() {
    DoublyLinkedList list;
    list.add(3);
    list.add(6);
    list.add(9);
    list.add(12);
    list.add(14);

    // Printing the list from head to end
    cout << "List in forward order: ";
    list.print();

    // Printing the list from end to head (reverse order)
    // cout << "List in reverse order: ";
    // list.printReverse();

    cout<<"size: "<<list.size()<<endl;

    return 0;
}
