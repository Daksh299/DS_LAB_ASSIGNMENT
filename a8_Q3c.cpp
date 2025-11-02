#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
    Node(int k) : key(k), left(NULL), right(NULL) {}
};

// (c) Maximum Depth (height)
int maxDepth(Node* root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

// Insert for testing
Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->key) root->left = insert(root->left, key);
    else if (key > root->key) root->right = insert(root->right, key);
    return root;
}

int main() {
    Node* root = NULL;
    int a[] = {50, 30, 70, 20, 40, 60, 80};
    for (int x : a) root = insert(root, x);
    cout << "Maximum Depth: " << maxDepth(root);
}