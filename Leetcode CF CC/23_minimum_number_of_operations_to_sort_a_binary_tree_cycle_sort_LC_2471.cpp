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
    int minSwaps(vector<int>& v, int n) {
        unordered_map<int, int> map;
        for(int i = 0; i < n; i++)
            map[v[i]] = i;
        sort(v.begin(), v.end());
        int swaps = 0;
        vector<bool> vis(n, false);
        for(int i = 0; i < n; i++) {
            if(vis[i] || map[v[i]] == i) 
                continue;
            int j = i, cycle_count = 0;
            while(!vis[j]) {
                vis[j] = true;
                j = map[v[j]];
                cycle_count++;
            }
            swaps += (cycle_count > 0 ? cycle_count - 1 : 0);
        }
        return swaps;
    }
    int minimumOperations(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            vector<int> v;
            while(n--) {
                TreeNode *node = q.front();
                q.pop();
                v.push_back(node->val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            ans += minSwaps(v, v.size());
        }
        return ans;
    }
};