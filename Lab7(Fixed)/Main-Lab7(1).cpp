#include "HashTable.h"

int main() {
    HashTable hashTable;
    hashTable.countOccurrencesInFile("text.txt");
    hashTable.display();
    return 0;
}