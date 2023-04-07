#include <bits/stdc++.h>
using namespace std;

class TreeNode {
    int val;
    TreeNode *left, *right;
};

// https://leetcode.com/problems/recover-binary-search-tree/

class Solution {
public:
    vector<int> v;
    int i;
    void in_order(TreeNode *root) {
        if(!root) {
            return;
        }
        in_order(root->left);
        v.push_back(root->val);
        in_order(root->right);
    }
    void assign(TreeNode *root) {
        if(!root) {
            return;
        }
        assign(root->left);
        root->val = v[i++];
        assign(root->right);
    }
    void recoverTree(TreeNode* root) {
        in_order(root);
        i = 0;
        sort(v.begin(), v.end());
        assign(root);
    }
};