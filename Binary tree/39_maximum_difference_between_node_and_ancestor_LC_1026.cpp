#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *right;
    TreeNode *left;
};

// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/ 

// O(n ^ 2)
class Solution {
public:
    int ans = 0;
    int findMin(TreeNode *root) {
        if(!root) {
            return 100000;
        }
        int l = findMin(root->left);
        int r = findMin(root->right);
        return min({l, r, root->val});
    }
    int findMax(TreeNode *root) {
        if(!root) {
            return 0;
        }
        int l = findMax(root->left);
        int r = findMax(root->right);
        return max({l, r, root->val});
    }
    void dfs(TreeNode *root) {
        if(!root || (!root->left && !root->right)) { // answer on leaf would be 0
            return;
        }
        dfs(root->left); dfs(root->right);
        int x = min(findMin(root->left), findMin(root->right));
        int y = max(findMax(root->left), findMax(root->right));
        ans = max({ans, abs(x - root->val), abs(y - root->val)});
    }
    int maxAncestorDiff(TreeNode* root) {
        dfs(root);
        return ans;
    }
};



// O(n)
