#include <iostream>
#include <string>

using namespace std;


struct Transaction {
    int transactionId;
    string transactionDetails;
    Transaction* next;

    Transaction(int id, string details) : transactionId(id), transactionDetails(details), next(nullptr) {}
};


class TransactionHistory {
private:
    Transaction* head;
    Transaction* tail;

public:
    TransactionHistory() : head(nullptr), tail(nullptr) {}

  
    void addTransaction(int id, string details) {
        Transaction* newTransaction = new Transaction(id, details);
        if (!head) {
            head = tail = newTransaction;
            tail->next = head;  
        } else {
            tail->next = newTransaction;
            tail = newTransaction;
            tail->next = head;  
        }
        cout << "Transaction added: ID = " << id << ", Details = " << details << endl;
    }

  
    void displayMostRecentTransaction() {
        if (!head) {
            cout << "No transactions available.\n";
            return;
        }
        cout << "Most recent transaction: ID = " << tail->transactionId << ", Details = " << tail->transactionDetails << endl;
    }

    
    void displayAllTransactions() {
        if (!head) {
            cout << "No transactions available.\n";
            return;
        }
        Transaction* temp = head;
        do {
            cout << "Transaction ID: " << temp->transactionId << ", Details: " << temp->transactionDetails << endl;
            temp = temp->next;
        } while (temp != head); 
    }
};

int main() {
    TransactionHistory history;

    history.addTransaction(101, "Purchased Item A");
    history.addTransaction(102, "Purchased Item B");
    history.addTransaction(103, "Refund for Item A");

    cout << "\nDisplaying all transactions:\n";
    history.displayAllTransactions();

    cout << "\nDisplaying the most recent transaction:\n";
    history.displayMostRecentTransaction();

    return 0;
}
