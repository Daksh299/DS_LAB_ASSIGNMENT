#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* rotateLeft(ListNode* head, int k) {
    if (!head || k == 0) return head;

    // First, find the length of the list
    int length = 1;
    ListNode* tail = head;
    while (tail->next) {
        tail = tail->next;
        length++;
    }

    // Normalize k if it's greater than length
    k = k % length;
    if (k == 0) return head; // no rotation needed

    // Find the new tail: (k-th node from the start)
    ListNode* newTail = head;
    for (int i = 1; i < k; i++) {
        newTail = newTail->next;
    }

    // The node after newTail will be the new head
    ListNode* newHead = newTail->next;

    // Rotate the list
    newTail->next = nullptr;  // break the list
    tail->next = head;        // connect old tail to old head

    return newHead;
}

// Utility function to print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";
}

// Example usage
int main() {
    // Create linked list: 1->2->3->4->5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;
    cout << "Original list: ";
    printList(head);

    head = rotateLeft(head, k);

    cout << "List after rotating left by " << k << " positions: ";
    printList(head);

    return 0;
}