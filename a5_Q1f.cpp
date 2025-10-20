#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insertAtEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    if (head == nullptr) head = newNode;
    else {
        Node* temp = head;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = newNode;
    }
}

void deleteSpecific(int target) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    if (head->data == target) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Deleted " << target << endl;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != target) {
        temp = temp->next;
    }
    if (temp->next == nullptr) {
        cout << "Node not found.\n";
        return;
    }
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
    cout << "Deleted " << target << endl;
}

void displayList() {
    Node* temp = head;
    cout << "Linked List: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    displayList();
    deleteSpecific(20);
    displayList();
    return 0;
}