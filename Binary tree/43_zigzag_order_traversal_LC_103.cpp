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
        stack<TreeNode *> p, ch;
        int level = 0;
        p.push(root);
        while(!p.empty()) {
            int n = p.size();
            vector<int> row;
            while(n--) {
                TreeNode *node = p.top();
                p.pop();
                row.push_back(node->val);
                if(level % 2 == 0) {
                    if(node->left) {
                        ch.push(node->left);
                    }
                    if(node->right) {
                        ch.push(node->right);
                    }
                } else {
                    if(node->right) {
                        ch.push(node->right);
                    } 
                    if(node->left) {
                        ch.push(node->left);
                    }
                }
            }
            level++;
            p = ch;
            ans.push_back(row);
            while(!ch.empty()) {
                ch.pop();
            }
        }
        return ans;
    }
};