#pragma once
#include <iostream>

namespace Task1 {
    template <typename T>
    class Stack
    {
    public:
        Stack(); // constructor
        void push(T val); // adds an element to the stack
        void pop(); // removes an element from the stack
        T peek(); // returns the value of the top of the stack
    private:
        bool isEmpty(); // checks if the stack is empty
        bool isFull(); // checks if the stack is full
        static const int MAX_SIZE = 100; // the maximum size of the array
        int top; // a pointer to the top of the stack
        T arr[MAX_SIZE]; // array for data storage
    };

    template<typename T>
    inline Stack<T>::Stack()
    {
        top = -1; // initialize the top of the stack as -1 (empty stack)
    }

    template<typename T>
    inline bool Stack<T>::isEmpty()
    {
        return top == -1;
    }

    template<typename T>
    inline bool Stack<T>::isFull()
    {
        return top == MAX_SIZE - 1;
    }

    template<typename T>
    inline void Stack<T>::push(T val)
    {
        if (isFull()) {
            std::cout << "The stack is full. Unable to add item." << std::endl;
            return;
        }
        arr[++top] = val;
    }

    template<typename T>
    inline void Stack<T>::pop()
    {
        if (isEmpty()) {
            std::cout << "The stack is empty. Unable to delete item." << std::endl;
            return;
        }
        --top;
    }

    template<typename T>
    inline T Stack<T>::peek()
    {
        if (isEmpty()) {
            std::cout << "The stack is empty. Unable to view the top." << std::endl;
            return -1; // return -1 in the case of an empty stack
        }
        return arr[top];
    }
}

namespace Task2 {
    class Stack
    {
    public:
        Stack(); // ctor
        void push(int val); // adds an element to the stack
        void pop(); // pull an element from the stack
        int peek(); // a view of the element placed at the top of the stack
        void print(); // a function that prints the stack
        double avarage();
        ~Stack(); // destructor
    private:
        bool isEmpty(); // a function that determines if the stack is empty
        int* stack; // a dynamic stack pointer array
        int count; // the top of the stack is the number of elements in the stack
    };

    inline Stack::Stack()
    {
        stack = nullptr;
        count = 0; // initialize the top of the stack as 0 (empty stack)
    }

    inline void Stack::push(int val)
    {
        int* tmp; // temporary pointer
        try { // in case if memory is not allocated
            tmp = stack;
            stack = new int[count + 1];
            ++count;
            for (int i = 0; i < count - 1; i++)
            {
                stack[i] = tmp[i];
            }
            stack[count - 1] = val;

            if (count > 1)
            {
                delete[] tmp;
                tmp = nullptr;
            }
        }
        catch (std::bad_alloc e)
        {
            // if memory is not allocated
            std::cout << e.what() << std::endl;
        }
    }
    inline void Stack::pop()
    {
        if (isEmpty())
        {
            std::cout << "The stack is empty. Unable to delete item." << std::endl;
            return;
        }
        --count;
    }
    inline int Stack::peek()
    {
        if (isEmpty()) {
            std::cout << "The stack is empty. Unable to view the top." << std::endl;
            return -1;
        }
        return stack[count - 1];
    }
    inline Stack::~Stack()
    {
        if (count > 0)
            delete[] stack;
    }
    inline bool Stack::isEmpty()
    {
        return count == 0;
    }
    inline void Stack::print()
    {
        int* p = stack; // temporary pointer, moves through the elements of the stack
        if (isEmpty())
        {
            std::cout << "The stack is empty." << std::endl;
            return;
        }
        std::cout << "Stack: ";
        for (int i = 0; i < count; i++)
        {
            std::cout << *p << "  ";
            ++p; // scroll the pointer to the next item
        }
        std::cout << std::endl;
        p = nullptr;
    }
    inline double Stack::avarage()
    {
        if (isEmpty()) {
            std::cout << "The stack is empty." << std::endl;
            return 0.0;
        }
        int* p = stack; // temporary pointer, moves through the elements of the stack
        int sum = 0; // sum of even elements
        int evenCount = 0; // number of even elements
        for (int i = 0; i < count; i++)
        {
            if (*p % 2 == 0) { // check if number is even
                sum += *p;
                ++evenCount;
            }
            ++p;
        }
        p = nullptr;
        return sum / evenCount;
    }
}