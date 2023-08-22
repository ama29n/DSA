#include <bits/stdc++.h>
using namespace std;

class TreeNode {
    int val;
    TreeNode *left, *right;
};

// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

class Solution {
public:
    int x = 0;
    void dfs(TreeNode *root) {
        if(!root) {
            return;
        }
        dfs(root->right);
        root->val += x;
        x = root->val;
        dfs(root->left);
    }
    TreeNode *bstToGst(TreeNode *root) {
        dfs(root);
        return root;
    }
};