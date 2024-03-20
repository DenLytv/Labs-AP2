#include <iostream>
#include <Windows.h>

// Структура вузла бінарного дерева
struct Node {
    std::string data;
    Node* left;
    Node* right;

    // Конструктор
    Node(std::string val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Функція для створення дерева
Node* createTree();
// Функція для виведення дерева (прямий обхід)
void printTree(Node* root);

int main() {
    SetConsoleOutputCP(1251); // Встановлення кодової сторінки для коректного відображення кирилиці
    Node* root = createTree(); // Створення дерева
    std::cout << "До вставки:" << std::endl;
    printTree(root); // Виведення проміжної інформації

    // Вставка слова "бінарне" перед словом "дерево"
    root->left->right->left = new Node("бінарне");

    std::cout << std::endl << "Після вставки:" << std::endl;
    printTree(root); // Виведення кінцевої інформації

    std::cout << std::endl;
    return 0;
}

Node* createTree() {
    // Створення кореневого вузла зі значенням "Для"
    Node* root = new Node("Для");
    // Створення лівого дочірнього вузла зі значенням "синтаксичного"
    root->left = new Node("синтаксичного");
    // Створення лівого дочірнього вузла зі значенням "розбору"
    root->left->left = new Node("розбору");
    // Створення лівого дочірнього вузла зі значенням "речення"
    root->left->left->left = new Node("речення");
    // Створення правого дочірнього вузла зі значенням "використай"
    root->left->right = new Node("використай");
    // Створення правого дочірнього вузла зі значенням "дерево"
    root->left->right->right = new Node("дерево");

    return root; // Повертаємо корінь дерева
}

void printTree(Node* root) {
    if (root == nullptr) return; // Якщо вузол = nullptr, вихід з функції
    std::cout << root->data << " "; // Виведення значення поточного вузла
    printTree(root->left); // Рекурсивний виклик для лівого піддерева
    printTree(root->right); // Рекурсивний виклик для правого піддерева
}