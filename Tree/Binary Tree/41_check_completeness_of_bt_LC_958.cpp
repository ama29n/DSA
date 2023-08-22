#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *right;
    TreeNode *left;
};

// https://leetcode.com/problems/check-completeness-of-a-binary-tree/

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        bool l = true, r = true;
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                TreeNode *top = q.front(); q.pop();
                if(top->left) {
                    if(!r) return false;
                    q.push(top->left);
                } else {
                    l = false;
                }
                if(top->right) {
                    if(!l) return false;
                    q.push(top->right);
                } else {
                    r = false;
                }
            }
        }
        return true;
    }
};

