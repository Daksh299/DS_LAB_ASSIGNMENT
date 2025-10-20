#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to split circular list into two halves
void splitList(Node* head, Node** head1, Node** head2) {
    if (!head) return;

    Node *slow = head, *fast = head;

    // Use fast and slow pointer to find mid
    while (fast->next != head && fast->next->next != head) {
        fast = fast->next->next;
        slow = slow->next;
    }

    // For even number of nodes, fast->next == head
    // For odd number, fast->next->next == head
    if (fast->next->next == head)
        fast = fast->next;

    // Set the head pointer of first and second half
    *head1 = head;
    *head2 = slow->next;

    // Make the second half circular
    fast->next = *head2;

    // Make the first half circular
    slow->next = *head1;
}

// Helper function to create circular linked list
Node* createCircularList(int arr[], int n) {
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for (int i = 1; i < n; i++) {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    temp->next = head; // make it circular
    return head;
}

// Helper function to print circular linked list
void printList(Node* head) {
    if (!head) return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    Node* head = createCircularList(arr, n);
    cout << "Original Circular List: ";
    printList(head);

    Node *head1 = nullptr, *head2 = nullptr;
    splitList(head, &head1, &head2);

    cout << "First Half: ";
    printList(head1);

    cout << "Second Half: ";
    printList(head2);

    return 0;
}