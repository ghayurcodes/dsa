#include <iostream>
using namespace std;

class deque {
    int qfront;
    int rear;
    int size;
    int *arr;

public:
    deque(int size) {
        this->size = size;
        arr = new int[size];
        qfront = -1;
        rear = -1;
    }

   
    void push_back(int data) {
        // Queue is full
        if ((qfront == 0 && rear == size - 1) || (rear == (qfront - 1) % (size))) {
            cout << "Queue is full\n";
            return;
        } 
        // First element insertion
        else if (qfront == -1) {
            qfront = rear = 0;
            arr[rear] = data;
        } 
        // To maintain cyclic nature
        else if (rear == size - 1 && qfront != 0) {
            rear = 0;
            arr[rear] = data;
        } 
        // Normal case
        else {
            rear++;
            arr[rear] = data;
        }
    }



      void push_front(int data) {
        // Queue is full
        if ((qfront == 0 && rear == size - 1) || (rear == (qfront - 1) % (size))) {
            cout << "Queue is full\n";
            return;
        } 
        // First element insertion
        else if (qfront == -1) {
            qfront = rear = 0;
            arr[qfront] = data;
        } 
        // To maintain cyclic nature
        else if (qfront==0) {
            qfront = size-1;
            arr[qfront] = data;
        } 
        // Normal case
        else {
            qfront--;
            arr[qfront] = data;
        }
    }
  
    void pop_front() {
        // Queue is empty
        if (qfront == -1) {
            cout << "Queue is empty\n";
            return;
        }

        // Single element in queue
        if (qfront == rear) {
            qfront = rear = -1;
        } 
        // To maintain cyclic nature
        else if (qfront == size - 1) {
            qfront = 0;
        } 
        // Normal case
        else {
            qfront++;
        }
    }


 void pop_back() {
        // Queue is empty
        if (rear == -1) {
            cout << "Queue is empty\n";
            return;
        }

        // Single element in queue
        if (qfront == rear) {
            qfront = rear = -1;
        } 
        // To maintain cyclic nature
        else if (rear==0) {
            rear=size-1;
        } 
        // Normal case
        else {
            rear--;
        }
    }

    

    // Method to get the front element of the queue
    int front() {
        if (qfront == -1) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[qfront];
    }

    int backk() {
        if (rear == -1) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[rear];
    }

    // Method to check if the queue is empty
    bool isempty() {
        return (qfront == -1);
    }

    // Method to display the queue elements
    void display() {
        if (qfront == -1) {
            cout << "Queue is empty\n";
            return;
        }
        if (rear >= qfront) {
            for (int i = qfront; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        } else {
            for (int i = qfront; i < size; i++) {
                cout << arr[i] << " ";
            }
            for (int i = 0; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
};

int main() {
    deque q(5);

    q.push_front(3);
    q.push_front(7);
    q.push_back(4);
    

    cout << "Front element: " << q.front() << endl;
     cout << "rear element: " << q.backk() << endl;         //hard dsa tounderstand but very fun to use
    
    q.pop_front();
    q.pop_back();
   
    q.display();

    return 0;
}
