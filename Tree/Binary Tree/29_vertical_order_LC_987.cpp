#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *right;
    TreeNode *left;
};

// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/ 

class Solution {
private:
    #define ff first
    #define ss second
public:
    vector<vector<int>> verticalTraversal(TreeNode *root) {
        map<int, map<int, multiset<int>>> m;             // < vertical, level, multiset >
        queue<pair<TreeNode *, pair<int, int>>> q;       // < node, vertical, level >
        q.push({ root, { 0, 0 } });
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                TreeNode *node = q.front().ff;
                int vertical = q.front().ss.ff, level = q.front().ss.ss;
                q.pop();
                m[vertical][level].insert(node->val);
                if(node->left) {
                    q.push({ node->left, { vertical - 1, level + 1 } });
                }
                if(node->right) {
                    q.push({ node->right, { vertical + 1, level + 1 } });
                }
            }
        }
        vector<vector<int>> ans;
        for(auto outer_map : m) {
            vector<int> v;
            for(auto inner_map : outer_map.ss) {
                for(auto it : inner_map.ss) {
                    v.push_back(it);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};