#include <iostream>
#include <vector>
#include <bitset>

void generateSubsets(const std::vector<char>& elements) {
    int n = elements.size();

    // Display decimal and binary numbers along with subsets
    for (int i = 0; i < (1 << n); ++i) {
        std::cout << i << ":";
        
        // Display binary representation
        std::bitset<10> binary(i);
        std::cout << binary << ":";

        // Display corresponding subset
        std::cout << "EMPTY";
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                std::cout << " " << elements[j];
            }
        }
        
        std::cout << "\n";
    }
}

int main() {
    int numElements;
    std::cout << "Enter the number of elements in the set (less than 10): ";
    std::cin >> numElements;

    if (numElements >= 10 || numElements <= 0) {
        std::cerr << "Invalid number of elements. Exiting program.\n";
        return 1;
    }

    // Read elements of the set
    std::vector<char> elements(numElements);
    std::cout << "Enter the elements of the set: ";
    for (int i = 0; i < numElements; ++i) {
        std::cin >> elements[i];
    }

    // Generate and display subsets
    generateSubsets(elements);

    return 0;
}