#include <iostream>
#include <string>
#include <Windows.h>

struct node
{
    int data;
    unsigned height;
    node* leftChild, * rightChild;
};

node* root = nullptr;

// Function to find the maximum value in the AVL tree
int findMax(node* t);

// Function to calculate the height of a node
int height(node* p);

// Function to create a new node with the given data
node* newNode(int element);

// Right rotation operation
node* rightRotate(node* p);

// Left rotation operation
node* leftRotate(node* p);

// Function to get the balance factor of a node
int getBalance(node* p);

// Recursive function to insert a new element into the AVL tree
node* insert(node*& p, int element);

// Function to perform inorder traversal of the AVL tree
void inorder(node* p);

// Function to print the maximum value, height, and inorder traversal of the AVL tree
void print(node* root);

int main()
{
    SetConsoleCP(1250);
    std::string str = "\0";
    int num = 0;
    while (true)
    {
        try
        {
            std::cout << "Enter a number (enter a blank to stop): ";
            getline(std::cin, str);
            if (str.empty()) break;
            for (size_t i = 0; i < str.length(); i++)
            {
                if (ispunct(str[i]) || isalpha(str[i]) || isspace(str[i])) {
                    if (i == 0 && str[i] == '-')
                        continue;
                    else
                        throw std::exception();
                }
            }
            num = std::stoi(str);
            root = insert(root, num);
        }
        catch (...)
        {
            std::cerr << "Error!! Your input is not a number or number is too large" << std::endl;
        }
    }

    print(root);

    return 0;
}

int findMax(node* t)
{
    while (t->rightChild != nullptr)
        t = t->rightChild;
    return t->data;
}

int height(node* p)
{
    if (p == nullptr)
        return -1;
    else
    {
        if (height(p->leftChild) > height(p->rightChild))
            p->height = height(p->leftChild);
        else
            p->height = height(p->rightChild);
    }
    return p->height + 1;
}

node* newNode(int element)
{
    node* newPtr = new node;
    newPtr->data = element;
    newPtr->leftChild = nullptr;
    newPtr->rightChild = nullptr;
    newPtr->height = 1;
    return newPtr;
}

node* rightRotate(node* p)
{
    node* child = p->leftChild; // Rotate the tree 
    p->leftChild = child->rightChild;
    child->rightChild = p;
    p->height = height(p); // Update the height for the nodes 
    child->height = height(child);
    return child; // Return new root
}

node* leftRotate(node* p)
{
    node* child = p->rightChild; // Perform the rotation
    p->rightChild = child->leftChild;
    child->leftChild = p;
    // Update the heights for the nodes
    p->height = height(p);
    child->height = height(child);

    return child; // Return new root 
}

int getBalance(node* p)
{
    if (p == nullptr)
        return 0;
    else
        return height(p->leftChild) - height(p->rightChild);
}

node* insert(node*& p, int element)
{
    if (p == nullptr)  // If the tree is empty 
        return(newNode(element));
    if (element < p->data)
    {
        p->leftChild = insert(p->leftChild, element);
    }
    else
    {
        p->rightChild = insert(p->rightChild, element);
    }

    p->height = height(p); // Update the height for this node

    int balance = getBalance(p); // Get the balance factor to see if the tree is unbalanced

    // Single Right Rotation (Left Left Case)
    if (balance > 1 && element < p->leftChild->data)
    {
        return rightRotate(p);
    }
    // Single Left Rotation (Right Right Case)
    if (balance < -1 && element > p->rightChild->data)
    {
        return leftRotate(p);
    }
    // Left Right Rotation (double left rotation)
    if (balance > 1 && element > p->leftChild->data)
    {
        p->leftChild = leftRotate(p->leftChild);
        return rightRotate(p);
    }
    // Right Left Rotation
    if (balance < -1 && element < p->rightChild->data)
    {
        p->rightChild = rightRotate(p->rightChild);
        return leftRotate(p);
    }

    return p;
}

void inorder(node* p)
{
    if (p != nullptr) {
        inorder(p->leftChild);
        std::cout << p->data << " ";
        inorder(p->rightChild);
    }
}

void print(node* root)
{
    if (root != nullptr) {
        std::cout << std::endl << "Max value: " << findMax(root) << std::endl;
        std::cout << "Height of the tree: " << height(root) << std::endl;
        std::cout << "Tree in order: ";
        inorder(root);
    }
    else
        std::cerr << "Error!!! Your tree is empty." << std::endl;
}