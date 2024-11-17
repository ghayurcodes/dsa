#include <iostream>
#include <string>
using namespace std;

class Node {
private:
    int jobId;
    string userName;
    string documentName;
    int totalPages;
    Node* next;

public:
    Node(int id, string name, string doc, int pages) {
        this->jobId = id;
        this->userName = name;
        this->documentName = doc;
        this->totalPages = pages;
        this->next = NULL;
    }

    // Setter and Getter methods
    void setJobId(int id) { this->jobId = id; }
    int getJobId() { return jobId; }

    void setUserName(string name) { this->userName = name; }
    string getUserName() { return userName; }

    void setDocumentName(string doc) { this->documentName = doc; }
    string getDocumentName() { return documentName; }

    void setTotalPages(int pages) { this->totalPages = pages; }
    int getTotalPages() { return totalPages; }

    void setNext(Node* next) { this->next = next; }
    Node* getNext() { return next; }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    // Add a job to the queue
    void enqueue(Node* node) {
        if (front == NULL) {
            front = node;
            rear = node;
        } else {
            rear->setNext(node);
            rear = node;
        }
        cout << "Job added successfully.\n";
    }

    // Process (dequeue) the next job
    Node* dequeue() {
        if (front == NULL) {
            cout << "Queue is empty!\n";
            return NULL;
        } else {
            Node* temp = front;
            front = front->getNext();
            if (front == NULL) rear = NULL; // Reset the queue if it becomes empty
            return temp;
        }
    }

    // Display all pending print jobs
    void display() {
        if (front == NULL) {
            cout << "No jobs in the queue.\n";
            return;
        }
        Node* temp = front;
        cout << "Pending Print Jobs:\n";
        while (temp != NULL) {
            cout << "Job ID: " << temp->getJobId() << "\n";
            cout << "User Name: " << temp->getUserName() << "\n";
            cout << "Document Name: " << temp->getDocumentName() << "\n";
            cout << "Total Pages: " << temp->getTotalPages() << "\n\n";
            temp = temp->getNext();
        }
    }

    // Cancel a specific job by Job ID
    void cancelJob(int id) {
        Node* temp = front;
        Node* prev = NULL;
        while (temp != NULL) {
            if (temp->getJobId() == id) {
                if (prev == NULL) {
                    front = temp->getNext();
                } else {
                    prev->setNext(temp->getNext());
                }
                if (temp == rear) {
                    rear = prev; 
                    }
                    // Update rear if last node is removed
                delete temp;
                cout << "Job canceled successfully.\n";
                return;
            }
            prev = temp;
            temp = temp->getNext();
        }
        cout << "Job not found.\n";
    }

    // Get the total number of jobs in the queue
    int totalJobs() {
        int count = 0;
        Node* temp = front;
        while (temp != NULL) {
            count++;
            temp = temp->getNext();
        }
        return count;
    }
};

int main() {
    Queue myQueue;
    int choice;

    do {
        cout << "1. Add a new print job to the queue\n";
        cout << "2. Process the next print job\n";
        cout << "3. Display all pending print jobs\n";
        cout << "4. Cancel a specific print job by Job ID\n";
        cout << "5. View the total number of print jobs in the queue\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int id, pages;
            string name, doc;
            cout << "Enter Job ID: ";
            cin >> id;
            cin.ignore(); // Clear input buffer
            cout << "Enter User Name: ";
            getline(cin, name);
            cout << "Enter Document Name: ";
            getline(cin, doc);
            cout << "Enter Total Pages: ";
            cin >> pages;

            if (id <= 0 || pages <= 0 || name.empty() || doc.empty()) {
                cout << "Invalid input! Try again.\n";
                break;
            }

            Node* newNode = new Node(id, name, doc, pages);
            myQueue.enqueue(newNode);
            break;
        }

        case 2: {
            Node* job = myQueue.dequeue();
            if (job != NULL) {
                cout << "Processing Print Job:\n";
                cout << "Job ID: " << job->getJobId() << "\n";
                cout << "User Name: " << job->getUserName() << "\n";
                cout << "Document Name: " << job->getDocumentName() << "\n";
                cout << "Total Pages: " << job->getTotalPages() << "\n";
                delete job;
            }
            break;
        }

        case 3:
            myQueue.display();
            break;

        case 4: {
            int id;
            cout << "Enter Job ID to cancel: ";
            cin >> id;
            myQueue.cancelJob(id);
            break;
        }

        case 5:
            cout << "Total Jobs in Queue: " << myQueue.totalJobs() << "\n";
            break;

        case 6:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

        cout << endl;

    } while (choice != 6);

    return 0;
}
