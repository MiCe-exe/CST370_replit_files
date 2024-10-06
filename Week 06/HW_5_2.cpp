#include <iostream>
#include <vector>
#include <random>
//#include <chrono>
#include <ctime>
#include <iomanip>

using namespace std;

// Merge sort implementation (source: GeeksforGeeks with enhancements)
void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays
    vector<int> L(n1), R(n2);

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    // Merge the temporary arrays back into arr[l..r]
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        }
        else {
            arr[k++] = R[j++];
        }
    }

    // Copy the remaining elements of L[] and R[]
    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        // Same as (l + r) / 2, avoids overflow for large numbers
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted halves
        merge(arr, l, m, r);
    }
}

// Quick sort implementation (source: GeeksforGeeks with improvements)
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choose last element as pivot
    int i = (low - 1); // index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[p] is now at right place
        int pi = partition(arr, low, high);

        // Separately sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void Display(double q, double m) {
    cout << "===================== Execution Time ====================" << endl;
    cout << "Merge sort: \t" << m << setw(10) << " milliseconds"  << endl;
    cout << "Quick sort: \t" << q << " milliseconds" << endl;
    cout << "=========================================================" << endl;
}

int main() {
    int maxSize = 0;

    // ctime
    double mTime = 0;
    double qTime = 0;
    time_t t1;


    //Random Numbers
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, 1000000);

    cout << "Enter input size: ";

    cin >> maxSize;

    vector<int> dataQsort(maxSize);


    for (int i = 0; i < maxSize; i++) {
        dataQsort[i] = dis(gen);
    }

    //for (int i = 0; i < maxSize; i++) {
    //    cout << dataQsort[i] << " ";
    //}

    vector<int> dataMsort(dataQsort);

    // calculate the time example
    //t1 = clock();
    //// function call
    //mTime = (clock() - t1);

    t1 = clock();
    quickSort(dataQsort, 0, maxSize - 1);
    qTime = clock() - t1;

    t1 = clock();
    mergeSort(dataMsort, 0, maxSize - 1);
    mTime = clock() - t1;


    Display(qTime, mTime);
}
