#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

class Solution {
public:
    typedef long long ll;
    typedef pair<ll, int> p;
    int mod = (1e9 + 7);
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> adj[n];
        for(auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        vector<ll> dis(n, LLONG_MAX);
        dis[0] = 0;
        vector<int> ways(n, 0);
        ways[0] = 1;
        priority_queue<p, vector<p>, greater<p>> q;
        q.push({0, 0});
        while(!q.empty()) {
            ll d = q.top().first;
            int node = q.top().second;
            q.pop();
            for(auto it : adj[node]) {
                int adj_node = it.first;
                ll adj_d = it.second;
                ll path = d + adj_d;
                if(path < dis[adj_node]) {
                    dis[adj_node] = path;
                    q.push({path, adj_node});
                    ways[adj_node] = ways[node];
                    continue;
                }
                if(path == dis[adj_node]) {
                    ways[adj_node] += ways[node];
                    ways[adj_node] %= mod;
                }
            }
        }
        return ways[n - 1];
    }
};