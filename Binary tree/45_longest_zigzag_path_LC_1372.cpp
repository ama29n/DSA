#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *right;
    TreeNode *left;
};

// https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/ 

class Solution {
public:
    int ans = 0;
    void dfs(TreeNode *root, int l, int r) {
        if(!root) {
            return;
        }
        dfs(root->left, r + 1, 0);
        dfs(root->right, 0, l + 1);
        ans = max({ ans, l , r });
    }
    int longestZigZag(TreeNode* root) {
        dfs(root, 0, 0);
        return ans;
    }
};