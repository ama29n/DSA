#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/topological-sort/1 

class Solution {
	public:
	void topo(int node, vector<int> &vis, vector<int> &v, vector<int> adj[]) {
	    vis[node] = 1;
	    for(auto it : adj[node]) {
	        if(!vis[it]) {
	            topo(it, vis, v, adj);
	        }
	    }
	    v.push_back(node);
	}
	vector<int> topoSort(int V, vector<int> adj[]) {
	    vector<int> ans;
	    vector<int> vis(V, 0);
	    for(int i = 0; i < V; i++) {
	        if(!vis[i]) {
	            topo(i, vis, ans, adj);
	        }
	    }
	    reverse(ans.begin(), ans.end());
	    return ans;
	}
};