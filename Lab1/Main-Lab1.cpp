#include <iostream>
#include <string>

// оголошення структури node
struct node;
typedef node* ref;

struct node {
    ref next;
    char el;
};

// оголошення прототипів функцій
void addElement(ref& head, char value);
void printList(ref head);
int count1(ref head);

int main()
{
    // початкове значення голови списку
    ref head = nullptr;

    std::string text;
    std::cout << "Input some text with numbers: ";
    getline(std::cin, text);

    for (char el : text)
    {
        addElement(head, el);
    }

    // виведення списку
    std::cout << "List: ";
    printList(head);

    int counter1 = count1(head);
    std::cout << "Number of '1': " << counter1 << ". The number is ";
    if (counter1 % 2 == 0) std::cout << "even"; // перевірка на парність кількості
    else std::cout << "odd"; // у випадку непарності кількості

    return 0;
}

// додавання елемента в кінець списку
void addElement(ref& head, char value) {
    ref newNode = new node;
    newNode->el = value;
    newNode->next = nullptr; // новий елемент стає останнім, тому next вказує на nullptr

    if (head == nullptr) {
        head = newNode; // якщо список пустий, новий елемент стає головою
    }
    else {
        ref current = head;
        while (current->next != nullptr) {
            current = current->next; // проходимо по списку до останнього елементу
        }
        current->next = newNode; // додаємо новий елемент після останнього
    }
}

// виведення списку
void printList(ref head) {
    while (head != nullptr) {
        std::cout << head->el << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// функція для підрахунку кількості "1"
int count1(ref head) {
    int counter1 = 0; // створення змінної лічильника для підрахунку кількості "1"
    while (head != nullptr) {
        if (head->el == '1') ++counter1;
        head = head->next;
    }
    return counter1;
}