#include <iostream>
#include <fstream>

// Definition of the hash table element class
class HashItem {
public:
    char key;            // Key of the hash item (character)
    int value;           // Value associated with the key (occurrence count)
    HashItem* next;     // Pointer to the next hash item in case of collisions

    // Constructor to initialize the hash item
    HashItem(char key, int value) : key(key), value(value), next(nullptr) {}
};

// Definition of the hash table class
class HashTable {
private:
    static const int SIZE = 128; // Size of the table (ASCII characters)

    // Array of pointers to hash table elements
    HashItem* table[SIZE];

public:
    // Constructor to initialize the hash table
    HashTable();

    // Hash function to calculate the index for a given key
    int hashFunction(char key);

    // Function to insert an element into the hash table
    void insert(char key, int value);

    // Function to display the hash table on the screen
    void display();

    // Function to count the occurrences of each letter in a text file
    void countOccurrencesInFile(const std::string& filename);
};