#include <bits/stdc++.h>
using namespace std;

class TreeNode {
    int val;
    TreeNode *left, *right;
};

// https://leetcode.com/problems/range-sum-of-bst/

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) {
            return 0;
        }
        int ls = rangeSumBST(root->left, low, high);
        int rs = rangeSumBST(root->right, low, high);
        if(root->val >= low && root->val <= high) {
            return root->val + ls + rs; 
        }
        return ls + rs;
    }
};