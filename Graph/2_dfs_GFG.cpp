#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1 

class Solution {
  public:
    vector<int> v;
    void dfs(int node, vector<int> &vis, vector<int> adj[]) {
        vis[node] = 1;
        v.push_back(node);
        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(it, vis, adj);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        dfs(0, vis, adj);
        return v;
    }
};

// Time - O(V + E), where V is number of vertices and E is number of edges
// Space - O(V + E), since an extra visited array of size V is used and stack space for dfs() call