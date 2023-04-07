#include <bits/stdc++.h>
using namespace std;

class TreeNode {
    int val;
    TreeNode *left, *right;
};

// https://leetcode.com/problems/balance-a-binary-search-tree/

class Solution { 
public:
    TreeNode* makeTree(vector<int> &v, int beg, int end) {
        if(beg > end) return NULL;
        int mid = beg + (end - beg) / 2;
        TreeNode* root = new TreeNode(v[mid]);
        root->left = makeTree(v, beg, mid - 1);
        root->right = makeTree(v, mid + 1, end);
        return root;
    }
    void inOrder(TreeNode* root, vector<int> &v) {
        if(!root) return;
        inOrder(root->left, v);
        v.push_back(root->val);
        inOrder(root->right, v);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        inOrder(root, v);
        TreeNode *newRoot = makeTree(v, 0, v.size() - 1);
        return newRoot;
    }
};