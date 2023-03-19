
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *right;
    TreeNode *left;
};

// https://leetcode.com/problems/cousins-in-binary-tree/ 

class Solution {
public:
    int depth(TreeNode *root, int t) {
        if(!root) {
            return 0;
        }
        if(root->val == t) {
            return 1;
        }
        int l = depth(root->left, t);
        int r = depth(root->right, t);
        if(l > 0) {
            return l + 1;
        }
        if(r > 0) {
            return r + 1;
        }
        return 0;
    }
    bool dfs(TreeNode *root, int x, int y) {
        if(!root) {
            return true;
        }
        if(root->left && root->right) {
            if(root->right->val == x && root->left->val == y) {
                return false;
            }
            if(root->right->val == y && root->left->val == x) {
                return false;
            }
        }
        bool l = dfs(root->left, x, y);
        bool r = dfs(root->right, x, y);
        if(!l || !r) {
            return false;
        }
        return true;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root) {
            return true;
        }
        if(depth(root, x) != depth(root, y)) {
            return false;
        }
        return dfs(root, x, y);
    }
};