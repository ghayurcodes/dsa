#include<iostream>

using namespace std;

// Node class representing a node in the circular linked list
class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Circular Linked List class
class CircularLinkedList {
public:
    Node* head;

    // Constructor
    CircularLinkedList() {
        head = nullptr;
    }

    // Function to add a node to the circular linked list
    void add(int val) {
        Node* newNode = new Node(val);

        // If the list is empty
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;  // Point to itself to make it circular
        } else {
            Node* temp = head;
            // Traverse to the last node
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;  // Point last node to the new node
            newNode->next = head;  // Make the new node point to the head
        }
    }

    // Function to print the circular linked list
    void print() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        // Use a do-while loop to handle circular printing
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);  // Stop when we circle back to the head
        cout << endl;
    }

    // Function to delete a node from the circular linked list
    void deleteNode(int key) {
        if (head == nullptr) return;  // If list is empty

        Node* curr = head;
        Node* prev = nullptr;

        // Case 1: If the node to be deleted is the head
        if (head->data == key) {
            // Find the last node to update its next pointer
            while (curr->next != head) {
                curr = curr->next;
            }
            if (head == head->next) {  // If there's only one node
                delete head;
                head = nullptr;
            } else {
                curr->next = head->next;  // Last node now points to the next node of head
                delete head;              // Delete the old head
                head = curr->next;        // Update the head
            }
            return;
        }

        // Case 2: Node to be deleted is somewhere else
        curr = head;
        do {
            prev = curr;
            curr = curr->next;
        } while (curr != head && curr->data != key);

        if (curr->data == key) {  // If we found the node
            prev->next = curr->next;
            delete curr;
        }
    }





    
     void is_circular() {
        Node* slow = head;
        Node* fast = head;

        bool is_circular = false;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                is_circular = true;
                break;
            }
        }

        cout << "It is " << (is_circular ? "circular" : "not circular") << endl;
    }
};

int main() {
    CircularLinkedList list;

    // Adding elements to the circular linked list
    list.add(10);
    list.add(20);
    list.add(30);
    list.add(40);
    list.add(50);

    // Printing the list
    cout << "Circular Linked List: ";
    list.print();  // Output: 10 20 30 40 50

    // Deleting a node
    list.deleteNode(30);
    cout << "After deleting 30: ";
    list.print();  // Output: 10 20 40 50

    return 0;
}
