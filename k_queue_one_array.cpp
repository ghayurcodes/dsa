#include <iostream>
using namespace std;

class KQueue {
    int *arr;       // Array to store the elements of the queues
    int *front;     // Front indices of the K queues
    int *rear;      // Rear indices of the K queues
    int *next;      // Next free index
    int k;          // Number of queues
    int n;          // Size of the array
    int freeIndex;  // Next free index in the array

public:
    KQueue(int k, int n) {
        this->k = k;
        this->n = n;
        arr = new int[n];
        front = new int[k];
        rear = new int[k];
        next = new int[n];

        // Initialize all front pointers to -1
        for (int i = 0; i < k; i++) {
            front[i] = -1;
            rear[i] = -1;
        }

        // Initialize the next array
        for (int i = 0; i < n - 1; i++) {
            next[i] = i + 1;
        }
        next[n - 1] = -1; // No free index after the last element
        freeIndex = 0;    // Start with the first index
    }

    // Function to check if the queue is full
    bool isFull() {
        return freeIndex == -1;
    }

    // Function to enqueue an element in queue number 'qn'
    void enqueue(int item, int qn) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }

        int index = freeIndex; // Get the next free index
        freeIndex = next[index]; // Update freeIndex to next free index

        // If this is the first element in the queue
        if (front[qn] == -1) {
            front[qn] = index; // Update front index for queue qn
        } else {
            next[rear[qn]] = index; // Link the new index to the rear
        }

        next[index] = -1; // Set the next of the new element to -1
        rear[qn] = index; // Update the rear index for queue qn
        arr[index] = item; // Insert the item
    }

    // Function to dequeue an element from queue number 'qn'
    int dequeue(int qn) {
        if (front[qn] == -1) {
            cout << "Queue Underflow\n";
            return -1; // Queue is empty
        }

        int index = front[qn]; // Get the front index of the queue
        front[qn] = next[index]; // Update front to the next element

        // If this was the last element, update rear as well
        if (front[qn] == -1) {
            rear[qn] = -1;
        }

        // Free the index for future use
        next[index] = freeIndex;
        freeIndex = index;

        return arr[index]; // Return the dequeued item
    }

    // Function to display the contents of a specific queue
    void displayQueue(int qn) {
        if (front[qn] == -1) {
            cout << "Queue " << qn << " is empty.\n";
            return;
        }

        cout << "Queue " << qn << ": ";
        for (int i = front[qn]; i != -1; i = next[i]) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Destructor to free allocated memory
    ~KQueue() {
        delete[] arr;
        delete[] front;
        delete[] rear;
        delete[] next;
    }
};

int main() {
    int k = 3; // Number of queues
    int n = 10; // Size of the array

    KQueue kQueue(k, n);

    // Enqueue elements
    kQueue.enqueue(10, 0);
    kQueue.enqueue(20, 0);
    kQueue.enqueue(30, 1);
    kQueue.enqueue(40, 1);
    kQueue.enqueue(50, 2);
    kQueue.enqueue(60, 2);

    // Display queues
    kQueue.displayQueue(0);
    kQueue.displayQueue(1);
    kQueue.displayQueue(2);

    // Dequeue elements
    cout << "Dequeued from Queue 0: " << kQueue.dequeue(0) << endl;
    cout << "Dequeued from Queue 1: " << kQueue.dequeue(1) << endl;

    // Display queues again
    kQueue.displayQueue(0);
    kQueue.displayQueue(1);
    kQueue.displayQueue(2);

    return 0;
}
