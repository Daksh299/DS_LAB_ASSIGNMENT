#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};


ListNode* reverseKNodes(ListNode* head, int k) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* next = nullptr;
    int count = 0;

    
    while (curr != nullptr && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    
    return prev;
}


ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head || k == 1) return head;

   
    int count = 0;
    while (node != nullptr && count < k) {
        node = node->next;
        count++;
    }

    if (count < k) {
       
        return head;
    }

   
    ListNode* newHead = reverseKNodes(head, k);

    
    head->next = reverseKGroup(node, k);

    return newHead;
}


void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";
}


int main() {
   
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
