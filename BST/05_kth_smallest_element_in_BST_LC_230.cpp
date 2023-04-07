#include <bits/stdc++.h>
using namespace std;

class TreeNode {
    int val;
    TreeNode *left, *right;
};

// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

// Apprach 1
class Solution {
public:
    vector<int> v;
    void in_order(TreeNode *root) {
        if(!root) {
            return;
        }
        in_order(root->left);
        v.push_back(root->val);
        in_order(root->right);
    }
    int kthSmallest(TreeNode *root, int k) {
        in_order(root);
        return v[k - 1];
    }
};

// Apprach 2 
class Solution {
public:
    int dfs(TreeNode *root, int &k) {
        if(root) {
            int x = dfs(root->left, k);
            return k == 0 ? x : !--k ? root->val : dfs(root->right, k);
        }
        return -1;
    }
    int kthSmallest(TreeNode *root, int k) {
        return dfs(root, k);
    }
};