#include <iostream>
using namespace std;

// Definition of a node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to reverse the linked list
Node* reverseLinkedList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* nextNode = nullptr;

    while (current != nullptr) {
        nextNode = current->next;   // store next node
        current->next = prev;       // reverse the link
        prev = current;             // move prev forward
        current = nextNode;         // move current forward
    }
    return prev; // new head
}

// Function to print the linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Create linked list: 1->2->3->4->NULL
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    cout << "Original Linked List:" << endl;
    printLinkedList(head);

    // Reverse the linked list
    head = reverseLinkedList(head);

    cout << "Reversed Linked List:" << endl;
    printLinkedList(head);

    return 0;
}