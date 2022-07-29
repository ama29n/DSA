#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *right;
    TreeNode *left;
};

// In this question one thing to note is that it is not necessary that the path passes through the root node
// &
// that the path must be from one leaf node to another leaf node
// it can be any path within as well, not passing through the root and with no leaf nodes

int maxPath = INT_MIN;
    
int cal(TreeNode* root) {
    if(!root)
        return 0;
    int l = cal(root->left);
    int r = cal(root->right);
    
    int sum = max({root->val, r + root->val, l + root->val});
    maxPath = max({maxPath, sum, root->val + l + r});
    
    return sum;
}

int maxPathSum(TreeNode* root) {
    int p = cal(root);
    return maxPath;
}
