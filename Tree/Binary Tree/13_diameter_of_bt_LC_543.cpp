#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *right;
    TreeNode *left;
};

// https://leetcode.com/problems/diameter-of-binary-tree/ 

class Solution {
public:
    int dfs(TreeNode *root) {
        if(!root) {
            return -1;
        }
        int l = dfs(root->left);
        int r = dfs(root->right);
        return max(l, r) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int l = diameterOfBinaryTree(root->left);
        int r = diameterOfBinaryTree(root->right);
        int h = dfs(root->left) + dfs(root->right) + 2;
        return max({l, r, h});
    }
};

class Solution {
public:
    class Helper {
    public:
        int max, depth;
        Helper() {
            max = 0;
            depth = -1;
        }
    };
    Helper hh;
    Helper dfs(TreeNode *root) {
        if(!root) {
            return hh;
        }
        Helper l = dfs(root->left);
        Helper r = dfs(root->right);
        Helper h;
        h.depth = max(l.depth, r.depth) + 1;
        h.max = max({l.max, r.max, 2 + l.depth + r.depth});
        return h;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        Helper h = dfs(root);
        return h.max;
    }
};

