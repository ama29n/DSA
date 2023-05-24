#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/cheapest-flights-within-k-stops/

class Solution {
public:
    vector<vector<int>> adj[102];
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) {
        for(auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> path(n, INT_MAX);
        queue<vector<int>> q;
        q.push({0, src, 0});
        path[src] = 0;
        int ans = INT_MAX, ans_k = INT_MAX;
        while(!q.empty()) {
            vector<int> v = q.front(); q.pop();
            int node_path = v[0], node = v[1], stops = v[2];
            if(stops > k) {
                break;
            }
            for(auto it : adj[node]) {
                int child = it[0], child_path = it[1] + node_path;
                if(child_path < path[child] && stops <= k) {
                    path[child] = child_path;
                    q.push({child_path, child, stops + 1});
                }
            }
        }
        return path[dst] == INT_MAX ? -1 : path[dst];
    }
};