#include <bits/stdc++.h>
using namespace std;

class TreeNode {
    int val;
    TreeNode *left, *right;
};

// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/ 

class Solution {
public:
    TreeNode *dfs(vector<int> &nums, int l, int r) {
        if(l > r) {
            return NULL;
        }
        int m = l + (r - l) / 2;
        TreeNode *root = new TreeNode(nums[m]);
        root->left = dfs(nums, l, m - 1);
        root->right = dfs(nums, m + 1, r);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int> &nums) {
        int n = nums.size();
        return dfs(nums, 0, n - 1);
    }
};