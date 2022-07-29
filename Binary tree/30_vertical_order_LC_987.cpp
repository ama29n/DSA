#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *right;
    TreeNode *left;
};
vector<vector<int>> verticalTraversal(TreeNode* root) {
    // <TreeNode*, <vertical, level>>
    queue<pair<TreeNode*, pair<int, int>>> q;
    q.push({root, {0, 0}});

    // <vertical, <level, multiset to store elements>>
    map<int, map<int, multiset<int>>> mp;

    while(q.size()) {
        int n = q.size();
        for(int i = 0; i < n; i++) {
            TreeNode *node = q.front().first;
            int v = q.front().second.first;
            int l = q.front().second.second;

            q.pop();

            mp[v][l].insert(node->val);

            if(node->left)
                q.push({node->left, {v - 1, l + 1}});
            if(node->right)
                q.push({node->right, {v + 1, l + 1}});
        }
    }

    vector<vector<int>> ans;
    for(auto it : mp) {
        vector<int> v;
        for(auto m : it.second) {
            for(auto el : m.second)
                v.push_back(el);
        }
        ans.push_back(v);
    }
    return ans;
}