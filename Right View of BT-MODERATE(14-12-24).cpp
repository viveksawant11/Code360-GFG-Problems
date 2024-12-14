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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        rightViewRecursive(root, 0, res);
        return res;
    }

private:
    void rightViewRecursive(TreeNode* node, int level, vector<int>& res) {
        if (!node) return;

        if (res.size() == level) {
            res.push_back(node->data);
        }

        rightViewRecursive(node->right, level + 1, res);
        rightViewRecursive(node->left, level + 1, res);
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
