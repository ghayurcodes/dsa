#include <iostream>
#include <vector>

using namespace std;

// Merge function: Combine two sorted parts of the array
void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp; // Temporary array to store merged elements

    int i = left;    // Starting index for the left subarray
    int j = mid + 1; // Starting index for the right subarray

    // Merge elements from both subarrays in sorted order
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }

    // Add remaining elements from the left subarray (if any)
    while (i <= mid) {
        temp.push_back(arr[i++]);
    }

    // Add remaining elements from the right subarray (if any)
    while (j <= right) {
        temp.push_back(arr[j++]);
    }

    // Copy sorted elements back into the original array
    for (int k = 0; k < temp.size(); ++k) {
        arr[left + k] = temp[k];
    }
}

// Merge Sort function
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Find the middle point

        // Recursively sort the left and right halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Helper function to print the array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    cout << "Original array: ";
    printArray(arr);

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
