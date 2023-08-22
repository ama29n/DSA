#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/ 

class Solution {
public:
    TreeNode *construct(vector<int> &in, int s1, int e1, vector<int> &post, int s2, int e2) {
        if(s1 > e1 || s2 > e2) {
            return NULL;
        }
        int idx = s1;
        for(idx; idx <= e1; idx++) {
            if(in[idx] == post[e2]) {
                break;
            }
        }
        int x = e1 - idx;
        TreeNode *root = new TreeNode(post[e2]);
        root->left = construct(in, s1, idx - 1, post, s2, e2 - x - 1);
        root->right = construct(in, idx + 1, e1, post, e2 - x, e2 - 1);
        return root;
    }
    TreeNode *buildTree(vector<int> &in, vector<int> &post) {
        int m = in.size(), n = post.size();
        TreeNode *root = construct(in, 0, m - 1, post, 0, n - 1);
        return root;
    }
};