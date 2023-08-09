#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *right;
    TreeNode *left;
};

// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

class Solution {
private:
    vector<int> ans;
    vector<TreeNode *> findPath(TreeNode *root, TreeNode *node) {
        if(!root) return {};
        if(root == node) {
            return { node };
        }
        vector<TreeNode *> l = findPath(root->left, node);
        vector<TreeNode *> r = findPath(root->right, node);
        if(l.size() > 0) {
            l.push_back(root); return l;
        }
        if(r.size() > 0) {
            r.push_back(root); return r;
        }
        return {};
    }
    void dfs(TreeNode *root, int k, TreeNode *after) {
        if(!root) return;
        if(k == 0) {
            ans.push_back(root->val); return;
        }
        if(root->left && root->left != after) {
            dfs(root->left, k - 1, after);
        }
        if(root->right && root->right != after) {
            dfs(root->right, k - 1, after);
        }
    }
public:
    vector<int> distanceK(TreeNode *root, TreeNode *node, int k) {
        vector<TreeNode *> path = findPath(root, node);
        for(int i = 0; i < path.size() && (k - i) >= 0; i++) {
            dfs(path[i], k - i, i == 0 ? NULL : path[i - 1]);
        }
        return ans;
    }
};