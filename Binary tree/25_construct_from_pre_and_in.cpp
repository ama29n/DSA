#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


TreeNode *build(int s1, int e1, vector<int> &pre, int s2, int e2, vector<int> &in) {
    if(s1 > e1 || s2 > e2)
        return NULL;

    TreeNode *root = new TreeNode(pre[s1]);

    int idx;
    for(int i = s2; i <= e2; i++) {
      if(pre[s1] == in[i]) {
            idx = i;
            break;
        }
    }

    int gap = idx - s2;
    root->left = build(s1 + 1, s1 + gap, pre, s2, idx - 1, in);
    root->right = build(s1 + gap + 1, e1, pre, idx + 1, e2, in);
    
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    TreeNode *root = build(0, preorder.size() -  1, preorder, 0, inorder.size() - 1, inorder);
    return root;
}