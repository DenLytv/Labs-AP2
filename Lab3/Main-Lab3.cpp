#include "Queue.h"

int main() {
    Queue<int> q; // Create a Queue object of type int

    // Add elements to the queue
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(2);
    q.enqueue(1);

    // Check if the queue is a palindrome
    if (q.isQueuePalindrome()) {
        std::cout << "Your queue is a palindrome" << std::endl;
    }
    else {
        std::cout << "Your queue is not a palindrome" << std::endl;
    }

    // Print the first element of the queue
    std::cout << "First element of the queue: " << q.peek() << std::endl;

    // Print the size of the queue
    std::cout << "Size of the queue: " << q.size() << std::endl;

    // Print the elements of the queue
    q.print();

    // Remove an element from the queue
    q.dequeue();

    std::cout << "---------- After dequeue ---------" << std::endl;

    // Print the first element of the queue after dequeue
    std::cout << "First element of the queue: " << q.peek() << std::endl;

    // Print the size of the queue after dequeue
    std::cout << "Size of the queue: " << q.size() << std::endl;

    // Print the elements of the queue after dequeue
    q.print();

    return 0;
}