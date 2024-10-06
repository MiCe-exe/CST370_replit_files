/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw5_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw5_1.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, Name, and Date.
/*
 * Title: main_hw5_1.cpp
 * Abstract: Heap operations with number elements set by the first value,
 * followed by elements to be inserted into the heap. Number of commands to be
 * executed, followed by the commands. Name: Michael Cervantes Date: 2/12/2024
 */

#include <iostream>
#include <vector>

using namespace std;

void maxHeapify(vector<int> &heap, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < heap.size() && heap[left] > heap[largest]) {
    largest = left;
  }

  if (right < heap.size() && heap[right] > heap[largest]) {
    largest = right;
  }

  if (largest != i) {
    swap(heap[i], heap[largest]);
    maxHeapify(heap, largest);
  }
}

void buildHeap(vector<int> &heap) {
  for (int i = heap.size() / 2 - 1; i >= 0; i--) {
    maxHeapify(heap, i);
  }
}

void displayMax(const vector<int> &heap) {
  if (heap.empty()) {
    cout << "Heap is empty." << endl;
  } else {
    cout << heap[0] << endl;
  }
}

void insert(vector<int> &heap, int value) {
  heap.push_back(value);
  int i = heap.size() - 1;

  while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
    swap(heap[(i - 1) / 2], heap[i]);
    i = (i - 1) / 2;
  }
}

void deleteMax(vector<int> &heap) {
  if (heap.empty()) {
    cout << "Heap is empty." << endl;
  } else {
    heap[0] = heap.back();
    heap.pop_back();
    maxHeapify(heap, 0);
  }
}

void display(const vector<int> &heap) {
  if (heap.empty()) {
    cout << "Heap is empty." << endl;
  } else {
    for (int i = 0; i < heap.size(); i++) {
      if (i == heap.size() - 1) {
        cout << heap[i];
      } else {
        cout << heap[i] << " ";
      }
    }
    cout << endl;
  }
}

int main() {
  int numElements, numCommands;
  cin >> numElements;

  vector<int> heap(numElements);
  for (int i = 0; i < numElements; i++) {
    cin >> heap[i];
  }

  bool isHeap = true;
  for (int i = 0; i < numElements / 2; i++) {
    if (heap[2 * i + 1] > heap[i] ||
        (2 * i + 2 < numElements && heap[2 * i + 2] > heap[i])) {
      isHeap = false;
      break;
    }
  }

  if (isHeap) {
    cout << "This is a heap." << endl;
  } else {
    cout << "This is NOT a heap." << endl;
    buildHeap(heap);
  }

  cin >> numCommands;
  for (int i = 0; i < numCommands; i++) {
    string command;
    cin >> command;

    if (command == "displayMax") {
      displayMax(heap);
    } else if (command == "insert") {
      int value;
      cin >> value;
      insert(heap, value);
    } else if (command == "deleteMax") {
      deleteMax(heap);
    } else if (command == "display") {
      display(heap);
    } else {
      cout << "Invalid command." << endl;
    }
  }

  return 0;
}
