#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *right;
    TreeNode *left;
};

// https://leetcode.com/problems/flip-equivalent-binary-trees 

class Solution {
public:
    bool flipEquiv(TreeNode* r1, TreeNode* r2) {
        if(!r1 && !r2) {
            return true;
        }
        if(!r1 && r2 || r1 && !r2) {
            return false;
        }
        if(r1->val != r2->val) {
            return false;
        }
        bool x = flipEquiv(r1->left, r2->left) && flipEquiv(r1->right, r2->right);
        bool y = flipEquiv(r1->left, r2->right) && flipEquiv(r1->right, r2->left);
        return x || y;
    }
};