#include <bits/stdc++.h>
using namespace std;

// Used for finding SSC - Strongly Connected Components 
// Possible in Directed Graphs

class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void topo(int node, vector<int> adj[], vector<int> &vis, stack<int> &s) {
	    vis[node] = 1;
	    for(auto it : adj[node]) {
	        if(!vis[it])
	            topo(it, adj, vis, s);
	    }
	    s.push(node);
	}
	void dfs(int node, vector<int> adj[], vector<int> &vis) {
	    vis[node] = 1;
	    for(auto it : adj[node])
	        if(!vis[it])
	            dfs(it, adj, vis);
	}
    int kosaraju(int n, vector<int> adj[]) {
        stack<int> s;
        vector<int> vis(n, 0);
        
        // Getting topological sort
        for(int i = 0; i < n; i++)
            if(!vis[i])
                topo(i, adj, vis, s);
        
        // Generating new reversed adjancy list 
        vector<int> newAdj[n];
        for(int i = 0; i < n; i++)
            for(auto it : adj[i])
                newAdj[it].push_back(i);
        
        for(int i = 0; i < n; i++)
            vis[i] = 0;
        
        int scc = 0;
        
        // Counting the strongly connected components
        while(s.size()) {
            int node = s.top();
            s.pop();
            if(!vis[node]) {
                scc++;
                dfs(node, newAdj, vis);
            }
        }
        return scc;
    }
};