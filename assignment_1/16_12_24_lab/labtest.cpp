#include <iostream>
using  namespace std;

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
    void linearSearch(int val) {
        for (int i = 0; i < heap_size; i++) {
            if (arr[i] == val)
            {
                cout << "value found\n";
                return;
            }
        }
    }
};
int main()
{
    cout << "Hello World!\n";
}