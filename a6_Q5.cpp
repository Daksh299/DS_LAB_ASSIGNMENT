#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

bool isCircular(Node* head) {
    if (!head) return false;   // Empty list is not circular
    Node* temp = head->next;

    while (temp && temp != head) {
        temp = temp->next;
    }

    return (temp == head);
}

// Helper function to create a non-circular list
Node* createLinearList() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = nullptr;
    return head;
}

// Helper function to create a circular list
Node* createCircularList() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    head->next = second;
    second->next = third;
    third->next = head; // Make circular
    return head;
}

int main() {
    Node* linear = createLinearList();
    Node* circular = createCircularList();

    cout << "Linear list is " << (isCircular(linear) ? "Circular" : "Not Circular") << endl;
    cout << "Circular list is " << (isCircular(circular) ? "Circular" : "Not Circular") << endl;

    return 0;
}