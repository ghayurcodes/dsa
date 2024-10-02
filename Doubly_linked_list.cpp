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


    void addat(int val, int index) {
    if (index < 0 || index > size()) {
        cout << "Invalid index" << endl;
        return;
    }

    Node* newnode = new Node(val);

    // Case 1: Insert at the beginning (index == 0)
    if (index == 0) {
        newnode->next = head;
        if (head != nullptr) {
            head->prev = newnode; // Update the previous head's prev pointer
        }
        head = newnode; // New node becomes the new head
        return;
    }

    Node* temp = head;
    
    // Traverse to the node just before the insertion point
    for (int i = 0; i < index - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    // Case 2: Insert in the middle or end
    newnode->next = temp->next;
    if (temp->next != nullptr) {
        temp->next->prev = newnode; // Set the next node's prev pointer if it's not null
    }
    temp->next = newnode;
    newnode->prev = temp; // Set the new node's prev pointer
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

    void remove(int index) {
    // Check if the list is empty
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    // Check for out-of-bound index
    if (index < 0 || index >= size()) {
        cout << "Invalid index" << endl;
        return;
    }

    // Case 1: Removing the head node
    if (index == 0) {
        Node* temp = head;
        head = head->next; // Move head to the next node
        if (head != nullptr) {
            head->prev = nullptr; // Update the new head's prev pointer
        }
        delete temp; // Delete the original head node
        return;
    }

    // Traverse to the node at the given index
    Node* temp = head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }

    // Case 2: Removing a middle or last node
    if (temp->next != nullptr) { // Not the last node
        temp->next->prev = temp->prev; // Update the next node's prev pointer
    }
    if (temp->prev != nullptr) { // Not the head
        temp->prev->next = temp->next; // Update the previous node's next pointer
    }

    delete temp; // Delete the node
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

    list.remove(2);
    list.print();

    // Printing the list from end to head (reverse order)
    // cout << "List in reverse order: ";
    // list.printReverse();

    cout<<"size: "<<list.size()<<endl;

    

    return 0;
}
