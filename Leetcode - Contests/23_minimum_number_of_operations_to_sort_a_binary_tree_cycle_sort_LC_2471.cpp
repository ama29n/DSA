#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

// https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/

class Solution {
public:
    int cycleSort(vector<int>& v, int n) {
        int swaps = 0;
        int cycle_start = 0;
        while(cycle_start <= n - 2) {
            int cur_ele = v[cycle_start];
            int pos = cycle_start;
            for(int i = cycle_start + 1; i < n; i++) {
                if(v[i] < cur_ele)
                    pos++;
            }
            if(pos == cycle_start) {
                cycle_start++;
                continue;
            }
            // If the array contains duplicate items
            // while(cur_ele == v[pos])
            //     pos++;
            swap(v[cycle_start], v[pos]);
            swaps++;
        }
        return swaps;
    }
    int ans = 0;
    void cal(vector<int> &v) {
        int n = v.size();
        unordered_map<int, int> map;
        for(int i = 0; i < n; i++) {
            map[v[i]] = i;
        }
        sort(v.begin(), v.end());
        vector<int> vis(n, 0);
        for(int i = 0; i < n; i++) {
            if(vis[i] || map[v[i]] == i) {
                continue;
            }
            int j = i, swaps = 0;
            while(!vis[j]) {
                vis[j] = true;
                j = map[v[j]];
                swaps++;
            }
            ans += swaps > 0 ? swaps - 1 : 0;
        }
    }
    int minimumOperations(TreeNode* root) {
        if(!root) {
            return ans;
        }
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            vector<int> v;
            while(n--) {
                TreeNode *r = q.front(); q.pop();
                v.push_back(r->val);
                if(r->left) q.push(r->left); 
                if(r->right) q.push(r->right);
            }
            cal(v);
        }
        return ans;
    }
};