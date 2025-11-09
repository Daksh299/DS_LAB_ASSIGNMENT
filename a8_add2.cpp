#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<TreeNode*> generateTreesHelper(int start, int end) {
    vector<TreeNode*> result;
    if (start > end) {
        result.push_back(nullptr); 
        return result;
    }

   
    for (int i = start; i <= end; ++i) {
        vector<TreeNode*> leftTrees = generateTreesHelper(start, i - 1);
        vector<TreeNode*> rightTrees = generateTreesHelper(i + 1, end);

        
        for (TreeNode* left : leftTrees) {
            for (TreeNode* right : rightTrees) {
                TreeNode* root = new TreeNode(i);
                root->left = left;
                root->right = right;
                result.push_back(root);
            }
        }
    }
    return result;
}

vector<TreeNode*> generateTrees(int n) {
    if (n == 0) return {};
    return generateTreesHelper(1, n);
}


void preorder(TreeNode* root) {
    if (!root) {
        cout << "null ";
        return;
    }
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n = 3;
    vector<TreeNode*> trees = generateTrees(n);

    cout << "Number of unique BSTs for n = " << n << " is: " << trees.size() << "\n\n";

    int idx = 1;
    for (TreeNode* root : trees) {
        cout << "Tree " << idx++ << ": ";
        preorder(root);
        cout << endl;
    }

    return 0;
}