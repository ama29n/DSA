#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *right;
    TreeNode *left;
};

// https://leetcode.com/problems/binary-tree-cameras/

class Solution {
private:
    #define no_need            1
    #define has_camera         2
    #define no_camera          3
    int count = 0;
public:
    int dfs(TreeNode *root) {
        // When there isn't left or right child, then result from that side should't matter
        if(!root) {
            return no_need;
        }

        // Leaf nodes shouldn't have camera to optimise the answer 
        if(!root->left && !root->right) {
            return no_camera;
        }

        int l = dfs(root->left);
        int r = dfs(root->right);

        // Case: no_camera
        // If any child doesn't have a camera, current node must have a camera to monitor it
        if(l == no_camera || r == no_camera) {
            count++;
            return has_camera;
        }

        // Case: has_camera
        // If any child has camera then current node is covered
        if(l == has_camera || r == has_camera) {
            return no_need;
        }

        // Case: no_need
        // If child nodes have no need then they are covered 
        // But current node is not covered. Therefore,
        return no_camera;
    }
    int minCameraCover(TreeNode *root) {
        return dfs(root) == no_camera ? count + 1 : count;
    }
};