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

    ~Node() {
        cout << "Node deleted with value: " << this->data << endl;
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

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    int size() {
        Node* temp = head;
        int count = 0;
        while (temp != nullptr) {
            temp = temp->next;
            count++;
        }
        return count;
    }

    void reverse() {
        Node* curr = head;
        Node* prev = nullptr;
        Node* next = nullptr;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void reverse_recursion(Node*& prev, Node*& curr) {
        if (curr == NULL) {
            head = prev;
            return;
        }
        Node* next = curr->next;
        reverse_recursion(curr, next);
        curr->next = prev;
    }

    void middle() {
        Node* temp = head;
        for (int i = 0; i < size() / 2; i++) {
            temp = temp->next;
        }
        cout << "Middle element at index: " << size() / 2 << " Element: " << temp->data << endl;
    }

    bool exists(int element) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == element) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void remove(int element) {
        if (head == nullptr) return;

        // Special case for head
        if (head->data == element) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != element) {
            temp = temp->next;
        }

        if (temp->next != nullptr) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }

    void join(LinkedList* list1, LinkedList* list2) {
        Node* temp1 = list1->head;
        Node* temp2 = list2->head;

        while (temp1->next != nullptr) {
            temp1 = temp1->next;
        }
        temp1->next = temp2;
    }

    Node* k_reverse(Node* head, int k) {
        if (head == NULL) {
            return NULL;
        }

        Node* curr = head;
        Node* prev = nullptr;
        Node* frwrd = nullptr;
        int count = 0;

        // Reverse first 'k' nodes
        while (curr != nullptr && count < k) {
            frwrd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = frwrd;
            count++;
        }

        // Recursively reverse the rest of the list
        if (frwrd != NULL) {
    
            head->next = k_reverse(frwrd, k);
        }

        // Return the new head
        return prev;
    }



     void is_circular() {
        
            if(head==nullptr){
                cout<<"no liked list yet\n";
            }

        Node* temp = head->next;
        bool is_circular = false;

        while(temp!=head && temp!=NULL){
            temp=temp->next;
        }

        if(temp==head){
            is_circular=true;

        }
    
        cout << "It is " << (is_circular ? "circular" : "not circular") << endl;
        
    }
};

int main() {
    LinkedList list;

    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    list.append(6);

    LinkedList list2;
    list2.append(88);
    list2.append(99);

    // Displaying list before reversing
    list.display();
    cout << endl;

    // k reverse call
    // list.head = list.k_reverse(list.head, 2);
    
    // // Display after reverse
    // cout << "After k-reverse:" << endl;
    // list.display();
    // cout << endl;

    list.is_circular();

    return 0;
}
