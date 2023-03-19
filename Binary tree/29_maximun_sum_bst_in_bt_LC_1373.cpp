#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *right;
    TreeNode *left;
};

// https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/

class Solution {
public:
    class Helper {
        public: 
        int maxi, mini, sum, isBST;
        Helper() {
            maxi = -40000; mini = 40000; sum = 0; isBST = 1;
        }
    };
    Helper hh;
    int maxSum = 0;
    Helper dfs(TreeNode *root) {
        if(!root) {
            return hh;
        }
        Helper l = dfs(root->left);
        Helper r = dfs(root->right);
        Helper h;
        if(!l.isBST || !r.isBST || root->val <= l.maxi || root->val >= r.mini) {
            h.isBST = 0;
            return h;
        }
        h.sum = l.sum + r.sum + root->val;
        maxSum = max(maxSum, h.sum);
        h.mini = min(l.mini, root->val);
        h.maxi = max(r.maxi, root->val);
        return h;
    }
    int maxSumBST(TreeNode* root) {
        Helper h = dfs(root);
        return maxSum;
    }
};

// [8,9,8,null,9,null,1,null,null,-3,5,null,-2,null,6]

// [4,2,-3,-2,9,9,null,-5,2,7,1,null,null,null,-3,0,3,null,6,null,null,null,null,null,null,null,null,null,8] 