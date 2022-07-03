

// In this question we have to calculate the number of those nodes, whose value is the largest amongst all nodes from 
// the root till them.

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *right;
    TreeNode *left;
};

class Solution {
public:
    
    int count=0;
    
    void nodes(TreeNode* root, int maxSoFar)
    {
        if(root==NULL)
            return;
        
        int maxx;
        
        if(root->val>=maxSoFar)
        {
            count++;
        }
        
        maxx=max(root->val,maxSoFar);
        
        nodes(root->left,maxx);
        nodes(root->right,maxx);
    }
        
    
    int goodNodes(TreeNode* root) {
        nodes(root,INT_MIN);
        return count;
    }
};
