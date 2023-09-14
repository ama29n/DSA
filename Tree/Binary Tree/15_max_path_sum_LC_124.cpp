#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *right;
    TreeNode *left;
}; 

// https://leetcode.com/problems/binary-tree-maximum-path-sum/ 

// It is not necessary that the path passes through the root node
// or
// that the path is from one leaf node to another leaf node

class Solution {
private:
    int max_path = INT_MIN;
public:
    int dfs(TreeNode *root) {
        if(!root) {
            return 0;
        }
        
        // l & r -> give the maximum sum path in both subtrees
        int l = dfs(root->left);
        int r = dfs(root->right);

        // max_till_now -> assure path won't be discontinuous
        int max_till_now = max({ root->val, r + root->val, l + root->val });

        // path_through_subtrees -> forms the max path b/w 2 leaf nodes, through current node
        int path_through_subtrees = root->val + l + r;
        
        // max_path -> maintains the max path
        max_path = max({ max_path, max_till_now, path_through_subtrees });

        // return
        return max_till_now;
    }
    int maxPathSum(TreeNode* root) {
        int p = dfs(root);
        return max_path;
    }
};
