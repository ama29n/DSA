#include <bits/stdc++.h>
using namespace std;

class TreeNode {
    int val;
    TreeNode *left, *right;
};

// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/ 

class Solution {
public:
    unordered_set<int> set;
    bool findTarget(TreeNode* root, int k) {
        if(!root) {
            return false;
        }
        if(set.find(k - root->val) != set.end()) {
            return true;
        }
        set.insert(root->val);
        bool l = findTarget(root->left, k);
        bool r = findTarget(root->right, k);
        return l || r;
    }
};