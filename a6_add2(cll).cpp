#include<iostream>
using namespace std;

struct CNode {
    int data;
    CNode* next;
    CNode(int val) : data(val), next(nullptr) {}
};

// Insert node at end of CLL
void insertCircular(CNode*& head, int val) {
    CNode* newNode = new CNode(val);
    if (!head) {
        head = newNode;
        head->next = head;
        return;
    }
    CNode* temp = head;
    while (temp->next != head) temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
}

// Function to remove even nodes from CLL
void removeEvenCircular(CNode*& head) {
    if (!head) return;

    CNode* curr = head;
    CNode* prev = nullptr;

    // Handle case where all nodes might be even
    int countChecked = 0;
    int total = 0;
    CNode* t = head;
    do {
        total++;
        t = t->next;
    } while (t != head);

    while (countChecked < total && head) {
        countChecked++;
        if (curr->data % 2 == 0) {
            // If this is the only node in the list
            if (curr->next == curr) {
                delete curr;
                head = nullptr;
                return;
            }

            // If we are deleting head
            if (curr == head) {
                // find tail to fix circular link
                CNode* tail = head;
                while (tail->next != head) tail = tail->next;
                head = head->next;
                tail->next = head;
                CNode* toDelete = curr;
                curr = head;
                delete toDelete;
                prev = tail;
            } else {
                prev->next = curr->next;
                CNode* toDelete = curr;
                curr = curr->next;
                delete toDelete;
            }
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
}

// Display CLL
void displayCircular(CNode* head) {
    if (!head) {
        cout << "List empty" << endl;
        return;
    }
    CNode* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    
    CNode* cHead = nullptr;
    insertCircular(cHead, 12);
    insertCircular(cHead, 7);
    insertCircular(cHead, 18);
    insertCircular(cHead, 5);
    insertCircular(cHead, 20);

    cout << "Original Circular Linked List: ";
    displayCircular(cHead);

    removeEvenCircular(cHead);

    cout << "After removing even nodes (CLL): ";
    displayCircular(cHead);

    return 0;
}