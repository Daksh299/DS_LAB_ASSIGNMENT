struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void removeLoop(ListNode *head) {
    if (!head || !head->next) return;

    ListNode *slow = head, *fast = head;

   
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break; 
    }

    
    if (slow != fast) return;

   
    slow = head;
    if (slow == fast) {
       
        while (fast->next != slow) {
            fast = fast->next;
        }
    } else {
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
    }

   
    fast->next = nullptr;
}
