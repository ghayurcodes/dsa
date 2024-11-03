#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize a node with data
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class Stack {
private:
    Node* topNode; // Pointer to the top node of the stack

public:
    Stack() : topNode(nullptr) {} // Initialize an empty stack

    // Push operation to add an element to the stack
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
        cout << "Pushed " << value << " onto the stack.\n";
    }

    // Pop operation to remove the top element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop.\n";
            return;
        }
        Node* temp = topNode;
        topNode = topNode->next;
        cout << "Popped " << temp->data << " from the stack.\n";
        delete temp; // Free memory
    }

    // Peek operation to view the top element of the stack without removing it
    int top() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return -1; // Returning -1 as a convention; could handle this differently
        }
        return topNode->data;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return topNode == nullptr;
    }

    // Display all elements in the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        Node* temp = topNode;
        cout << "Stack elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to clean up all nodes when the stack is destroyed
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    Stack stack;

    // Test push operation
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // Display stack elements
    stack.display();

    // Test top operation
    cout << "Top element is: " << stack.top() << endl;

    // Test pop operation
    stack.pop();
    stack.display();

    // Check top element after pop
    cout << "Top element after pop is: " << stack.top() << endl;

    return 0;
}
