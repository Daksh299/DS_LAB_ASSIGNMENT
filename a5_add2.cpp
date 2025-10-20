#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Helper function to reverse k nodes of the linked list
ListNode* reverseKNodes(ListNode* head, int k) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* next = nullptr;
    int count = 0;

    // Reverse k nodes or until the end of the list
    while (curr != nullptr && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // prev is the new head of the reversed group
    return prev;
}

// Main function to reverse nodes in k groups
ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head || k == 1) return head;

    // Check if there are at least k nodes left in the list
    ListNode* node = head;
    int count = 0;
    while (node != nullptr && count < k) {
        node = node->next;
        count++;
    }

    if (count < k) {
        // Less than k nodes remaining, return head as is
        return head;
    }

    // Reverse first k nodes
    ListNode* newHead = reverseKNodes(head, k);

    // Now head is the last node of the reversed group
    // Recurse for the rest of the list and connect
    head->next = reverseKGroup(node, k);

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
    // Create linked list 1->2->3->4->5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;
    cout << "Original list: ";
    printList(head);

    head = reverseKGroup(head, k);

    cout << "Reversed in groups of " << k << ": ";
    printList(head);

    return 0;
}