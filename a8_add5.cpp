#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

Node* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd,
                      vector<int>& inorder, int inStart, int inEnd,
                      unordered_map<int, int>& inorderIndex) {
    if (preStart > preEnd || inStart > inEnd)
        return nullptr;

    int rootVal = preorder[preStart];
    Node* root = new Node(rootVal);

    int inRoot = inorderIndex[rootVal];
    int numsLeft = inRoot - inStart;

    root->left = buildTreeHelper(preorder, preStart + 1, preStart + numsLeft,
                                 inorder, inStart, inRoot - 1, inorderIndex);
    root->right = buildTreeHelper(preorder, preStart + numsLeft + 1, preEnd,
                                  inorder, inRoot + 1, inEnd, inorderIndex);

    return root;
}

Node* buildTreeFromPreIn(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> inorderIndex;
    for (int i = 0; i < inorder.size(); i++)
        inorderIndex[inorder[i]] = i;

    return buildTreeHelper(preorder, 0, preorder.size() - 1,
                           inorder, 0, inorder.size() - 1, inorderIndex);
}

void printInorder(Node* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Node* root = buildTreeFromPreIn(preorder, inorder);

    cout << "Inorder traversal of constructed tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}