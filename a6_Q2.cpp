#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to insert a node at the end of circular linked list
void insert(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        head->next = head; // point to itself (circular)
        return;
    }

    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
}

// Function to display circular linked list and repeat head value at end
void display(Node* head) {
    if (!head) return;

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    // repeat the head node value at the end
    cout << head->data << endl;
}

// Example usage
int main() {
    Node* head = nullptr;

    insert(head, 20);
    insert(head, 100);
    insert(head, 40);
    insert(head, 80);
    insert(head, 60);

    cout << "Circular Linked List values: ";
    display(head);

    return 0;
}