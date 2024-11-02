#include <iostream>
using namespace std;

// Node structure to represent each element in the stack
struct Node {
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

// Stack class using linked list
class Stack {
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    // Push element onto stack
    void push(int element) {
        Node* newNode = new Node(element);
        newNode->next = top;
        top = newNode;
        cout << "Element added\n";
    }

    // Pop element from stack
    void pop() {
        if (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
            cout << "Element removed\n";
        } else {
            cout << "Stack underflowed\n";
        }
    }

    // Peek top element of stack
    int peek() {
        if (top != nullptr) {
            return top->data;
        } else {
            cout << "Stack is empty!\n";
            return -1;
        }
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Destructor to clear memory
    ~Stack() {
        while (top != nullptr) {
            pop();
        }
    }
};

int main() {
    Stack s;
    s.push(45);
    s.push(55);
    s.push(65);

    cout << "Top element: " << s.peek() << endl;

    s.pop();
    cout << "Top element after pop: " << s.peek() << endl;

    return 0;
}
