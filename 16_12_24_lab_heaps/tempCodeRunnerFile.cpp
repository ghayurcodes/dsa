#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MaxHeapValidator {
private:
    vector<int> heap;

    // Helper function to get the index of the left child
    int left(int i) { return 2 * i + 1; }

    // Helper function to get the index of the right child
    int right(int i) { return 2 * i + 2; }

    // Function to check the heap property at node i
    void checkHeapProperty(int i) {
        int l = left(i);
        int r = right(i);

        // Check if left child exists and violates the max heap property
        if (l < heap.size()) {
            if (heap[i] < heap[l]) {
                cout << "Error: Parent " << heap[i] << " is smaller than left child " << heap[l] << " at index " << i << endl;
            }
        }

        // Check if right child exists and violates the max heap property
        if (r < heap.size()) {
            if (heap[i] < heap[r]) {
                cout << "Error: Parent " << heap[i] << " is smaller than right child " << heap[r] << " at index " << i << endl;
            }
        }

        // Recursively check for errors in left and right subtrees
        if (l < heap.size()) checkHeapProperty(l);
        if (r < heap.size()) checkHeapProperty(r);
    }

public:
    // Constructor to initialize the heap
    MaxHeapValidator(vector<int>& h) : heap(h) {}

    // Function to validate the heap
    void validateHeap() {
        // Start checking from the root (index 0)
        checkHeapProperty(0);
    }
};

int main() {
    // Example of an invalid Max Heap
    vector<int> heap = {20, 15, 10, 5, 7, 8, 3};

    MaxHeapValidator validator(heap);

    cout << "Validating Heap..." << endl;
    validator.validateHeap();

    return 0;
}
