#include <iostream>
#include <stack>

class QueueUsingTwoStacks {
private:
    std::stack<int> stack1;  // Stack for enqueue operation
    std::stack<int> stack2;  // Stack for dequeue operation

public:
    // Enqueue operation
    void enqueue(int x) {
        stack1.push(x);
    }

    // Dequeue operation
    void dequeue() {
        if (stack2.empty()) {
            if (stack1.empty()) {
                std::cout << "Queue is empty!" << std::endl;
                return;
            }
            // Move elements from stack1 to stack2
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        // Pop from stack2 which is the front of the queue
        std::cout << "Dequeued: " << stack2.top() << std::endl;
        stack2.pop();
    }

    // Front operation to get the front element
    int front() {
        if (stack2.empty()) {
            if (stack1.empty()) {
                std::cout << "Queue is empty!" << std::endl;
                return -1;  // Return an invalid value
            }
            // Move elements from stack1 to stack2
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        return stack2.top();  // Return the front element
    }

    // Empty operation to check if the queue is empty
    bool empty() {
        return stack1.empty() && stack2.empty();
    }

    // Size operation to get the number of elements in the queue
    int size() {
        return stack1.size() + stack2.size();
    }
};

int main() {
    QueueUsingTwoStacks queue;

    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);

    std::cout << "Front element: " << queue.front() << std::endl;  

    queue.dequeue();  // Dequeues 1
    std::cout << "Front element after dequeue: " << queue.front() << std::endl;  // Output: 2

    queue.dequeue();  // Dequeues 2
    queue.enqueue(7); 
    queue.dequeue();
     // Dequeues 3

     std::cout << "Front element: " << queue.front() << std::endl;  

    if (queue.empty()) {
        std::cout << "Queue is empty now!" << std::endl;  // Queue is empty now!
    }

    return 0;
}
