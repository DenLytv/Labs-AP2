#include "BTree.h"

int main() {
    // Create a B-tree with minimum degree 5
    BTree tree(5);

    // Numbers to insert into the B-tree
    std::vector<int> nums = { 4, 6, 110, 8, 15, 10, 19, 20, 34, 21, 100 };

    // Insert numbers into the B-tree
    for (const int& num : nums) {
        tree.insert(num);
    }

    // Print the B-tree after insertion
    std::cout << "B-Tree after insertion: " << std::endl;
    tree.printTree();

    // Numbers to remove from the B-tree
    nums = { 6, 15, 19, 21 };

    // Remove numbers from the B-tree
    for (const int& num : nums) {
        tree.remove(num);
    }

    // Print the B-tree after removal
    std::cout << "B-Tree after removal: " << std::endl;
    tree.printTree();

    return 0;
}