Node* findMax(Node* root) {
    if (!root->right) return root;
    return findMax(root->right);
}

int main() {
    Node* root = NULL;
    int a[] = {50, 30, 70, 20, 40, 60, 80};
    for (int x : a) root = insert(root, x);

    cout << "Max: " << findMax(root)->key << endl;
}