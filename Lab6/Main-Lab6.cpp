#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>

const int MAX_KEYS = 3; // Maximum number of keys in a node

struct Node {
public:
	int keyCount;
	int keys[MAX_KEYS];
	Node* parent;
	Node* children[MAX_KEYS + 1];

	Node() {
		keyCount = 0;
		parent = nullptr;
		for (int i = 0; i < MAX_KEYS + 1; ++i)
			children[i] = nullptr;
	}
};

class Tree {
public:
	Node* root;
	Tree() : root(nullptr) {}
};

Node* search(Node* node, int val);
void splitNode(Tree* t, Node* p);
void insert(Tree* t, int val);
void printTreeHelper(Node* node);
void printTree(Tree* t);
void remove(Tree* t, int val);

int main() {
	Tree* t = new Tree();

	std::vector<int> nums = { 4, 6, 13, 7, 19, 20, 34, 28, 29, 100, 130, 140, 8, 15 };

	for (const int& num : nums)
	{
		insert(t, num);
	}

	printTree(t);

	nums = { 8, 130, 13, 34 };

	for (const int& num : nums)
	{
		remove(t, num);
	}

	printTree(t);

	delete t; // Free memory allocated for the tree
	return 0;
}


Node* search(Node* node, int val) {
	if (node == nullptr)
		return nullptr;

	int i = 0;
	while (i < node->keyCount && val > node->keys[i])
		++i;

	if (i < node->keyCount && val == node->keys[i])
		return node;

	if (node->children[i] != nullptr)
		return search(node->children[i], val);

	return nullptr;
}

void splitNode(Tree* t, Node* p) {
	if (p->keyCount < MAX_KEYS) {
		return;
	}
	if (p == t->root) {
		Node* n = new Node();
		Node* newRoot = new Node();
		n->keyCount = 1;
		n->keys[0] = p->keys[2];
		n->children[0] = p->children[2];
		n->children[1] = p->children[3];
		if (n->children[0] != nullptr) {
			n->children[0]->parent = n;
			n->children[1]->parent = n;
		}
		p->keyCount = 1;
		newRoot->keyCount = 1;
		newRoot->keys[0] = p->keys[1];
		newRoot->children[0] = p;
		newRoot->children[1] = n;
		p->parent = newRoot;
		n->parent = newRoot;
		newRoot->parent = nullptr;
		t->root = newRoot;
		return;
	}
	else {
		Node* n = new Node();
		n->keyCount = 1;
		n->keys[0] = p->keys[2];
		n->children[0] = p->children[2];
		n->children[1] = p->children[3];
		if (n->children[0] != nullptr) {
			n->children[0]->parent = n;
			n->children[1]->parent = n;
		}
		p->keyCount = 1;
		Node* parent = p->parent;
		int insertPos;
		for (insertPos = 0; insertPos <= parent->keyCount; insertPos++) {
			if (parent->children[insertPos] == p) {
				break;
			}
		}
		for (int i = parent->keyCount; i > insertPos; i--) {
			parent->keys[i] = parent->keys[i - 1];
		}
		for (int i = parent->keyCount + 1; i > insertPos + 1; i--) {
			parent->children[i] = parent->children[i - 1];
		}
		parent->keys[insertPos] = p->keys[1];
		parent->children[insertPos + 1] = n;
		n->parent = parent;
		parent->keyCount++;
		splitNode(t, parent);
		return;
	}
}

void insert(Tree* t, int val) {
	Node* q = search(t->root, val);
	if (q != nullptr) {
		std::cout << val << " already exists in the tree.\n";
		return;
	}

	if (t->root == nullptr) {
		t->root = new Node();
		t->root->keys[0] = val;
		t->root->keyCount = 1;
		std::cout << val << " successfully inserted in the tree.\n";
		return;
	}

	Node* p = t->root;
	while (true) {
		int i = 0;
		while (i < p->keyCount && p->keys[i] < val)
			++i;

		if (i < p->keyCount && p->keys[i] == val) {
			std::cout << val << " already exists in the tree.\n";
			return;
		}

		if (p->children[i] == nullptr) {
			// Insert into leaf node
			int j = p->keyCount - 1;
			while (j >= 0 && p->keys[j] > val) {
				p->keys[j + 1] = p->keys[j];
				--j;
			}
			p->keys[j + 1] = val;
			++p->keyCount;

			std::cout << val << " successfully inserted in the tree.\n";
			if (p->keyCount == MAX_KEYS)
				splitNode(t, p); // Split if necessary
			return;
		}
		else {
			p = p->children[i]; // Move to child node
		}
	}
}

void printTreeHelper(Node* node) {
	if (node == nullptr)
		return;

	std::cout << "(";
	for (int i = 0; i < node->keyCount; ++i) {
		printTreeHelper(node->children[i]);
		std::cout << node->keys[i];
		if (i < node->keyCount - 1)
			std::cout << ", ";
	}
	printTreeHelper(node->children[node->keyCount]);
	std::cout << ")";
}

void printTree(Tree* t) {
	std::cout << "2-3-4 tree: ";
	if (t == nullptr || t->root == nullptr) {
		std::cout << "Tree is empty." << std::endl;
		return;
	}
	printTreeHelper(t->root);
	std::cout << std::endl;
}

void remove(Tree* t, int val) {
	Node* node = search(t->root, val);
	if (node == nullptr) {
		std::cout << val << " not found in the tree.\n";
		return;
	}

	Node* parent = node->parent;
	if (node->keyCount == 1) {
		// Removal from a leaf
		if (parent != nullptr) {
			// Find sibling node
			Node* sibling;
			if (parent->children[0] == node)
				sibling = parent->children[1];
			else
				sibling = parent->children[0];

			if (sibling->keyCount > 1) {
				// If the sibling node has more than one key, remove the key from the current node
				for (int i = 0; i < parent->keyCount; ++i) {
					if (parent->children[i] == node) {
						parent->keys[i] = sibling->keys[0];
						sibling->keys[0] = 0;  // Clear the key value
						std::sort(sibling->keys, sibling->keys + sibling->keyCount);
						break;
					}
				}
			}
			else {
				// Merge with the sibling node if the sibling node has only one key
				int index;
				for (int i = 0; i < parent->keyCount; ++i) {
					if (parent->children[i] == node) {
						index = i;
						break;
					}
				}
				if (parent->children[0] == node) {
					sibling->keys[1] = parent->keys[0];
					parent->keys[0] = 0;
				}
				else {
					sibling->keys[1] = parent->keys[0];
					parent->keys[0] = 0;
				}
				for (int i = index; i < parent->keyCount - 1; ++i) {
					parent->keys[i] = parent->keys[i + 1];
				}
				parent->keyCount--;
				// Remove the node
				if (parent->children[0] == node) {
					parent->children[0] = parent->children[1];
					parent->children[1] = parent->children[2];
				}
				else {
					parent->children[1] = parent->children[2];
				}
				delete node;
			}
		}
		else {
			// Node is the root
			delete node;
			t->root = nullptr;
		}
	}
	else {
		// Removal from an internal node
		for (int i = 0; i < node->keyCount; ++i) {
			if (node->keys[i] == val) {
				for (int j = i; j < node->keyCount - 1; ++j) {
					node->keys[j] = node->keys[j + 1];
				}
				node->keyCount--;
				break;
			}
		}
	}
	std::cout << val << " removed from the tree.\n";
}