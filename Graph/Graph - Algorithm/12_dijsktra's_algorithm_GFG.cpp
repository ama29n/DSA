#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1# 

// Priority Queue Method
class Solution {
private:
    #define ff  first
    #define ss  second
    typedef pair<int, int> P;
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        vector<int> path(V, INT_MAX);
        path[S] = 0;
        priority_queue<P, vector<P>, greater<P>> q;         // Min Heap
        q.push({ 0, S });
        while(!q.empty()) {
            int node_path = q.top().ff, node = q.top().ss;  // O(V log V)
            q.pop();
            if(node_path > path[node]) continue;
            for(auto it : adj[node]) {                      // O(V + E)
                int child = it[0], child_path = node_path + it[1];
                if(child_path < path[child]) {
                    path[child] = child_path;
                    q.push({ child_path, child });           // O((V + E) log V)
                }
            }
        }
        return path;
    }
};
// The time to visit each vertex becomes O(V + E) and 
// The time required to process all the neighbours of a vertex becomes O(log V)

// Normal Approach
class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        vector<int> path(V, INT_MAX);
        vector<int> vis(V, 0);
        path[S] = 0;
        for(int i = 0; i < V - 1; i++) {                // O(V)
            int node, node_path = INT_MAX;
            // Finding the node with minimum path
            for(int j = 0; j < V; j++) {                // O(V)
                if(!vis[j] && path[j] < node_path) {
                    node_path = path[j]; node = j;
                }
            }
            // Make the node visited
            vis[node] = 1;
            // Determine the minimum path to neighbours via node
            for(auto it : adj[node]) {
                int child = it[0], child_path = node_path + it[1];
                if(!vis[child] && child_path < path[child]) {
                    path[child] = child_path;
                }
            }
        }
        return path;
    }
};
// Time Complexity - O(V)
