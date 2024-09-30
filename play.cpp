#include <iostream>
using namespace std;

int main() {
    int* ptr1 = new int(5);   // Dynamically allocate memory, ptr1 points to this memory
    int*ptr2 = ptr1;         // ptr2 now points to the same memory as ptr1

    cout << "Value pointed by ptr1: " << *ptr1 << endl;  // Output: 5
    cout << "Value pointed by ptr2: " << *ptr2 << endl;  // Output: 5

    *ptr2 = 10;  // Modify the value using ptr2

    cout << "Value pointed by ptr1 after modification: " << *ptr1 << endl;  // Output: 10
    cout << "Value pointed by ptr2 after modification: " << *ptr2 << endl;  // Output: 10
    cout<<sizeof(ptr2)<<endl;




    delete ptr1;  // Delete the dynamically allocated memory
    // Note: No need to delete ptr2 separately because ptr2 points to the same memory as ptr1

    ptr1 = nullptr;
    ptr2 = nullptr;  // Set both to nullptr to avoid dangling pointers
    cout<<*ptr1<<" "<<*ptr2<<endl;

    return 0;
}
