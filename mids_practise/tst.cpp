#include <iostream>
#define SIZE 5  // Define the maximum size of the queue

using namespace std;

class CircularQueue {
private:
    int items[SIZE];
    int front, rear;

public:
    CircularQueue() : front(-1), rear(-1) {}

    // Check if the queue is full
    bool isFull() {
        return (rear + 1) % SIZE == front;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Enqueue: Add an element to the queue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue " << value << "." << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % SIZE;  // Move rear to the next position
        }
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
        if (front == rear) {
            // Queue is empty after this dequeue
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;  // Move front to the next position
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
        int i = front;
        while (true) {
            cout << items[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;

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

    // Add more elements after dequeuing
    q.enqueue(60);
    q.enqueue(70);

    // Display the queue after adding more elements
    q.display();

    return 0;
}
