#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
	class DSU {
	    public:
	    int n;
	    vector<int> parent, rank;
	    DSU(int V) : n(V) {
	        parent = vector<int> (n, 0);
	        rank = vector<int> (n, 1);
	        for(int i = 0; i < n; i++) {
	            parent[i] = i;
	        }
	    }
	    int findParent(int node) {
	        if(parent[node] == node)
	            return node;
	        return parent[node] = findParent(parent[node]);
	    }
	    void makeUnion(int x, int y) {
	        x = findParent(x);
	        y = findParent(y);
	        if(rank[x] > rank[y]) {
	            parent[y] = x;
	        } else if(rank[x] < rank[y]) {
	            parent[x] = y;
	        } else {
	            parent[x] = y;
	            rank[y]++;
	        }
	    }
	};
	
    int spanningTree(int n, vector<vector<int>> adj[]) {
        DSU d(n);
        vector<vector<int>> edges;
        for(int i = 0; i < n; i++) {
            for(auto it : adj[i]) {
                edges.push_back({it[1], i, it[0]});
            }
        }
        sort(edges.begin(), edges.end());
        int ans = 0;
        for(auto edge : edges) {
            int w = edge[0], x = edge[1], y = edge[2];
            if(d.findParent(x) != d.findParent(y)) {
                ans += w;
                d.makeUnion(x, y);
            }
        }
        return ans;
    }
};