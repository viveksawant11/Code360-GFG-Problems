#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

vector<int> bottomView(TreeNode<int>* root) {
    vector<int> ans;

    if (root == NULL)
        return ans;

    map<int, int> mp;
    queue<pair<TreeNode<int>*, int>> q;

    q.push({root, 0});

    while (!q.empty()) {
        TreeNode<int>* node = q.front().first;
        int line = q.front().second;

        q.pop();

        // Store the most recent node at the horizontal distance 'line'
        mp[line] = node->data;

        if (node->left)
            q.push({node->left, line - 1});
        if (node->right)
            q.push({node->right, line + 1});
    }

    for (auto it : mp)
        ans.push_back(it.second);

    return ans;
}

int main() {
    // Creating a sample tree:
    //         1
    //        /  \
    //       2    3
    //      / \   / \
    //     4   5  6  7
    
    TreeNode<int>* root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(3);
    root->left->left = new TreeNode<int>(4);
    root->left->right = new TreeNode<int>(5);
    root->right->right = new TreeNode<int>(6);
    root->right->right->left = new TreeNode<int>(7);

    vector<int> result = bottomView(root);

    cout << "Bottom View: ";
    for (int val : result) {
        cout << val << " ";
    }

    return 0;
}
