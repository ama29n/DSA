#include <bits/sdtc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *right;
    TreeNode *left;
};

// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/ 

// Intution
// At each level the direction of nodes will reverse, thus 2 stacks can be used
// One stack will contain the nodes and 2nd stack will store the child nodes
// The 2nd stack will become the primary stack then

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        if(!root) return {};
        vector<vector<int>> ans;
        stack<TreeNode *> parent, child;
        parent.push(root);
        int level = 0;
        while(!parent.empty()) {
            int n = parent.size();
            vector<int> v;
            while(n--) {
                TreeNode *node = parent.top(); parent.pop();
                v.push_back(node->val);
                if(level % 2 == 0) {
                    if(node->left) child.push(node->left);
                    if(node->right) child.push(node->right);
                } else {
                    if(node->right) child.push(node->right);
                    if(node->left) child.push(node->left);
                }
            }
            ans.push_back(v);
            level++;
            parent = child;
            while(!child.empty()) child.pop();
        }
        return ans;
    }
};