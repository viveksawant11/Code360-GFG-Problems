#include<bits/stdc++.h>
using namespace std;

template<typename T>
struct TreeNode {
    T data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(T val) : data(val), left(NULL), right(NULL) {}
};

vector<int> getTopView(TreeNode<int> *root) {
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

        if (mp.find(line) == mp.end()) 
            mp[line] = node->data;
        
        if (node->left)
            q.push({node->left, line - 1});
        if (node->right)
            q.push({node->right, line + 1});
    }

    for (auto it : mp) { 
        ans.push_back(it.second);
    }

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
    root->right->left = new TreeNode<int>(6);
    root->right->right = new TreeNode<int>(7);

    vector<int> topView = getTopView(root);

    for (int val : topView) {
        cout << val << " ";
    }

    return 0;
}
