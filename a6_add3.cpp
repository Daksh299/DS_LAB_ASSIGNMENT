#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Function to reverse every group of k nodes
Node* reverseInGroups(Node* head, int k) {
    if (!head || k <= 1) return head;

    Node* current = head;
    Node* newHead = nullptr;
    Node* prevTail = nullptr;

    while (current != nullptr) {
        Node* groupHead = current;
        Node* prev = nullptr;
        int count = 0;

        // Reverse k nodes
        while (current != nullptr && count < k) {
            Node* nextNode = current->next;
            current->next = prev;
            current->prev = nextNode;
            prev = current;
            current = nextNode;
            count++;
        }

        // Connect with previous part
        if (prevTail != nullptr) {
            prevTail->next = prev;
        }
        prev->prev = prevTail;

        // New head after first group
        if (newHead == nullptr) {
            newHead = prev;
        }

        // Tail of this group becomes prevTail for next group
        prevTail = groupHead;
    }

    // Last node next must be null
    if (prevTail != nullptr)
        prevTail->next = nullptr;

    return newHead;
}

// Helper function to insert node at end
void insert(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Helper function to print list
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    for (int i = 1; i <= 8; i++)
        insert(head, i);

    int k = 3;
    cout << "Original List: ";
    printList(head);

    head = reverseInGroups(head, k);

    cout << "Reversed in groups of " << k << ": ";
    printList(head);

    return 0;
}