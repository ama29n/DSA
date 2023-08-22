#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-cycle-in-a-graph/

class Solution {
public:
    int dfs(int node, vector<int> &vis, vector<int> &length, vector<int> adj[], int len) {
        vis[node] = 1;
        length[node] = len;
        int tlen = -1;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                int x = dfs(it, vis, length, adj, len + 1);
                tlen = max(tlen, x);
            } else if(length[it] != -1) {
                int x = length[node] - length[it] + 1;
                tlen = max(tlen, x);
            }
        }
        length[node] = -1;
        return tlen;
    }
    int longestCycle(vector<int> &edges) {
        int n = edges.size();
        vector<int> adj[n]; for(int i = 0; i < n; i++) if(edges[i] != -1) adj[i].push_back(edges[i]);
        vector<int> vis(n, 0);
        vector<int> length(n, -1);
        int ans = -1;
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                int x = dfs(i, vis, length, adj, 1);
                ans = max(ans, x);
            }
        }
        return ans;
    }
};