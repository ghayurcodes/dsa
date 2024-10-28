#include <iostream>
using namespace std;
#define MAX 10

template <typename T>
class Stack {
    int top;
    T arr[MAX];  

public:
    Stack() { top = -1; }
    bool push(T x);
    T pop();
    bool isEmpty();
    T peek();
};

template <typename T>
bool Stack<T>::push(T x) {
    if (top >= (MAX - 1)) {
        cout << "Stack Overflow\n";
        return false;
    } else {
        arr[++top] = x;
        cout << x << " pushed into stack\n";
        return true;
    }
}

template <typename T>
T Stack<T>::pop() {
    if (top < 0) {
        cout << "Stack Underflow\n";
        return T(); 
    } else {
        T x = arr[top--];
        return x;
    }
}

template <typename T>
T Stack<T>::peek() {
    if (top < 0) {
        cout << "Stack is Empty\n";
        return T(); 
    } else {
        return arr[top];
    }
}

template <typename T>
bool Stack<T>::isEmpty() {
    return (top < 0);
}

int main() {
    Stack<int> intStack; 
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);
    cout << intStack.pop() << " popped from stack\n";
    cout << "Top element is: " << intStack.peek() << endl;

    Stack<float> floatStack; 
    floatStack.push(1.1);
    floatStack.push(2.2);
    floatStack.push(3.3);
    cout << floatStack.pop() << " popped from stack\n";
    cout << "Top element is: " << floatStack.peek() << endl;

    Stack<char> charStack; 
    charStack.push('A');
    charStack.push('B');
    charStack.push('C');
    cout << charStack.pop() << " popped from stack\n";
    cout << "Top element is: " << charStack.peek() << endl;

    return 0;
}
