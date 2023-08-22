#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1 

class Solution {
public:
    bool check(int node, vector<int> &vis, vector<int> &dfs, vector<int> adj[]) {
        vis[node] = dfs[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                if(check(it, vis, dfs, adj)) {
                    return true;
                }
            } else if(dfs[it] == 1) {
                return true;
            }
        }
        dfs[node] = 0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                vector<int> dfs(V, 0);
                if(check(i, vis, dfs, adj)) {
                    return true;
                }
            }
        }
        return false;
    }
};