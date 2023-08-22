#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *right;
    TreeNode *left;
};

// https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/

class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int sum = 0;
        if(root->val % 2 == 0 && root->left) {
            if(root->left->left) {
                sum += root->left->left->val;
            }
            if(root->left->right) {
                sum += root->left->right->val;
            }
        }
        if(root->val % 2 == 0 && root->right) {
            if(root->right->left) {
                sum += root->right->left->val;
            }
            if(root->right->right) {
                sum += root->right->right->val;
            }
        }
        sum += sumEvenGrandparent(root->left);
        sum += sumEvenGrandparent(root->right);
        return sum;
    }
};