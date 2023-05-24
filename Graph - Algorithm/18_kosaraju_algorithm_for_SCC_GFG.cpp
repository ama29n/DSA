#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

// Possible in Directed Graphs
class Solution {
	public:
    stack<int> s;
	void topoSort(int node, vector<int> adj[], vector<int> &vis) {
	    vis[node] = 1;
	    for(auto it : adj[node]) {
	        if(!vis[it]) topoSort(it, adj, vis);
	    }
	    s.push(node);
	}
	void dfs(int node, vector<int> adj[], vector<int> &vis) {
	    vis[node] = 1;
	    for(auto it : adj[node]) if(!vis[it]) dfs(it, adj, vis);
	}
    int kosaraju(int n, vector<int> adj[]) {
        vector<int> vis(n, 0);
        // Getting topological sort
        for(int i = 0; i < n; i++) if(!vis[i]) topoSort(i, adj, vis);
        // Generating new reversed adjancy list 
        vector<int> newAdj[n];
        for(int i = 0; i < n; i++) {
            for(auto it : adj[i]) newAdj[it].push_back(i);
        }
        vis.clear(); vis.resize(n, 0);
        int scc = 0;
        // Counting the strongly connected components
        while(s.size()) {
            int node = s.top();
            s.pop();
            if(!vis[node]) {
                scc++; dfs(node, newAdj, vis);
            }
        }
        return scc;
    }
};