#include <iostream>
#define SIZE 5  // Define the maximum size of the queue

using namespace std;

class Queue {
private:
    int items[SIZE];
    int front, rear;

public:
    Queue() : front(-1), rear(-1) {}

    // Check if the queue is full
    bool isFull() {
        return rear == SIZE - 1;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == -1 || front > rear;
    }

    // Enqueue: Add an element to the queue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue " << value << "." << endl;
            return;
        }
        if (isEmpty()) {
            front = 0;  // Set front to 0 when adding the first element
        }
        rear++;
        items[rear] = value;
        cout << "Enqueued " << value << endl;
    }

    // Dequeue: Remove an element from the queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1;
        }
        int removedValue = items[front];
        front++;
        // Reset front and rear if the queue becomes empty after dequeue
        if (front > rear) {
            front = rear = -1;
        }
        return removedValue;
    }

    // Display the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << items[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    // Perform enqueue operations
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    
    // Trying to add another element to a full queue
    q.enqueue(60);

    // Display the queue
    q.display();

    // Perform dequeue operations
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;

    // Display the queue again
    q.display();

    return 0;
}
