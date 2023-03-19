#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/ 

class Solution {
public:
    TreeNode *construct(vector<int> &pre, int s1, int e1, vector<int> &in, int s2, int e2) {
        if(s1 > e1 || s2 > e2) {
            return NULL;
        }
        int idx = s2;
        for(idx; idx <= e2; idx++) {
            if(pre[s1] == in[idx]) {
                break;
            }
        }
        int x = idx - s2;
        TreeNode *root = new TreeNode(pre[s1]);
        root->left = construct(pre, s1 + 1, s1 + x, in, s2, idx - 1);
        root->right = construct(pre, s1 + x + 1, e1, in, idx + 1, e2);
        return root;
    }
    TreeNode *buildTree(vector<int> &pre, vector<int> &in) {
        int m = pre.size(), n = in.size();
        TreeNode *root = construct(pre, 0, m - 1, in, 0, n - 1);
        return root;
    }
};