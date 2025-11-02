Node* findMax(Node* root) {
    if (!root->right) return root;
    return findMax(root->right);
}

Node* inorderPredecessor(Node* root, Node* node) {
    if (node->left) return findMax(node->left);
    Node* pred = NULL;
    if (!root) return NULL;
    if (node->key > root->key) {
        pred = root;
        return inorderPredecessor(root->right, node) ?: pred;
    } else if (node->key < root->key)
        return inorderPredecessor(root->left, node);
    return pred;
}

int main() {
    Node* root = NULL;
    int a[] = {50, 30, 70, 20, 40, 60, 80};
    for (int x : a) root = insert(root, x);

    Node* node = search(root, 50);
    Node* pred = inorderPredecessor(root, node);
    cout << "Predecessor of " << node->key << " is "
         << (pred ? to_string(pred->key) : "None") << endl;
}