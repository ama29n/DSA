#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *right;
    TreeNode *left;
};

class Solution {
public:
    int mini = INT_MAX, maxi = INT_MIN;
    void dfs(TreeNode *root, int b) {
        if(!root) {
            return;
        }
        dfs(root->left, b - 1);
        dfs(root->right, b + 1);
        mini = min(mini, b);
        maxi = max(maxi, b);
    }
    int width(TreeNode *root) {
        dfs(root, 0);
        return maxi - mini + 1;
    }
}