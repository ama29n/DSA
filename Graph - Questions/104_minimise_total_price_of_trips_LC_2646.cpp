#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimize-the-total-price-of-the-trips/ 

class Solution {
public:
    int n;
    vector<int> price;
    int count[52];
    bool process(int src, int des, vector<int> &vis, vector<int> adj[]) {
        if(src == des) {
            return true;
        }
        vis[src] = 1;
        for(auto it : adj[src]) {
            if(!vis[it] && process(it, des, vis, adj)) {
                count[it]++;
                return true;
            }
        }
        return false;
    }
    // can_take = 1, means parent is not taken
    // can_take = 0, means parent is taken
    int dp[52][2];
    int dfs(int node, int parent, int can_take, vector<int> adj[]) {
        if(dp[node][can_take] != -1) {
            return dp[node][can_take];
        }
        if(can_take == 0) {
            int ans = 0;
            for(auto it : adj[node]) {
                if(it != parent) {
                    ans += dfs(it, node, 1, adj);
                }
            }
            ans += count[node] * price[node];
            return dp[node][can_take] = ans;
        }
        // Parent is not taken
        // Here we have 2 case; either we take current node or we don't
        int take = 0, not_take = 0;
        for(auto it : adj[node]) {
            if(it != parent) {
                take += dfs(it, node, 0, adj);
                not_take += dfs(it, node, 1, adj);
            }
        }
        take += count[node] * (price[node] / 2);
        not_take += count[node] * price[node];
        return dp[node][can_take] = min(take, not_take);
    }
    int minimumTotalPrice(int N, vector<vector<int>>& edges, vector<int>& P, vector<vector<int>>& trips) {
        n = N;
        price = P;
        vector<int> adj[n];
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]); adj[it[1]].push_back(it[0]);
        }
        memset(count, 0, sizeof(count));
        for(auto it : trips) {
            vector<int> vis(n, 0);
            count[it[0]]++;
            process(it[0], it[1], vis, adj);
        }
        memset(dp, -1, sizeof(dp));
        return dfs(0, -1, 1, adj);
    }
};