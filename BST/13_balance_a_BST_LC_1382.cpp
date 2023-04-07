#include <bits/stdc++.h>
using namespace std;

class TreeNode {
    int val;
    TreeNode *left, *right;
};

// https://leetcode.com/problems/balance-a-binary-search-tree/

class Solution { 
public:
    TreeNode *makeTree(vector<int> &v, int l, int r) {
        if(l > r) {
            return NULL;
        }
        int m = l + (r - l) / 2;
        TreeNode* root = new TreeNode(v[m]);
        root->left = makeTree(v, l, m - 1);
        root->right = makeTree(v, m + 1, r);
        return root;
    }
    void in_order(TreeNode *root, vector<int> &v) {
        if(!root) {
            return;
        }
        in_order(root->left, v);
        v.push_back(root->val);
        in_order(root->right, v);
    }
    TreeNode *balanceBST(TreeNode *root) {
        vector<int> v;
        in_order(root, v);
        TreeNode *newRoot = makeTree(v, 0, v.size() - 1);
        return newRoot;
    }
};