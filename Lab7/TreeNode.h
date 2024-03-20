#pragma once
#include <iostream>

class TreeNode {
public:
    // Ctor
    TreeNode(int t, bool leaf);

    // Traversal method
    void traverse();

    // Find key index
    int findKey(int k);

    // Insertion method for non-full node
    void insertNonFull(int k);

    // Split child node during insertion
    void splitChild(int i, TreeNode* y);

    // Removal method
    void remove(int k);

    // Remove key from leaf node
    void removeFromLeaf(int idx);

    // Remove key from non-leaf node
    void removeFromNonLeaf(int idx);

    // Get predecessor of a key
    int getPredecessor(int idx);

    // Get successor of a key
    int getSuccessor(int idx);

    // Fill the child node to meet minimum requirements
    void fill(int idx);

    // Borrow a key from the previous child node
    void borrowFromPrev(int idx);

    // Borrow a key from the next child node
    void borrowFromNext(int idx);

    // Merge the child nodes
    void merge(int idx);

    friend class BTree;

private:
    int* keys;          // Array to store keys
    int t;              // Minimum degree (defines the range for number of keys)
    TreeNode** C;       // Array of child pointers
    int n;              // Current number of keys
    bool leaf;          // Is true if node is a leaf, false otherwise
};