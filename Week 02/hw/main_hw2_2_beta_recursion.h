#include <iostream>
#include <vector>
#include <bitset>

void generateSubsets(const std::vector<char>& elements, int index, std::vector<char>& currentSubset) {
    if (index == elements.size()) {
        // Base case: reached the end of the elements, display the current subset
        std::cout << currentSubset.size() << ":";
        
        // Display binary representation
        std::bitset<10> binary(currentSubset.size());
        std::cout << binary << ":";

        // Display corresponding subset
        if (currentSubset.empty()) {
            std::cout << "EMPTY";
        } else {
            for (const char& element : currentSubset) {
                std::cout << " " << element;
            }
        }
        
        std::cout << "\n";
        return;
    }

    // Exclude the current element
    generateSubsets(elements, index + 1, currentSubset);

    // Include the current element
    currentSubset.push_back(elements[index]);
    generateSubsets(elements, index + 1, currentSubset);

    // Backtrack to exclude the current element for the next subset
    currentSubset.pop_back();
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

    std::vector<char> currentSubset;

    // Generate and display subsets using recursion
    generateSubsets(elements, 0, currentSubset);

    return 0;
}