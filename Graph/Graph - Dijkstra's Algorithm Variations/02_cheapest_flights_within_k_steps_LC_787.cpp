#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/cheapest-flights-within-k-stops/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>> &edges, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        for(auto it : edges) {
            adj[it[0]].push_back({ it[1], it[2] });
        }
        vector<int> path(n, INT_MAX);
        path[src] = 0;
        queue<vector<int>> q;
        q.push({ 0, src, 0 });
        while(!q.empty()) {
            vector<int> v = q.front(); q.pop();
            int stops = v[0], node = v[1], node_path = v[2];
            if(stops > k) break;
            for(auto it : adj[node]) {
                int child = it.first, child_path = it.second + node_path;
                if(child_path < path[child]) {
                    path[child] = child_path;
                    q.push({ stops + 1, child, child_path });
                }
            }
        }
        return path[dst] == INT_MAX ? -1 : path[dst];
    }
};
