#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *right;
    TreeNode *left;
};

// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/ 

// O(n ^ 2)
class Solution {
public:
    int findMax(TreeNode *root) {
        if(!root) return 0;
        return max({root->val, findMax(root->left), findMax(root->right)});
    }
    int findMin(TreeNode *root) {
        if(!root) return 1E5;
        return min({root->val, findMin(root->left), findMin(root->right)});
    }
    int dfs(TreeNode *root) {
        if(!root) return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        int mini = min(findMin(root->left), findMin(root->right));
        int maxi = max(findMax(root->left), findMax(root->right));
        if(!root->left && !root->right) {
            return 0;
        }
        return max({l, r, abs(root->val - maxi), abs(root->val - mini)});
    }
    int maxAncestorDiff(TreeNode *root) {
        return dfs(root);
    }
};

// O(n)
class Solution {
public:
    class Helper {
        public:
        int dif, maxi, mini;
        Helper() {
            dif = 0; maxi = 0; mini = 1E5;
        }
    } hh;
    Helper dfs(TreeNode *root) {
        if(!root) return hh;
        Helper l = dfs(root->left), r = dfs(root->right), h;
        h.mini = min(l.mini, r.mini);
        h.maxi = max(l.maxi, r.maxi);
        h.dif = max({abs(root->val - h.mini), abs(root->val - h.maxi), r.dif, l.dif});
        if(!root->left && !root->right) {
            h.dif = 0;
        }
        h.mini = min(h.mini, root->val);
        h.maxi = max(h.maxi, root->val);
        return h;
    }
    int maxAncestorDiff(TreeNode* root) {
        Helper h = dfs(root);
        return h.dif;
    }
};