#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Insert node at the end of Doubly Linked List
void insertDoubly(DNode*& head, int val) {
    DNode* newNode = new DNode(val);
    if (!head) {
        head = newNode;
        return;
    }
    DNode* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to find size of Doubly Linked List
int sizeOfDoubly(DNode* head) {
    int count = 0;
    DNode* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    // Doubly Linked List
    DNode* dHead = nullptr;
    insertDoubly(dHead, 10);
    insertDoubly(dHead, 20);
    insertDoubly(dHead, 30);
    insertDoubly(dHead, 40);
    cout << "Size of Doubly Linked List: " << sizeOfDoubly(dHead) << endl;
    return 0;
}
