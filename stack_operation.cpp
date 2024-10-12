#include<iostream>
using namespace std;

class Doublestack {
    int top1;
    int top2;
    int* arr;
    int size;

public:
    Doublestack(int size) {
        this->size = size;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    // Push into the first stack
    void push1(int element) {
        if (top2 - top1 > 1) {
            top1++;
            arr[top1] = element;
            cout << "Element added to Stack 1: " << element << endl;
        } else {
            cout << "Stack Overflow\n";
        }
    }

    // Push into the second stack
    void push2(int element) {
        if (top2 - top1 > 1) {
            top2--;
            arr[top2] = element;
            cout << "Element added to Stack 2: " << element << endl;
        } else {
            cout << "Stack Overflow\n";
        }
    }

    // Pop from the first stack
    void pop1() {
        if (top1 >= 0) {
            cout << "Popped element from Stack 1: " << arr[top1] << endl;
            top1--;
        } else {
            cout << "Stack 1 Underflow\n";
        }
    }

    // Pop from the second stack
    void pop2() {
        if (top2 < size) {
            cout << "Popped element from Stack 2: " << arr[top2] << endl;
            top2++;
        } else {
            cout << "Stack 2 Underflow\n";
        }
    }

    // Peak from the first stack
    int peak1() {
        if (top1 >= 0) {
            return arr[top1];
        } else {
            cout << "Stack 1 is Empty\n";
            return -1;
        }
    }

    // Peak from the second stack
    int peak2() {
        if (top2 < size) {
            return arr[top2];
        } else {
            cout << "Stack 2 is Empty\n";
            return -1;
        }
    }

    ~Doublestack() {
        delete[] arr;
    }
};

int main() {
    Doublestack s(5);

    s.push1(10);
    s.push1(20);
    s.push2(30);
    s.push2(40);

    cout << "Top of Stack 1: " << s.peak1() << endl;
    cout << "Top of Stack 2: " << s.peak2() << endl;

    s.pop1();
    s.pop2();
    

    cout << "Top of Stack 1 after pop: " << s.peak1() << endl;
    cout << "Top of Stack 2 after pop: " << s.peak2() << endl;

    return 0;
}
