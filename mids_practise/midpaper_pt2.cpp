#include <iostream>
using namespace std;

class Stack {
    int top;
    int size;
    int* arr;

public:
    Stack(int s) {
        size = s;
        arr = new int[size];
        top = -1;
    }

    void add(int id) {
        if (top < size - 1) { // Check for stack overflow
            if (id % 5 == 0) {
                pop(); // Pop if id is divisible by 5
            } 
            else if (id % 9 != 0) { // Skip adding if id is divisible by 9
                arr[++top] = id;
            }
        } else {
            cout << "Stack is full, cannot add plate " << id << endl;
        }
    }

    void disp_broken() {
        int count = 0;
        for (int i = 0; i <= top; i++) {
            if (arr[i] != -1) {
                cout << "Plate " << arr[i] << " is broken\n";
                count++;
            }
        }
        cout << "Total broken plates: " << count << endl;
    }

    int stop() {
        if (top == -1) {
            return -1;
        }
        return arr[top];
    }

    bool empty() {
        return top == -1;
    }

    void pop() {
        if (top >= 0) {
            arr[top--] = -1; // Mark the position as broken
        }
    }

    ~Stack() {
        delete[] arr; // Clean up dynamic memory
    }
};

int main() {
    cout << "Enter the number of plates:\n";
    int no;
    cin >> no;
    Stack s(no);

    int id;
    for (int i = 0; i < no; i++) {
        cout << "Enter identity number of plate: ";
        cin >> id;
        s.add(id);
    }

    cout << "===== BROKEN PLATES =====\n";
    s.disp_broken();
}
