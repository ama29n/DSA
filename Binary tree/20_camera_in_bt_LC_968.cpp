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
    
    #define no_camera 1
    #define has_camera 2
    #define no_need 3
    
    int count=0;
    
    int camera(TreeNode* root)
    {
        if(root==NULL)
            return no_need;
        
        if(root->left==NULL && root->right==NULL)
            return no_camera;
        
        int ls=camera(root->left);
        int rs=camera(root->right);
        
        if(ls==no_camera || rs==no_camera)
        {
            count++;
            return has_camera;
        }
        
        if(rs==has_camera || ls==has_camera)
            return no_need;
        
        return no_camera;
    }
    
    int minCameraCover(TreeNode* root) {
        
        if(camera(root)==no_camera)
            count++;
        
        return count;
    }
};