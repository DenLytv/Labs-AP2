#pragma once
#include <iostream>
#include <stack>

// Node structure for a Queue
template <typename T>
struct Node {
    T data;         // Data stored in the node
    Node* next;     // Pointer to the next node

    // Ctor
    Node(T value) {
        data = value;
        next = nullptr;
    }
};

// Class for implementing a Queue
template<typename T>
class Queue {
public:
    // Ctor
    Queue();

    // Function to add an element to the Queue
    void enqueue(T data);

    // Function to remove an element from the Queue
    void dequeue();

    // Function to print the elements of the Queue
    void print();

    // Function to get the size of the Queue
    int size();

    // Function to check if the Queue is empty
    bool isEmpty();

    // Function to get the element at the front of the Queue
    T peek();

    // Function to check if the Queue is a palindrome
    bool isQueuePalindrome();

    // Dtor
    ~Queue();

private:
    Node<T>* front;     // Pointer to the front of the Queue
    Node<T>* back;      // Pointer to the back of the Queue
};

template<typename T>
inline Queue<T>::Queue() {
    front = nullptr;
    back = nullptr;
}

template<typename T>
inline void Queue<T>::enqueue(T data) {
    Node<T>* newNode = new Node<T>(data);

    if (isEmpty()) {
        front = newNode;
        back = newNode;
    }
    else {
        back->next = newNode;
        back = newNode;
    }
}

template<typename T>
inline void Queue<T>::dequeue() {
    if (isEmpty()) {
        back = nullptr;
        std::cerr << "Error! Your queue is empty" << std::endl;
        return;
    }
    Node<T>* tmp = front;
    front = front->next;
    delete tmp;
}

template<typename T>
inline Queue<T>::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

template<typename T>
inline void Queue<T>::print() {
    if (isEmpty()) {
        std::cerr << "Error! Your queue is empty" << std::endl;
        return;
    }
    Node<T>* tmp = front;
    std::cout << "Queue: ";
    while (tmp != nullptr) {
        std::cout << tmp->data << " ";
        tmp = tmp->next;
    }
    std::cout << std::endl;
}

template<typename T>
inline int Queue<T>::size() {
    if (isEmpty()) {
        return 0;
    }
    else {
        Node<T>* tmp = front;
        int size = 0;
        while (tmp != nullptr) {
            ++size;
            tmp = tmp->next;
        }
        return size;
    }
}

template<typename T>
inline bool Queue<T>::isEmpty() {
    return front == nullptr;
}

template<typename T>
inline T Queue<T>::peek() {
    if (!isEmpty()) {
        return front->data;
    }
    else {
        std::cerr << "Error! Your queue is empty" << std::endl;
        exit(EXIT_FAILURE);
    }
}

template<typename T>
inline bool Queue<T>::isQueuePalindrome() {
    if (isEmpty()) {
        std::cerr << "Error! Your queue is empty" << std::endl;
        return false;
    }
    else {
        std::stack<T> stack;
        Node<T>* tmp = front;
        while (tmp != nullptr) {
            stack.push(tmp->data);
            tmp = tmp->next;
        }

        tmp = front;
        while (tmp != nullptr) {
            if (tmp->data != stack.top()) {
                return false;
            }
            stack.pop();
            tmp = tmp->next;
        }
        return true;
    }
}