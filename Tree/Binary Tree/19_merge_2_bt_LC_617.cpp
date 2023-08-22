#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *right, *left;
}

// https://leetcode.com/problems/merge-two-binary-trees/ 

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* r1, TreeNode* r2) {
        if(!r1 && !r2) {
            return NULL;
        }
        if(!r1 && r2) {
            return r2;
        }
        if(r1 && !r2) {
            return r1;
        }
        r1->val += r2->val;
        r1->left = mergeTrees(r1->left, r2->left);
        r1->right = mergeTrees(r1->right, r2->right);
        return r1;
    }
};


