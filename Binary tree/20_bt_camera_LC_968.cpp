#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *right;
    TreeNode *left;
};

// https://leetcode.com/problems/binary-tree-cameras/

class Solution {
public:
    #define has_camera      1
    #define no_need         2
    #define no_camera       3
    int count = 0;
    int dfs(TreeNode *root) {
        if(!root) {
            return no_need;
        }
        if(!root->left && !root->right) {
            return no_camera;
        }
        int l = dfs(root->left); int r = dfs(root->right);
        if(l == no_camera || r == no_camera) {
            count++;
            return has_camera;
        }
        if(l == has_camera || r == has_camera) {
            return no_need;
        }
        // no_need: which means now the camera will be needed
        return no_camera;
    }
    int minCameraCover(TreeNode* root) {
        return dfs(root) == no_camera ? count + 1 : count;
    }
};