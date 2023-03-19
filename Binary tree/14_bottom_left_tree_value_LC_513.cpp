#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *right;
    TreeNode *left;
};

// https://leetcode.com/problems/find-bottom-left-tree-value/description/

class Solution {
public:
    int maxDepth = -1;
    int val;
    void dfs(TreeNode *root, int level) {
        if(!root) {
            return;
        }
        if(level > maxDepth) {
            maxDepth = level;
            val = root->val;
        }
        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    }
    int findBottomLeftValue(TreeNode* root) {
        dfs(root, 0);
        return val;
    }
};