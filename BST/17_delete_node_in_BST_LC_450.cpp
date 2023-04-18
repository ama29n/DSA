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
        } else if(key < root->val) {
            root->left = deleteNode(root->left, key);
            return root;
        } else if(key > root->val) {
            root->right = deleteNode(root->right, key);
            return root;
        } else {
            if(!root->left && !root->right) {
                return NULL;
            } else if(root->left && !root->right) {
                return root->left;
            } else if(!root->left && root->right) {
                return root->right;
            } else {
                TreeNode *ptr = root->left;
                while(ptr->right) {
                    ptr = ptr->right;
                }
                ptr->right = root->right;
                return root->left;
            }
        }
    }
};

// TreeNode *ptr = root->right;
// while(ptr->left) {
//     ptr = ptr->left;
// }
// ptr->left = root->left;
// return root->right;