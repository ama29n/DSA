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
    vector<TreeNode *> findParents(TreeNode *root, TreeNode *node) {
        if(!root) return {};
        if(root == node) {
            return { node };
        }
        vector<TreeNode *> l = findParents(root->left, node);
        vector<TreeNode *> r = findParents(root->right, node);
        if(l.size() > 0) {
            l.push_back(root); return l;
        }
        if(r.size() > 0) {
            r.push_back(root); return r;
        }
        return {};
    }
    TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        vector<TreeNode *> u = findParents(root, p);
        vector<TreeNode *> v = findParents(root, q);
        int n = u.size() - 1, m = v.size() - 1;
        while(n >= 0 && m >= 0 && u[n] == v[m]) {
            n--; m--;
        }
        return u[++n];
    }
};