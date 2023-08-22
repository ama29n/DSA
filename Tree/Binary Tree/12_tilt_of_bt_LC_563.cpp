#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *right;
    TreeNode *left;
};

// https://leetcode.com/problems/binary-tree-tilt 

// O(n ^ 2)
class Solution {
public:
    int dfs(TreeNode *root) {
        if(!root) {
            return 0;
        }
        int l = dfs(root->left);
        int r = dfs(root->right);
        return l + r + root->val;
    }
    int findTilt(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int l = findTilt(root->left);
        int r = findTilt(root->right);
        int h = abs(dfs(root->left) - dfs(root->right));
        return l + r + h;
    }
};

// O(n) 
class Solution {
public:
    int tiltSum = 0;
    int dfs(TreeNode *root) {
        if(!root) {
            return 0;
        }
        int l = dfs(root->left);
        int r = dfs(root->right);
        tiltSum += abs(r - l);
        return l + r + root->val;
    }
    int findTilt(TreeNode* root) {
        int sum = dfs(root);
        return tiltSum;
    }
};

