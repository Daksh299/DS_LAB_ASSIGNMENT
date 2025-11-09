#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> rightView(Node* root) {
    vector<int> result;
    if (!root)
        return result;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            Node* curr = q.front();
            q.pop();

            if (i == levelSize - 1)
                result.push_back(curr->val);

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }

    return result;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    root->right->right = new Node(4);

    vector<int> view = rightView(root);

    cout << "Right view of the binary tree: ";
    for (int val : view)
        cout << val << " ";
    cout << endl;

    return 0;
}