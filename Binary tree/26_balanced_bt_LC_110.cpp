#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *right;
    TreeNode *left;
};

// https://leetcode.com/problems/balanced-binary-tree/ 

// O(n ^ 2)
class Solution {
public:
    int dfs(TreeNode *root) {
        if(!root) {
            return 0;
        }
        int l = dfs(root->left);
        int r = dfs(root->right);
        return max(l, r) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) {
            return true;
        }
        bool l = isBalanced(root->left);
        bool r = isBalanced(root->right);
        if(!l || !r) {
            return false;
        }
        int x = dfs(root->left);
        int y = dfs(root->right);
        if(abs(x - y) > 1) {
            return false;
        }
        return true;
    }
};


// O(n)
class Solution {
public:
    class Helper {
    public:
        int depth;
        bool bal;
        Helper() {
            depth = 0;
            bal = true;
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
        if(!l.bal || !r.bal) {
            h.bal = false;
            return h;
        }
        if(abs(l.depth - r.depth) > 1) {
            h.bal = false;
            return h;
        }
        h.depth = max(l.depth, r.depth) + 1;
        return h;
    }
    bool isBalanced(TreeNode* root) {
        Helper h = dfs(root);
        return h.bal;
    }
};