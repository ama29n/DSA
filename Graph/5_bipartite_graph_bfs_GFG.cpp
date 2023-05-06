#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/bipartite-graph/1 

// Graph can be disconnected

class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V, -1);
	    for(int i = 0; i < V; i++) {
	        if(color[i] == -1) {
	            queue<int> q;
	            q.push(i); color[i] = 1;
	            while(!q.empty()) {
	                int node = q.front(); q.pop();
	                for(auto it : adj[node]) {
	                    if(color[it] == -1) {
	                        color[it] = 1 - color[node];
	                        q.push(it);
	                    } else if(color[it] == color[node]) {
	                        return false;
	                    }
	                }
	            }
	        }
	    }
	    return true;
	}
};

// Time - O(V + E)
// Space - O(V)