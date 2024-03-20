#include <iostream>
#include <Windows.h>

// ��������� ����� �������� ������
struct Node {
    std::string data;
    Node* left;
    Node* right;

    // �����������
    Node(std::string val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// ������� ��� ��������� ������
Node* createTree();
// ������� ��� ��������� ������ (������ �����)
void printTree(Node* root);

int main() {
    SetConsoleOutputCP(1251); // ������������ ������ ������� ��� ���������� ����������� ��������
    Node* root = createTree(); // ��������� ������
    std::cout << "�� �������:" << std::endl;
    printTree(root); // ��������� ������� ����������

    // ������� ����� "������" ����� ������ "������"
    root->left->right->left = new Node("������");

    std::cout << std::endl << "ϳ��� �������:" << std::endl;
    printTree(root); // ��������� ������ ����������

    std::cout << std::endl;
    return 0;
}

Node* createTree() {
    // ��������� ���������� ����� � ��������� "���"
    Node* root = new Node("���");
    // ��������� ����� ���������� ����� � ��������� "�������������"
    root->left = new Node("�������������");
    // ��������� ����� ���������� ����� � ��������� "�������"
    root->left->left = new Node("�������");
    // ��������� ����� ���������� ����� � ��������� "�������"
    root->left->left->left = new Node("�������");
    // ��������� ������� ���������� ����� � ��������� "����������"
    root->left->right = new Node("����������");
    // ��������� ������� ���������� ����� � ��������� "������"
    root->left->right->right = new Node("������");

    return root; // ��������� ����� ������
}

void printTree(Node* root) {
    if (root == nullptr) return; // ���� ����� = nullptr, ����� � �������
    std::cout << root->data << " "; // ��������� �������� ��������� �����
    printTree(root->left); // ����������� ������ ��� ����� ��������
    printTree(root->right); // ����������� ������ ��� ������� ��������
}