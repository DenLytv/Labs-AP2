#include "HashTable.h"

HashTable::HashTable() {
    // Initialize all elements of the table to nullptr
    for (int i = 0; i < SIZE; ++i) {
        table[i] = nullptr;
    }
}

int HashTable::hashFunction(char key) {
    return key % SIZE;
}

void HashTable::insert(char key, int value) {
    int hash = hashFunction(key);
    HashItem* newItem = new HashItem(key, value);
    if (table[hash] == nullptr) {
        table[hash] = newItem;
    }
    else {
        HashItem* temp = table[hash];
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newItem;
    }
}

void HashTable::display() {
    for (int i = 0; i < SIZE; ++i) {
        HashItem* temp = table[i];
        std::cout << i << ": ";
        while (temp != nullptr) {
            std::cout << "[" << temp->key << "," << temp->value << "] ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
}

void HashTable::countOccurrencesInFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file" << std::endl;
        return;
    }
    char c;
    while (file.get(c)) {
        // Check if the character is a letter
        if (isalpha(c)) {
            // Convert the character to lowercase
            c = tolower(c);
            int hash = hashFunction(c);
            HashItem* current = table[hash];
            bool found = false;
            while (current != nullptr) {
                if (current->key == c) {
                    current->value++;
                    found = true;
                    break;
                }
                current = current->next;
            }
            if (!found) {
                insert(c, 1); // Insert the character with a value of 1 if not found
            }
        }
    }
    file.close();
}