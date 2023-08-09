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
    string smallestFromLeaf(TreeNode* root, string str = "") {
        // Case: If either left or right child doesn't exist
        if(!root) return "~";
        string x = str + char('a' + root->val);
        string l = smallestFromLeaf(root->left, x);
        string r = smallestFromLeaf(root->right, x);
        if(!root->left && !root->right) {
            reverse(x.begin(), x.end());
            return x;
        }
        return min(l, r);
    }
};