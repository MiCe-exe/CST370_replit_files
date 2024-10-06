#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class ProbingHashTable {
private:
    vector<int> table;
    int size;
    int currentSize;

    int getNextPrime(int num) {
        while (!isPrime(++num)) {
            // just incrmeet no logic needed here.
        }
            
        return num;
    }

    bool isPrime(int num) {
        if (num <= 1)
            return false;
        for (int i = 2; i <= sqrt(num); ++i) {
            if (num % i == 0)
                return false;
        }
        return true;
    }

    void rehash() {
        int newSize = getNextPrime(2 * size);
        vector<int> newTable(newSize, -1);

        for (int i = 0; i < size; ++i) {
            if (table[i] != -1) {
                int newIndex = table[i] % newSize;
                while (newTable[newIndex] != -1) {
                    newIndex = (newIndex + 1) % newSize;
                }
                newTable[newIndex] = table[i];
            }
        }

        table = newTable;
        size = newSize;
    }

public:
    ProbingHashTable(int initialSize) : size(initialSize), currentSize(0) {
        table.resize(size, -1);
    }

    void insert(int key) {
        if (currentSize >= size / 2) {
            rehash();
        }

        int index = key % size;
        while (table[index] != -1) {
            index = (index + 1) % size;
        }

        table[index] = key;
        ++currentSize;
    }

    void displayStatus(int index) {
        if (table[index] == -1) {
            cout << "Empty" << endl;
        }
        else {
            cout << table[index] << endl;
        }
    }

    void displayTableSize() {
        cout << size << endl;
    }

    bool search(int key) {
        int index = key % size;
        while (table[index] != -1) {
            if (table[index] == key) {
                return true;
            }
            index = (index + 1) % size;
        }
        return false;
    }
};

int main() {
    int initialSize, numCommands;
    cin >> initialSize >> numCommands;

    ProbingHashTable hashTable(initialSize);

    while (numCommands-- > 0) {
        string command;
        cin >> command;

        if (command == "insert") {
            int key;
            cin >> key;
            hashTable.insert(key);
        }
        else if (command == "displayStatus") {
            int index;
            cin >> index;
            hashTable.displayStatus(index);
        }
        else if (command == "tableSize") {
            hashTable.displayTableSize();
        }
        else if (command == "search") {
            int key;
            cin >> key;
            //cout << key << " " << (hashTable.search(key) ? "Found" : "Not found") << endl;
            if(hashTable.search(key)){
                cout << key << " FOUND" << endl;
            } else {
                cout << key << " Not found" << endl;
            }
        }
    }

    return 0;
}
