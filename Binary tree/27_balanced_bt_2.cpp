#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *right;
    TreeNode *left;
};

class helper {
    public:
    int height;
    bool bal;
};
helper fn(TreeNode* root) {
    if(!root) {
        helper h;
        h.height = 0;
        h.bal = true;
        return h;
        }
    helper l = fn(root->left);
    helper r = fn(root->right);
    helper h;
    
    if(!l.bal || !r.bal) {h.bal = false; return h;}
    
    h.height = max(l.height, r.height) + 1;
    
    int diff = (l.height - r.height);
    
    if(diff == 1 || diff == 0 || diff == -1) h.bal = true;
    
    else h.bal = false;
    
    return h;
}
bool isBalanced(TreeNode* root) {
    helper h = fn(root);
    return h.bal;
}