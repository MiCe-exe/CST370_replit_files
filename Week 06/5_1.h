#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to check if the array is a max heap
bool isMaxHeap(vector<int>& arr, int n) {
    // Start from the second node, as parent of the first node is always the root
    for (int i = 1; i < n; ++i) {
        int parentIndex = (i - 1) / 2;
        // If parent is smaller than child, heap property is violated
        if (arr[i] > arr[parentIndex]) {
            return false;
        }
    }
    return true;
}

// Function to build a max heap from the given array
void buildMaxHeap(vector<int>& arr, int n) {
    // Start from the middle node and go up recursively
    for (int i = n / 2 - 1; i >= 0; --i) {
        maxHeapify(arr, n, i);
    }
}

// Function to maintain max heap property after insert or delete
void maxHeapify(vector<int>& arr, int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // See if left child of root exists and is greater than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // See if right child of root exists and is greater than root
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // Change root, if needed
    if (largest != i) {
        swap(arr[i], arr[largest]);
        // Heapify the root
        maxHeapify(arr, n, largest);
    }
}

// Function to insert a new element into the heap
void insert(vector<int>& arr, int& n, int key) {
    // Increase heap size and place new element at end
    ++n;
    arr[n - 1] = key;

    // Fix heap property
    maxHeapify(arr, n, n - 1);
}

// Function to delete the root (max element)
void deleteMax(vector<int>& arr, int& n) {
    if (n == 0) {
        cout << "Heap is empty" << endl;
        return;
    }

    // Replace root with the last element
    arr[0] = arr[n - 1];
    --n;

    // Fix heap property
    maxHeapify(arr, n, 0);
}

// Function to display the heap elements
void display(vector<int>& arr, int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;

    // Input the number of elements
    cout << "Enter the number of elements: ";
    cin >> n;

    // Input the elements
    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Check if the array is a max heap
    if (!isMaxHeap(arr, n)) {
        cout << "This is NOT a heap." << endl;
        buildMaxHeap(arr, n);
    }
    else {
        cout << "This is a heap." << endl;
    }

    // Read the number of commands
    int numCommands;
    cout << "Enter the number of commands: ";
    cin >> numCommands;

    // Process each command
    for (int i = 0; i < numCommands; ++i) {
        string command;
        int value;

        cin >> command;

        if (command == "displayMax") {
            if (n == 0) {
                cout << "Heap is empty" << endl;
            }
            else {
                cout << arr[0] << endl;
            }
        }
        else if (command == "insert") {
