#include "Stack.h"

int main()
{
    std::cout << "--------------- Task 1 --------------" << std::endl;
    Task1::Stack<int> stack;

    stack.push(5);
    stack.push(10);
    stack.push(15);

    std::cout << "Top of stack: " << stack.peek() << std::endl;

    stack.pop();
    std::cout << "Top of stack after deletion: " << stack.peek() << std::endl << std::endl;


    std::cout << "--------------- Task 2 --------------" << std::endl;
    Task2::Stack stack1;
    stack1.push(11);
    stack1.push(16);
    stack1.push(20);
    stack1.push(22);

    stack1.print();

    std::cout << "Avarage value: " << stack1.avarage() << std::endl;

    stack1.pop();
    stack1.print();

    std::cout << "Avarage value: " << stack1.avarage() << std::endl;
    std::cout << "Top of stack: " << stack1.peek() << std::endl;


    return 0;
}