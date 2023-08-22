#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *right;
    TreeNode *left;
};

// https://leetcode.com/problems/binary-tree-pruning/

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(!root) {
            return root;
        }
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if(root->val == 0 && !root->right && !root->left) {
            return NULL;
        }
        return root;
    }
};