#include <iostream>
using namespace std;

class heap {
    int* a;      // Pointer to the heap array
    int curr;    // Current number of elements in the heap
    int size;    // Maximum size of the heap

public:
    // Constructor
    heap(int s) {
        a = new int[s];
        size = s;
        curr = 0;
    }

    // Add an element to the heap
    void add(int val) {
        if (curr == size) {
            cout << "Heap is full\n";
            return;
        }

        a[curr] = val;
        int tmp = curr;
        curr++;

        // Bubble up to maintain min-heap property
        while (tmp != 0) {
            int p = (tmp - 1) / 2; // Parent index
            if (a[tmp] < a[p]) {
                swap(a[tmp], a[p]);
                tmp = p;
            } else {
                break;
            }
        }

        cout << val << " added\n";
    }

    // Display the heap
    void display() {
        for (int i = 0; i < curr; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    // Get the highest priority element (smallest in a min-heap)
    int getminpriority() {
        if (curr == 0) {
            cout << "Heap is empty\n";
            return -1;
        }
        return a[0];
    }

    // Heapify the subtree rooted at index i
    void heapify(int i = 0) {
        int left = 2 * i + 1;   // Left child
        int right = 2 * i + 2;  // Right child
        int smallest = i;       // Assume root is the smallest

        // Check if left child exists and is smaller than root
        if (left < curr && a[left] < a[smallest]) {
            smallest = left;
        }

        // Check if right child exists and is smaller than current smallest
        if (right < curr && a[right] < a[smallest]) {
            smallest = right;
        }

        // If the smallest is not the root
        if (smallest != i) {
            swap(a[i], a[smallest]);
            heapify(smallest); // Recursively heapify the affected subtree
        }
    }
};

int main() {
    heap h(5);
    h.add(20);
    h.add(10);
    h.add(2);
    h.add(76);

    cout << "\tDisplaying:\n";
    h.display();

    cout << "\tMin priority:\n";
    cout << h.getminpriority() << endl;

    return 0;
}
