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

Node* buildTreeHelper(vector<int>& inorder, int inStart, int inEnd,
                      vector<int>& postorder, int postStart, int postEnd,
                      unordered_map<int, int>& inorderIndex) {
    if (inStart > inEnd || postStart > postEnd)
        return nullptr;

    int rootVal = postorder[postEnd];
    Node* root = new Node(rootVal);

    int inRoot = inorderIndex[rootVal];
    int numsLeft = inRoot - inStart;

    root->left = buildTreeHelper(inorder, inStart, inRoot - 1,
                                 postorder, postStart, postStart + numsLeft - 1, inorderIndex);
    root->right = buildTreeHelper(inorder, inRoot + 1, inEnd,
                                  postorder, postStart + numsLeft, postEnd - 1, inorderIndex);

    return root;
}

Node* buildTreeFromInPost(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int, int> inorderIndex;
    for (int i = 0; i < inorder.size(); i++)
        inorderIndex[inorder[i]] = i;

    return buildTreeHelper(inorder, 0, inorder.size() - 1,
                           postorder, 0, postorder.size() - 1, inorderIndex);
}

void printInorder(Node* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    Node* root = buildTreeFromInPost(inorder, postorder);

    cout << "Inorder traversal of constructed tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}