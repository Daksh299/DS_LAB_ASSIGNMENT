#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

bool isBSTUtil(Node* node, Node* left = nullptr, Node* right = nullptr) {
    if (node == nullptr)
        return true;

    
    if (left && node->data <= left->data)
        return false;
    if (right && node->data >= right->data)
        return false;

    return isBSTUtil(node->left, left, node) && isBSTUtil(node->right, node, right);
}

bool isBST(Node* root) {
    return isBSTUtil(root);
}


int main() {
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right->right = new Node(14);

    cout << (isBST(root) ? "This tree is a BST." : "This tree is NOT a BST.") << endl;

    return 0;
}