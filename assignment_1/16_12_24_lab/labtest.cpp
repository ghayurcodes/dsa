#include <iostream>
using namespace std;

class minHeap {
public:
    int* arr;
    int capacity;
    int heap_size;

    minHeap(int cap) {
        heap_size = 0;
        capacity = cap;
        arr = new int[cap];
    }

    // Function to insert a new value into the heap
    void insert(int val) {
        if (heap_size == capacity) {
            cout << "Heap is full. Cannot insert more elements.\n";
            return;
        }

        
        heap_size++;
        int i = heap_size - 1;
        arr[i] = val;

     
        while (i != 0 && arr[(i - 1) / 2] < arr[i]) {
            swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    // Function to display the heap elements
    void display() {
        if (heap_size == 0) {
            cout << "Heap is empty.\n";
            return;
        }
        cout << "Heap elements: ";
        for (int i = 0; i < heap_size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Function to search for a value in the heap
    void linearSearch(int val) {
        for (int i = 0; i < heap_size; i++) {
            if (arr[i] == val) {
                cout << "Value found\n";
                return;
            }
        }
        cout << "Value not found\n";
    }
};

int main() {
    minHeap heap(10);

    // Insert some elements into the heap
    heap.insert(15);
    heap.insert(10);
    heap.insert(20);
    heap.insert(5);
    heap.insert(7);

    // Display the heap elements
    heap.display();  // Output: Heap elements: 5 7 20 15 10

    // Search for a value
    heap.linearSearch(10); // Output: Value found
    heap.linearSearch(25); // Output: Value not found

    return 0;
}
