//#include <iostream>
//#include <vector>
//#include <bitset>
//
//void generateSubsets(const std::vector<std::string>& elements, int decimal, int index, std::vector<std::string>& currentSubset) {
//    // Base case: if index reaches the size of elements, display the result
//    if (index == elements.size()) {
//        std::cout << decimal << ":" << std::bitset<10>(decimal).to_string().substr(10 - elements.size()) << ":";
//        if (!currentSubset.empty()) {
//            std::cout << "{";
//            for (size_t i = 0; i < currentSubset.size(); ++i) {
//                std::cout << currentSubset[i];
//                if (i < currentSubset.size() - 1) {
//                    std::cout << ", ";
//                }
//            }
//            std::cout << "}";
//        }
//        else {
//            std::cout << "EMPTY";
//        }
//        std::cout << std::endl;
//        return;
//    }
//
//    // Include the current element in the subset
//    currentSubset.push_back(elements[index]);
//    generateSubsets(elements, decimal | (1 << index), index + 1, currentSubset);
//    currentSubset.pop_back();  // Exclude the current element in the subset
//    generateSubsets(elements, decimal, index + 1, currentSubset);
//}
//
//int main() {
//    int numElements;
//    std::cout << "Enter the number of elements in the set (less than 10): ";
//    std::cin >> numElements;
//
//    // Input elements
//    std::vector<std::string> elements(numElements);
//    std::cout << "Enter the elements of the set: ";
//    for (int i = 0; i < numElements; ++i) {
//        std::cin >> elements[i];
//    }
//
//    std::vector<std::string> currentSubset;
//    generateSubsets(elements, 0, 0, currentSubset);
//
//    return 0;
//}

//#include <iostream> 
//using namespace std;
//
//// function to convert decimal to binary 
//void decToBinary(int n)
//{
//	// array to store binary number 
//	int binaryNum[32];
//
//	// counter for binary array 
//	int i = 0;
//	while (n > 0) {
//
//		// storing remainder in binary array 
//		binaryNum[i] = n % 2;
//		n = n / 2;
//		i++;
//	}
//
//	// printing binary array in reverse order 
//	for (int j = i - 1; j >= 0; j--)
//		cout << binaryNum[j];
//}
//
//// Driver program to test above function 
//int main()
//{
//	int n = 'C';
//	decToBinary(n);
//	return 0;
//}

//#include <iostream>
//#include <bitset>
//
//int main() {
//    char myChar = 'C';  // You can replace 'A' with the char you want to convert
//
//    // Convert char to binary representation
//    std::bitset<3> binaryRepresentation(myChar);
//
//    // Display the binary representation
//    std::cout << "Binary representation of '" << myChar << "': " << binaryRepresentation << std::endl;
//
//    return 0;
//}

//#include <iostream>
//
//int main() {
//    // Array of characters with one "empty" element
//    char myArray[] = { 'A', 'B', '\0', 'C' };
//
//    // Check if an array element is "empty" (contains null character '\0')
//    for (int i = 0; i < sizeof(myArray) / sizeof(myArray[0]); ++i) {
//        if (myArray[i] == '\0') {
//            std::cout << "Element at index " << i << " is empty." << std::endl;
//        }
//    }
//
//    return 0;
//}

//#include <iostream>
//
//void displayCombinations(const char arr[], int index, int size, std::string currentCombination) {
//    // Base case: if index is equal to the size, display the current combination
//    if (index == size) {
//        std::cout << currentCombination << std::endl;
//        return;
//    }
//
//    // Exclude the current element
//    displayCombinations(arr, index + 1, size, currentCombination);
//
//    // Include the current element
//    displayCombinations(arr, index + 1, size, currentCombination + arr[index]);
//}
//
//int main() {
//    // Array of characters {1, 2, 3}
//    char myArray[] = { '1', '2', '3' };
//    int size = sizeof(myArray) / sizeof(myArray[0]);
//
//    // Display all combinations using recursion
//    std::cout << "All Combinations: " << std::endl;
//    displayCombinations(myArray, 0, size, "");
//
//    return 0;
//}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//#include <iostream>
//#include <string>
//
//void displayCombinations(const char arr[], int index, int size, std::string currentCombination) {
//
//    //Include '0' at the beginning only once
//    if (index == 0) {
//        std::cout << "0" << std::endl;
//    }
//
//    // Base case: if index is equal to the size, display the current combination
//    if (index == size) {
//
//        if (!currentCombination.empty()) {
//            std::cout << currentCombination << std::endl;
//        }
//        return;
//    }
//
//    // Exclude the current element
//    displayCombinations(arr, index + 1, size, currentCombination);
//
//    // Include the current element
//    displayCombinations(arr, index + 1, size, currentCombination + arr[index]);
//}
//
//int main() {
//    // Array of characters {1, 2, 3}
//    char myArray[] = { '1', '2', '3' };
//    int size = sizeof(myArray) / sizeof(myArray[0]);
//
//    // Display all combinations using recursion
//    std::cout << "All Combinations: " << std::endl;
//    displayCombinations(myArray, 0, size, "");
//
//    return 0;
//}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////// +++++++++ Get inout values ++++++++++ ////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <sstream>

int main() {
    std::string input;
    std::cout << "Enter a line of text: ";
    std::getline(std::cin, input);

    std::istringstream iss(input);
    std::string words[10]; // Array to store words, size is 10

    int index = 0;
    while (iss >> words[index] && index < 10) {
        index++;
    }

    std::cout << "Words separated and added to the array:\n";
    for (int i = 0; i < index; i++) {
        std::cout << "Word " << i + 1 << ": " << words[i] << std::endl;
    }

    return 0;
}
