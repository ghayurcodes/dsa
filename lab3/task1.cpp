#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    
    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class Stack {
private:
    Node* head;
    Node* tail;

public:
    Stack() {
        head = nullptr;
        tail = nullptr;
    }

    // Push element onto the stack
    void push(int data) {
        Node* newNode = new Node(data);
        if (tail == nullptr) {  // If the stack is empty
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Remove the top element from the stack
    void pop() {
        if (tail == nullptr) {  // Stack is empty
            std::cout << "Stack Underflow" << std::endl;
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
    }

    // Get the top element of the stack
    int top() {
        if (tail == nullptr) {
            std::cout << "Stack is empty" << std::endl;
            return -1;
        }
        return tail->data;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return tail == nullptr;
    }

    // Display stack elements
    void display() {
        Node* temp = tail;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->prev;
        }
        std::cout << std::endl;
    }
};

int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Stack elements: ";
    stack.display();

    std::cout << "Top element: " << stack.top() << std::endl;

    stack.pop();
    std::cout << "After pop, top element: " << stack.top() << std::endl;

    std::cout << "Stack elements after pop: ";
    stack.display();

    return 0;
}
