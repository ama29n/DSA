#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *right;
    TreeNode *left;
};

// https://leetcode.com/problems/add-one-row-to-tree/ 

class Solution {
public:
    TreeNode* dfs(TreeNode *root, int val, int depth) {
        if(!root) {
            return root;
        }
        if(depth == 1) {
            TreeNode *l = new TreeNode(val), *r = new TreeNode(val);
            l->left = root->left; r->right = root->right;
            root->left = l; root->right = r;
            return root;
        }
        root->left = dfs(root->left, val, depth - 1);
        root->right = dfs(root->right, val, depth - 1);
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode *r = new TreeNode(val);
            r->left = root;
            return r;
        }
        return dfs(root, val, depth - 1);
    }
};