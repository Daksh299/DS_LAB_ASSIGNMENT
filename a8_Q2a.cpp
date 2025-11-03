#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
    Node(int k) : key(k), left(NULL), right(NULL) {}
};

Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->key) root->left = insert(root->left, key);
    else if (key > root->key) root->right = insert(root->right, key);
    return root;
}


Node* search(Node* root, int key) {
    if (!root || root->key == key) return root;
    if (key < root->key) return search(root->left, key);
    return search(root->right, key);
}

int main() {
    Node* root = NULL;
    int a[] = {50, 30, 70, 20, 40, 60, 80};
    for (int x : a) root = insert(root, x);

    Node* res = search(root, 60);
    cout << (res ? "Found" : "Not Found") << endl;
}