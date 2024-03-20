#pragma once
#include <iomanip>
#include <vector>
#include "TreeNode.h"

class BTree {
public:
    // Ctor
    BTree(int t);

    // Traversal method
    void traverse();

    // Insertion method
    void insert(int k);

    // Removal method
    void remove(int k);

    // Print the B-tree
    void printTree();

    // Helper function to print the B-tree recursively
    void printTree(TreeNode* node, int indent);

private:
    TreeNode* root; // Pointer to the root node
    int t;          // Minimum degree of the B-tree
};