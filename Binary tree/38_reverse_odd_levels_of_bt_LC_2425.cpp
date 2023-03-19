#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

// https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/

class Solution {
public:
    void dfs(TreeNode *l, TreeNode *r, int level) {
        if(!l || !r) {
            return;
        }
        if(level % 2 == 1) {
            swap(l->val, r->val);
        }
        dfs(l->left, r->right, level + 1);
        dfs(l->right, r->left, level + 1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root->left, root->right, 1);
        return root;
    }
};