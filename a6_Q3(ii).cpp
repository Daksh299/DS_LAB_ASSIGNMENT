#include<iostream>
using namespace std;

struct CNode {
    int data;
    CNode* next;
    CNode(int val) : data(val), next(nullptr) {}
};

// Insert node at the end of Circular Linked List
void insertCircular(CNode*& head, int val) {
    CNode* newNode = new CNode(val);
    if (!head) {
        head = newNode;
        head->next = head;
        return;
    }
    CNode* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
}

// Function to find size of Circular Linked List
int sizeOfCircular(CNode* head) {
    if (!head) return 0;
    int count = 0;
    CNode* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

int main() {
    CNode* cHead = nullptr;
    insertCircular(cHead, 5);
    insertCircular(cHead, 15);
    insertCircular(cHead, 25);
    insertCircular(cHead, 35);
    cout << "Size of Circular Linked List: " << sizeOfCircular(cHead) << endl;

    return 0;
}
