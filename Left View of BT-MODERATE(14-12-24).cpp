#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> leftSideView(TreeNode* root) {
        vector<int> ans;
        leftViewRecursive(root, 0, res);
        return res;
    }

private:
    void leftViewRecursive(TreeNode* node, int level, vector<int>& res) {
        if (root == NULL)
            return;
    
        if (res.size() == level)
            res.push_back(node->val);
    
        if (node->left)
            leftViewRecursive(node->left, level + 1, res);
        if (node->right)
            leftViewRecursive(node->right, level + 1, res);
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(10);
    root->left->left->right = new TreeNode(5);
    root->left->left->right->right = new TreeNode(6);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(10);
    root->right->left = new TreeNode(9);

    Solution solution;

    vector<int> rightView = solution.rightSideView(root);

    cout << "Right View Traversal: ";
    for (auto node : rightView) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
