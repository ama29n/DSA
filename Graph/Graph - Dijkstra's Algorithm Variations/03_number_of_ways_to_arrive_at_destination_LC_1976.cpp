#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

class Solution {
public:
    typedef long long ll;
    typedef pair<ll, int> P;
    const int mod = 1E9 + 7;
    int countPaths(int n, vector<vector<int>> &roads) {
        vector<pair<int, int>> adj[n];
        for(auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        vector<ll> path(n, LLONG_MAX);
        path[0] = 0;
        vector<ll> ways(n, 0);
        ways[0] = 1;
        priority_queue<P, vector<P>, greater<P>> q;
        q.push({0, 0});
        while(!q.empty()) {
            auto [node_path, node] = q.top(); q.pop();
            if(node_path > path[node]) continue;
            for(auto it : adj[node]) {
                ll child = it.first, child_path = node_path + it.second;
                if(child_path < path[child]) {
                    path[child] = child_path;
                    q.push({child_path, child});
                    ways[child] = ways[node];
                } else if(child_path == path[child]) {
                    ways[child] += ways[node];
                    ways[child] %= mod;
                }
            }
        }
        return ways[n - 1];
    }
};
