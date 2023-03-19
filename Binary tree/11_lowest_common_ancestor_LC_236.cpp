#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *right;
    TreeNode *left;
};

// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree

class Solution {
public:
    vector<TreeNode *> dfs(TreeNode *root, TreeNode *val) {
        if(!root) {
            return {};
        }
        if(root == val) {
            return {root};
        }
        vector<TreeNode *> l = dfs(root->left, val);
        vector<TreeNode *> r = dfs(root->right, val);
        if(l.size() > 0) {
            l.push_back(root);
            return l;
        }
        if(r.size() > 0) {
            r.push_back(root);
            return r;
        }
        return {};
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *> u, v;
        u = dfs(root, p);
        v = dfs(root, q);
        int i = u.size() - 1, j = v.size() - 1;
        while(i >= 0 && j >= 0 && u[i] == v[j]) {
            i--; j--;
        }
        i++;
        return u[i];
    }
};