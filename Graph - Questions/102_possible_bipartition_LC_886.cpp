#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/possible-bipartition/ 

// Bipartition is same in directed and indirected graphs

class Solution {
public:
    bool dfs(int node, vector<int> &color, vector<int> adj[]) {
        for(auto it : adj[node]) {
            if(color[it] == -1) {
                color[it] = 1 - color[node];
                if(!dfs(it, color, adj)) {
                    return false;
                }
            } else if(color[node] == color[it]) return false;
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>> &edges) {
        vector<int> adj[n];
        for(auto it : edges) {
            adj[it[0] - 1].push_back(it[1] - 1);
            adj[it[1] - 1].push_back(it[0] - 1);
        }
        vector<int> color(n, -1);
        for(int i = 0; i < n; i++) {
            if(color[i] == -1) {
                color[i] = 1;
                if(!dfs(i, color, adj)) {
                    return false;
                }
            }
        }
        return true;
    }
};