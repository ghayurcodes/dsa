#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

// MinHeap Class
class MinHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] < heap[parent]) {
                swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();
        while (index < size) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallest = index;

            if (left < size && heap[left] < heap[smallest]) {
                smallest = left;
            }
            if (right < size && heap[right] < heap[smallest]) {
                smallest = right;
            }
            if (smallest != index) {
                swap(heap[index], heap[smallest]);
                index = smallest;
            } else {
                break;
            }
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int extractMin() {
        if (heap.empty()) {
            throw runtime_error("Heap is empty");
        }
        int minValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return minValue;
    }

    void display() {
        for (int value : heap) {
            cout << value << " ";
        }
        cout << endl;
    }
};

int main() {
    MinHeap minHeap;

    // Inserting values into the Min Heap
    minHeap.insert(10);
    minHeap.insert(5);
    minHeap.insert(20);
    minHeap.insert(15);

    cout << "Min Heap after inserting 10, 5, 20, 15: ";
    minHeap.display();

    cout << "Extracted min: " << minHeap.extractMin() << endl;
    cout << "Min Heap after extracting min: ";
    minHeap.display();

    cout << "Extracted min: " << minHeap.extractMin() << endl;
    cout << "Min Heap after extracting min: ";
    minHeap.display();

    return 0;
}
 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MaxHeapValidator {
private:
    vector<int> heap;

    
    int left(int i) { return 2 * i + 1; }

    
    int right(int i) { return 2 * i + 2; }

  
    void checkHeapProperty(int i) {
        int l = left(i);
        int r = right(i);

        
        if (l < heap.size()) {
            if (heap[i] < heap[l]) {
                cout << "Error: Parent " << heap[i] << " is smaller than left child " << heap[l] << " at index " << i << endl;
            }
            
            checkHeapProperty(l);
        }

        
        if (r < heap.size()) {
            if (heap[i] < heap[r]) {
                cout << "Error: Parent " << heap[i] << " is smaller than right child " << heap[r] << " at index " << i << endl;
            }
          
            checkHeapProperty(r);
        }
    }

public:
    
    MaxHeapValidator(vector<int>& h) : heap(h) {}

    
    void validateHeap() {
    
        checkHeapProperty(0);
    }
};

int main() {
    
    vector<int> heap = {20, 15, 10, 5, 7, 8, 3,13,60,78};

    MaxHeapValidator validator(heap);

    cout << "Validating Heap..." << endl;
    validator.validateHeap();

    return 0;
}
