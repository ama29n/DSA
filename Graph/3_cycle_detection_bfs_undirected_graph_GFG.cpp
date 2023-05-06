#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1 

// Graph can be disconnected

class Solution {
  public:
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        // <node, parent>
        for(int i = 0; i < V; i++){
            if(!vis[i]) {
                queue<pair<int, int>> q;
                q.push({i, -1}); vis[i] = 1;
                while(!q.empty()) {
                    int node = q.front().first;
                    int parent = q.front().second;
                    q.pop();
                    for(auto it : adj[node]) {
                        if(!vis[it]) {
                            vis[it] = 1;
                            q.push({it, node});
                        } else if(parent != it) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};

// Time - O(V + E)
// Space - O(V)