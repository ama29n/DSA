#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *right;
    TreeNode *left;
};

// https://leetcode.com/problems/path-sum-iii/

class Solution {
public:
    int ans = 0;
    int t;
    int mod = 1E9 + 7;
    void count(TreeNode *root, int sum) {
        if(!root) {
            return;
        }
        sum = (sum + root->val) % mod;
        if(sum == t) {
            ans++;
        }
        count(root->left, sum);
        count(root->right, sum);
    }
    void dfs(TreeNode *root) {
        if(!root) {
            return;
        }
        count(root, 0);
        dfs(root->left);
        dfs(root->right);
    }
    int pathSum(TreeNode* root, int targetSum) {
        t = targetSum;
        dfs(root);
        return ans;
    }
};
