#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1 

// Graph can be disconnected

class Solution {
  public:
    bool dfs(int node, int parent, vector<int> &vis, vector<int> adj[]) {
        vis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                if(dfs(it, node, vis, adj)) {
                    return true;
                }
            } else if(parent != it) {
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if(dfs(i, -1, vis, adj)) {
                    return true;
                }
            }
        }
        return false;
    }
};

// Time - O(V + E)
// Space - O(V + E)