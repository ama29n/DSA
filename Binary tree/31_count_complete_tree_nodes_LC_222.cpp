#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *right;
    TreeNode *left;
};

// https://leetcode.com/problems/count-complete-tree-nodes/

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        TreeNode *l = root, *r = root;
        int ls = 0, rs = 0;
        while(l) {
            ls++; l = l->left;
        }
        while(r) {
            rs++; r = r->right;
        }
        if(ls == rs)
            return (1 << ls) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};