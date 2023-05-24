#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1# 

class Solution {
	public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<int> weight(V, INT_MAX);
        vector<int> vis(V, 0);
        weight[0] = 0;
        for(int i = 0; i < V - 1; i++) {
            int node, min_edge = INT_MAX;
            for(int j = 0; j < V; j++) {
                if(weight[j] < min_edge && !vis[j]) {
                    node = j; min_edge = weight[j];
                }
            }
            vis[node] = 1;
            for(auto it : adj[node]) {
                int child = it[0], child_edge = it[1];
                if(child_edge < weight[child] && !vis[child]) {
                    weight[child] = child_edge;
                }
            }
        }
        int mst = 0;
        for(auto it : weight) {
            mst += it;
        }
        return mst;
    }
};