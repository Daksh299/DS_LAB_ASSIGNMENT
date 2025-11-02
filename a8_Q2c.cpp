Node* findMin(Node* root) {
    if (!root->left) return root;
    return findMin(root->left);
}

int main() {
    Node* root = NULL;
    int a[] = {50, 30, 70, 20, 40, 60, 80};
    for (int x : a) root = insert(root, x);

    cout << "Min: " << findMin(root)->key << endl;
}