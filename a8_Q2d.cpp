Node* findMin(Node* root) {
    if (!root->left) return root;
    return findMin(root->left);
}

Node* inorderSuccessor(Node* root, Node* node) {
    if (node->right) return findMin(node->right);
    Node* succ = NULL;
    if (!root) return NULL;
    if (node->key < root->key) {
        succ = root;
        return inorderSuccessor(root->left, node) ?: succ;
    } else if (node->key > root->key)
        return inorderSuccessor(root->right, node);
    return succ;
}

int main() {
    Node* root = NULL;
    int a[] = {50, 30, 70, 20, 40, 60, 80};
    for (int x : a) root = insert(root, x);

    Node* node = search(root, 50);
    Node* succ = inorderSuccessor(root, node);
    cout << "Successor of " << node->key << " is " 
         << (succ ? to_string(succ->key) : "None") << endl;
}