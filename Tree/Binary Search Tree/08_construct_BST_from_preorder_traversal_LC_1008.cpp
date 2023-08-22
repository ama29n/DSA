#include <bits/stdc++.h>
using namespace std;

class TreeNode {
    int val;
    TreeNode *left, *right;
};

// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/ 

class Solution {
public:
    TreeNode *dfs(vector<int> &pre, int l, int r) {
        if(l > r) {
            return NULL;
        }
        int m;
        for(m = l + 1; m <= r; m++) {
            if(pre[m] > pre[l]) {
                break;
            }
        }
        TreeNode *root = new TreeNode(pre[l]);
        root->left = dfs(pre, l + 1, m - 1);
        root->right = dfs(pre, m, r);
        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &pre) {
        return dfs(pre, 0, pre.size() - 1);
    }
};