#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Task {
public:
    int taskId;
    string taskDescription;

    Task(int id, const string& description) : taskId(id), taskDescription(description) {}
};

class TaskQueue {
private:
    queue<Task> taskQueue;

public:
    void enqueue(int id, const string& description) {
        taskQueue.push(Task(id, description));
    }

    void dequeue() {
        if (!taskQueue.empty()) {
            Task task = taskQueue.front();
            taskQueue.pop();
            cout << "Processing Task ID: " << task.taskId << ", Description: " << task.taskDescription << endl;
        } else {
            cout << "Queue is empty!" << endl;
        }
    }

    void peek() {
        if (!taskQueue.empty()) {
            Task task = taskQueue.front();
            cout << "Next Task: ID: " << task.taskId << ", Description: " << task.taskDescription << endl;
        } else {
            cout << "Queue is empty!" << endl;
        }
    }

    bool isEmpty() {
        return taskQueue.empty();
    }
};

int main() {
    TaskQueue tq;

    tq.enqueue(1, "Print Documents");
    tq.enqueue(2, "Process Images");
    tq.enqueue(3, "Clean Server");

    tq.peek();

    tq.dequeue();
    tq.dequeue();
    tq.dequeue();

    tq.peek();

    return 0;
}
