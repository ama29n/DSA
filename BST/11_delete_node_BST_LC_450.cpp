#include<bits/stdc++.h>
using namespace std;

TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        
        if(key > root->val) {root->right = deleteNode(root->right, key); return root;}
        
        else if(key < root->val) {root->left = deleteNode(root->left, key); return root;}
        
        else if(key == root->val) {
            if(!root->left && !root->right) return NULL;
            else if(!root->left && root->right) return root->right;
            else if(!root->right && root->left) return root->left;
            else {
                TreeNode *temp = root->left;
                while(temp && temp->right) {temp = temp->right;}
                temp->right = root->right;
                return root->left;
            }
        }
        return root;
    }