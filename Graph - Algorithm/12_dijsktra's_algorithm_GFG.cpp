#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1# 

// Priority Queue Method
class Solution {
    #define ff   first
    #define ss   second
    typedef pair<int, int> P;
    public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        vector<int> path(V, INT_MAX);
        vector<int> vis(V, 0);
        path[S] = 0;
        priority_queue<P, vector<P>, greater<P>> q;
        q.push({0, S});
        while(!q.empty()) {                                               
            int min_path = q.top().ff, node = q.top().ss;                     // O(V log V)
            q.pop();
            if(vis[node]) {
                continue;
            }
            vis[node] = true;
            for(auto it : adj[node]) {                                         // O(v + E)
                int child_path = min_path + it[1], child = it[0];
                if(child_path < path[child]) {
                    path[child] = child_path;
                    q.push({child_path, child});                               // O((V + E) log V)
                }
            }
        }
        return path;
    }
};
// the time to visit each vertex becomes O(V + E) and 
// the time required to process all the neighbours of a vertex becomes O(log V)

// Normal Approach
class Solution {
	public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        vector<int> path(V, INT_MAX);
        vector<int> vis(V, 0);
        path[S] = 0;
        for(int i = 0; i < V - 1; i++) {                            // O(V)
            int min_path = INT_MAX, node;
            for(int j = 0; j < V; j++) {                            // O(V)
                if(path[j] < min_path && !vis[j]) {
                    min_path = path[j]; node = j;
                }
            }
            vis[node] = 1;
            for(auto it : adj[node]) {
                int child_path = min_path + it[1], child = it[0];
                if(child_path < path[child] && !vis[child]) {
                    path[child] = child_path;
                }
            }
        }
        return path;
    }
};
