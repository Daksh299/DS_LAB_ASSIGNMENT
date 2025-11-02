#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
    Node(int k) : key(k), left(NULL), right(NULL) {}
};

Node* findMin(Node* root) {
    return root->left ? findMin(root->left) : root;
}


Node* deleteNode(Node* root, int key) {
    if (!root) return NULL;
    if (key < root->key) root->left = deleteNode(root->left, key);
    else if (key > root->key) root->right = deleteNode(root->right, key);
    else {
        if (!root->left) return root->right;
        if (!root->right) return root->left;
        Node* temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    int a[] = {50, 30, 70, 20, 40, 60, 80};
    for (int x : a) {
        if (!root) root = new Node(x);
        else {
            Node* cur = root; Node* prev = NULL;
            while (cur) {
                prev = cur;
                if (x < cur->key) cur = cur->left;
                else if (x > cur->key) cur = cur->right;
                else break;
            }
            if (x < prev->key) prev->left = new Node(x);
            else if (x > prev->key) prev->right = new Node(x);
        }
    }
    cout << "Before deletion: "; inorder(root); cout << endl;
    root = deleteNode(root, 70);
    cout << "After deletion: "; inorder(root);
}