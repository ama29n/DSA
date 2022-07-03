#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *right;
    TreeNode *left;
};

vector<vector<int>> verticalTraversal(TreeNode* root) {
    // <Node*, <vertical, level>>
    queue<pair<TreeNode*, pair<int, int>>> q;
    q.push({root, {0, 0}});
    
    // <vertical, node>>
    map<int, int> mp;
    
    int minL = 0, maxR = 0;
    
    while(!q.empty()) {
        int n = q.size();
        while(n--) {
            pair<TreeNode*, pair<int, int>> p = q.front();
            q.pop();
            TreeNode *node = p.first;
            int x = p.second.first;
            int y = p.second.second;
            if(node->left) {
                q.push({node->left, {x - 1, y + 1}});
            }
            if(node->right) {
                q.push({node->right, {x + 1, y + 1}});
            }
            maxR = max(maxR, x);
            minL = min(minL, x);
            if(mp.find(x) == mp.end())
                mp[x] = node->val;
        }
    }
    
    vector<int> ans;
    for(int i = minL; i <= maxR; i++) {
        ans.push_back(mp[i]);
    }
    return {ans};
}