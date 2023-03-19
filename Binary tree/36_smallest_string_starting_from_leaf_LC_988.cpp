#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *right;
    TreeNode *left;
};

// https://leetcode.com/problems/smallest-string-starting-from-leaf/

class Solution {
public:
    string ans = "~";
    void dfs(TreeNode *root, string s) {
        if(!root) {
            return;
        }
        s += ('a' + root->val);
        if(!root->left && !root->right) {
            reverse(s.begin(), s.end());
            if(s < ans) {
                ans = s;
            }
            return;
        }
        dfs(root->left, s);
        dfs(root->right, s);
    }
    string smallestFromLeaf(TreeNode* root) {
        dfs(root, "");
        return ans;
    }
};