#include <iostream>
#include <string>

// ���������� ��������� node
struct node;
typedef node* ref;

struct node {
    ref next;
    char el;
};

// ���������� ��������� �������
void addElement(ref& head, char value);
void printList(ref head);
int count1(ref head);

int main()
{
    // ��������� �������� ������ ������
    ref head = nullptr;

    std::string text;
    std::cout << "Input some text with numbers: ";
    getline(std::cin, text);

    for (char el : text)
    {
        addElement(head, el);
    }

    // ��������� ������
    std::cout << "List: ";
    printList(head);

    int counter1 = count1(head);
    std::cout << "Number of '1': " << counter1 << ". The number is ";
    if (counter1 % 2 == 0) std::cout << "even"; // �������� �� ������� �������
    else std::cout << "odd"; // � ������� ��������� �������

    return 0;
}

// ��������� �������� � ����� ������
void addElement(ref& head, char value) {
    ref newNode = new node;
    newNode->el = value;
    newNode->next = nullptr; // ����� ������� ��� �������, ���� next ����� �� nullptr

    if (head == nullptr) {
        head = newNode; // ���� ������ ������, ����� ������� ��� �������
    }
    else {
        ref current = head;
        while (current->next != nullptr) {
            current = current->next; // ��������� �� ������ �� ���������� ��������
        }
        current->next = newNode; // ������ ����� ������� ���� ����������
    }
}

// ��������� ������
void printList(ref head) {
    while (head != nullptr) {
        std::cout << head->el << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// ������� ��� ��������� ������� "1"
int count1(ref head) {
    int counter1 = 0; // ��������� ����� ��������� ��� ��������� ������� "1"
    while (head != nullptr) {
        if (head->el == '1') ++counter1;
        head = head->next;
    }
    return counter1;
}