#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;   
    Node* right;  
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

void bstToDLL(Node* root, Node*& head, Node*& prev) {
    if (!root) return;

    bstToDLL(root->left, head, prev);

    if (prev == nullptr)
        head = root;
    else {
        prev->right = root;
        root->left = prev;
    }
    prev = root;

    bstToDLL(root->right, head, prev);
}

Node* mergeDLLs(Node* first, Node* second) {
    if (!first) return second;
    if (!second) return first;

    Node* head = nullptr;
    Node* tail = nullptr;

    while (first && second) {
        Node* temp = nullptr;
        if (first->val < second->val) {
            temp = first;
            first = first->right;
        } else {
            temp = second;
            second = second->right;
        }

        if (!head)
            head = temp;
        else {
            tail->right = temp;
            temp->left = tail;
        }
        tail = temp;
    }

    if (first) tail->right = first;
    if (second) tail->right = second;

    return head;
}

void printDLL(Node* head) {
    while (head) {
        cout << head->val << " ";
        head = head->right;
    }
}

int main() {
    Node* root1 = new Node(3);
    root1->left = new Node(1);
    root1->right = new Node(5);

    Node* root2 = new Node(8);
    root2->left = new Node(6);
    root2->right = new Node(10);

    Node* head1 = nullptr; Node* prev1 = nullptr;
    bstToDLL(root1, head1, prev1);
    Node* head2 = nullptr; Node* prev2 = nullptr;
    bstToDLL(root2, head2, prev2);

    Node* merged = mergeDLLs(head1, head2);

    cout << "Merged sorted doubly linked list: ";
    printDLL(merged);
    cout << endl;

    return 0;
}