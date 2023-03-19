#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *right;
    TreeNode *left;
};

// https://leetcode.com/problems/count-good-nodes-in-binary-tree/ 

class Solution {
public:
    int goodNodes(TreeNode* root, int maxSoFar = -1E4) {
        if(!root) {
            return 0;
        }
        maxSoFar = max(maxSoFar, root->val);
        int count = maxSoFar > root->val ? 0 : 1;
        count += goodNodes(root->left, maxSoFar);
        count += goodNodes(root->right, maxSoFar);
        return count;
    }
};