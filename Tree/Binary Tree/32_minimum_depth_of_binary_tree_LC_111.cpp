#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *right;
    TreeNode *left;
};

// https://leetcode.com/problems/minimum-depth-of-binary-tree/description/ 

class Solution {
public:
    int dfs(TreeNode *root) {
        if(!root) return 1E5;
        if(!root->left && !root->right) {
            return 1;
        }
        int l = dfs(root->left), r = dfs(root->right);
        return min(l, r) + 1;
    }
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        return dfs(root);
    }
};

 