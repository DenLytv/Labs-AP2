#include "BTree.h"

// Ctor
BTree::BTree(int t) {
    root = NULL;
    this->t = t;
}

// Traversal method
void BTree::traverse() {
    if (root != NULL)
        root->traverse();
}

// Insertion operation
void BTree::insert(int k) {
    if (root == NULL) {
        root = new TreeNode(t, true);
        root->keys[0] = k;
        root->n = 1;
    }
    else {
        if (root->n == 2 * t - 1) {
            TreeNode* s = new TreeNode(t, false);

            s->C[0] = root;

            s->splitChild(0, root);

            int i = 0;
            if (s->keys[0] < k)
                i++;
            s->C[i]->insertNonFull(k);

            root = s;
        }
        else
            root->insertNonFull(k);
    }
}

// Delete Operation
void BTree::remove(int k) {
    if (!root) {
        std::cout << "The tree is empty\n";
        return;
    }

    root->remove(k);

    if (root->n == 0) {
        TreeNode* tmp = root;
        if (root->leaf)
            root = NULL;
        else
            root = root->C[0];

        delete tmp;
    }
    return;
}

// Print the B-tree
void BTree::printTree() {
    if (!root) {
        std::cout << "The tree is empty\n";
        return;
    }

    printTree(root, 0);
}

// Helper function to print the B-tree recursively
void BTree::printTree(TreeNode* node, int level) {
    if (node == nullptr) {
        std::cout << "The tree is empty." << std::endl;
        return;
    }

    const int INDENTATION = 6;

    // Print the keys of the current node with indentation
    std::cout << std::setw(level * INDENTATION) << " ";
    for (int i = node->n - 1; i >= 0; --i) {
        std::cout << node->keys[i] << " ";
    }
    std::cout << std::endl;

    // Print children recursively
    for (int i = node->n; i >= 0; --i) {
        if (!node->leaf) {
            printTree(node->C[i], level + 1);
            if (i > 0) {
                std::cout << std::setw(level * INDENTATION) << " ";
            }
        }
    }
}