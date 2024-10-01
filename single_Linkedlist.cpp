#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* previous;

    Node(int data) {
       (*this).data = data;
        this->next = nullptr;
        this->previous=nullptr;
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

    

    // Function to reverse the linked list
    void reverse() {
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        Node* previous = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next; // Save the next node
            current->next = previous; // Reverse the link
            previous = current; // Move the 'previous' pointer forward
            current = next; // Move to the next node
        }
        head = previous; // Update the head to the new first node
    }

    // Function to append a node to the end of the list
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
        temp->next->previous=temp->next;
    }

    // Function to print the linked list
    void printList() {
        Node* temp = head;
        while (temp != nullptr) { 
            cout << temp->data << " "; 
            temp = temp->next;//2 
        }
        cout << endl;
    }

    // Function to get the size of the linked list
    int size() {
        int size = 0;
        Node* temp = head;
        while (temp != nullptr) {
            temp = temp->next;
            size++;
        }
        return size;
    }

    // Function to remove a node by index
    void remove(int index) {
        if (head == nullptr || index < 0 || index >= size()) {
            return;
        }

        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

       Node* temp = head;
    int i = 0;
    while (i < index - 1) {
        temp = temp->next;
        i++;
    }

    
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;

    }

    void inser_middle(int val, int index) {
    if (index <= 0 || index > size()) {
        cout << "Invalid index" << endl;
        return;
    }

    Node* temp = head;
    int i = 0;

    // Traverse to the node before the insertion point
    while (i < index - 1 && temp != nullptr) {
        temp = temp->next;
        i++;
    }

    // Insert the new node
    Node* newNode = new Node(val);
    newNode->next = temp->next; // New node should point to the current next node
    temp->next = newNode; // Current node should point to the new node
    delete newNode;
}



};

int main() {
    LinkedList list;

    // Adding elements to the list
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);

    cout << "Original List:" << endl;
    list.printList();

    // Reverse the list
    // list.reverse();

    // cout << "Reversed List:" << endl;
    // list.printList();

    // Print the size of the list
    cout <<"Size of List is :"<< list.size() << endl;

    // Remove an element by index
    list.remove(2);
    list.printList();

    // list.inser_middle(44,3);
    // list.printList();

    return 0;
}
