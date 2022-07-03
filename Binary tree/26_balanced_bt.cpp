#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *right;
    TreeNode *left;
};

class Solution {
public:
    int height(TreeNode *root) {
        if(!root) return 0;
        int l = height(root->left);
        int r = height(root->right);
        return (max(l, r)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        bool l = isBalanced(root->left);
        bool r = isBalanced(root->right);
        if(!l || !r) return false;
        int diff = fabs(height(root->left) - height(root->right));
        if(diff == 1 || diff == 0)
            return true;
        return false;
    }
};