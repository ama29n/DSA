#include <bits/stdc++.h>
using namespace std;

class TreeNode {
    int val;
    TreeNode *left, *right;
};

// https://leetcode.com/problems/minimum-absolute-difference-in-bst/

class Solution {
public:
    int minDif = INT_MAX;
    TreeNode *prev = NULL;
    void dfs(TreeNode *root) {
        if(!root) {
            return;
        }
        dfs(root->left);
        if(prev) {
            minDif = min(minDif, root->val - prev->val);
        }
        prev = root;
        dfs(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        return minDif;
    }
};