#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *right;
    TreeNode *left;
};

// https://leetcode.com/problems/distribute-coins-in-binary-tree/ 

// There are n nodes and n coins

class Solution {
public:
    int moves = 0;
    int distribute(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int l = distribute(root->left);
        int r = distribute(root->right);
        moves += abs(r) + abs(l);
        return root->val + l + r - 1;
    }
    int distributeCoins(TreeNode* root) {
        distribute(root);
        return moves;
    }
};