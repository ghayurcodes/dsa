#include <iostream>
#include <queue>  // Include the queue library

using namespace std;

int main() {
    // Create a queue of integers
    queue<int> q;

    // Add elements to the queue
    q.push(10);  // First element
    q.push(20);  // Second element
    q.push(30);  // Third element

    // Display the front element
    cout << "Front element: " << q.front() << endl;

    // Display the back element
    cout << "Back element: " << q.back() << endl;

    // Remove the front element
    q.pop();

    // Display the front element again after pop
    cout << "Front element after pop: " << q.front() << endl;

    // Check if the queue is empty
    if (q.empty()) {
        cout << "The queue is empty!" << endl;
    } else {
        cout << "The queue is not empty!" << endl;
    }

    // Display the size of the queue
    cout << "Size of queue: " << q.size() << endl;

    return 0;
}
