#include <bits/stdc++.h>
using namespace std;

class TreeNode {
    int val;
    TreeNode *left, *right;
};

// https://leetcode.com/problems/delete-node-in-a-bst/

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) {
            return root;
        } else if(root->val > key) {
            root->left = deleteNode(root->left, key);
        } else if(root->val < key) {
            root->right = deleteNode(root->right, key);
        } else {
            if(!root->left && !root->right) {
                return NULL;
            } else if(!root->left) {
                return root->right;
            } else if(!root->right) {
                return root->left;
            } else {
                TreeNode *ptr = root->left;
                while(ptr->right) ptr = ptr->right;
                ptr->right = root->right;
                return root->left;
            }
        }
        return root;
    }
};

// TreeNode *ptr = root->right;
// while(ptr->left) {
//     ptr = ptr->left;
// }
// ptr->left = root->left;
// return root->right;