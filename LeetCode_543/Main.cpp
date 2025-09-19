#include<bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int ans = 0;
    int dfs(TreeNode* root) {
        if (root->left == nullptr and root->right == nullptr) {
            return 0;
        }

        int mx = 0;
        if (root->left) {
            mx = max(dfs(root->left) + 1, mx);
        }
        if (root->right) {
            mx = max(dfs(root->right) + 1, mx);
        }
        return mx;
    }
    void traverse(TreeNode* root) {
        int cur = 0;
        if (root->left) {
            cur += dfs(root->left) + 1;
        }
        if (root->right) {
            cur += dfs(root->right) + 1;
        }
        ans = max(ans, cur);
        if (root->left) {
            traverse(root->left);
        }
        if (root->right) {
            traverse(root->right);
        }
    }

    int diameterOfBinaryTree(TreeNode* root) {
        traverse(root);
        return ans;
    }
};