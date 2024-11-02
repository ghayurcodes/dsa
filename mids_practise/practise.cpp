#include <iostream>

using namespace std;

class Node {
public:
    string title, author, date;
    Node* nxt;

    Node(string title, string author, string date) {
        this->title = title;
        this->author = author;
        this->date = date;
        this->nxt = NULL;
    }
};

class Books {
private:
    Node* top;

public:
    Books() {
        top = NULL;
    }

    void push(string title, string author, string date) {
        Node* temp = new Node(title, author, date);
        temp->nxt = top; // Point to previous top
        top = temp;      // Set new top
    }

    void pop() {
        if (top == NULL) {
            cout << "Nothing to pop, books are empty!\n";
            return;
        }
        Node* temp = top;
        top = top->nxt;
        delete temp; // Free memory
    }

    void display() {
        if (top == NULL) {
            cout << "No books in stack.\n";
            return;
        }
        Node* temp = top;
        while (temp != NULL) {
            cout << "Title: " << temp->title << ", Author: " << temp->author << ", Date: " << temp->date << endl;
            temp = temp->nxt;
        }
    }
};

int main() {
    Books bookStack;
    bookStack.push("Book A", "Author A", "01-01-2020");
    bookStack.push("Book B", "Author B", "02-02-2021");
    bookStack.display();

    bookStack.pop();
    cout << "\nAfter popping one book:\n";
    bookStack.display();

    return 0;
}
