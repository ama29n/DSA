#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *right;
    TreeNode *left;
};

// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) {
            return;
        }

        flatten(root->left);
        flatten(root->right);

        // Assume: we get the flattened LL from left and right subtree
        TreeNode *ptr = root;

        // Storwe right LL in temp
        TreeNode *temp = root->right;
        
        // Connect left LL to right side of node
        root->right = root->left;
        root->left = NULL;

        // Iterate to the end of the left LL and 
        while(ptr->right != NULL) {
            ptr = ptr->right;
        }

        // Connect right LL to end of left LL
        ptr->right = temp;
        
        return;
    }
};