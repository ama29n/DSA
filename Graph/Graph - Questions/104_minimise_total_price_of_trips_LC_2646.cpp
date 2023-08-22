#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimize-the-total-price-of-the-trips/ 

class Solution {
public:
    int n;
    vector<int> price, count;
    // Function to find number of times each node is visited
    bool dfs(int src, int dst, vector<int> &vis, vector<int> adj[]) {
        vis[src] = 1;
        if(src == dst) return true;
        for(auto it : adj[src]) {
            if(!vis[it]) {
                count[it]++; 
                if(dfs(it, dst, vis, adj)) return true;
                count[it]--;
            }
        }
        return false;
    }
    // Function to calculate minimum path 
    int dp[52][2];
    // 1 -> Can take current node | 0 -> Cannot take current node
    int cal(int node, int parent, int can_take, vector<int> adj[]) {
        if(dp[node][can_take] != -1) {
            return dp[node][can_take];
        }
        if(can_take == 0) {
            int ans = 0;
            for(auto it : adj[node]) {
                if(it != parent) 
                    ans += cal(it, node, 1, adj);
            }
            ans += price[node] * count[node];
            return dp[node][can_take] = ans;
        }
        int take = 0, notTake = 0;
        for(auto it : adj[node]) {
            if(it != parent) {
                take += cal(it, node, 0, adj);
                notTake += cal(it, node, 1, adj);
            }
        }
        take += (price[node] / 2) * count[node];
        notTake += price[node] * count[node];
        return dp[node][can_take] = min(take, notTake);
    }
    // Driver Function
    int minimumTotalPrice(int N, vector<vector<int>> &edges, vector<int> &PRICE, vector<vector<int>> &trips) {
        n = N; price = PRICE;
        vector<int> adj[n];
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]); adj[it[1]].push_back(it[0]);
        }
        count.resize(n, 0);
        // Number of time each node is visited
        for(auto it : trips) {
            count[it[0]]++;
            vector<int> vis(n, 0);
            dfs(it[0], it[1], vis, adj);
        }
        memset(dp, -1, sizeof(dp));
        return cal(0, -1, 1, adj);
    }
};