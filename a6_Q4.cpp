#include <iostream>
using namespace std;

struct Node {
    char data;
    Node *next, *prev;
    Node(char c) : data(c), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
    Node* head;
public:
    DoublyLinkedList() : head(nullptr) {}

    void insertEnd(char c) {
        Node* n = new Node(c);
        if (!head) { head = n; return; }
        Node* t = head;
        while (t->next) t = t->next;
        t->next = n;
        n->prev = t;
    }

    bool isPalindrome() {
        if (!head || !head->next) return true;
        Node* left = head;
        Node* right = head;
        // Move right to the tail
        while (right->next) right = right->next;

        // Compare characters
        while (left != right && left->prev != right) {
            if (left->data != right->data) return false;
            left = left->next;
            right = right->prev;
        }
        return true;
    }

    void display() {
        Node* t = head;
        while (t) { cout << t->data << " "; t = t->next; }
        cout << "\n";
    }
};

int main() {
    DoublyLinkedList dll;
    string str;
    cout << "Enter string: ";
    cin >> str;

    for (char c : str) dll.insertEnd(c);

    cout << "List: "; dll.display();
    if (dll.isPalindrome()) cout << "Palindrome ✅\n";
    else cout << "Not Palindrome ❌\n";
}