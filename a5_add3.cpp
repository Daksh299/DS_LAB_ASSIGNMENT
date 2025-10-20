struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void removeLoop(ListNode *head) {
    if (!head || !head->next) return;

    ListNode *slow = head, *fast = head;

    // Step 1: Detect loop using Floyd’s cycle detection
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;  // loop detected
    }

    // No loop found
    if (slow != fast) return;

    // Step 2: Find the start of the loop
    slow = head;
    if (slow == fast) {
        // Special case: loop starts at head
        while (fast->next != slow) {
            fast = fast->next;
        }
    } else {
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    // Step 3: Break the loop
    fast->next = nullptr;
}