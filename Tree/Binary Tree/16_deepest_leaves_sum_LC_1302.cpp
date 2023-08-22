#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *right;
    TreeNode *left;
};

// https://leetcode.com/problems/deepest-leaves-sum/

class Solution {
public:
    int maxLevel = 0;
    int sum = 0;
    void dfs(TreeNode *root, int level) {
        if(!root) {
            return;
        }
        if(!root->left && !root->right) {
            if(level == maxLevel) {
                sum += root->val;
            }
            if(level > maxLevel) {
                maxLevel = level;
                sum = root->val;
            }
        }
        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    }
    int deepestLeavesSum(TreeNode* root) {
        dfs(root, 0);
        return sum;
    }
};