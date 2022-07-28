#include <bits/stdc++.h>
using namespace std;

// n = number of nodes
// m = number of edges
// w = weight


// Doesn't works for negative edges 


// Priority Queue Method

// < path, node >
typedef pair<int, int> p;
    
vector <int> dijkstra(int n, vector<vector<int>> adj[], int src) {
    priority_queue<p, vector<p>, greater<p>> q;
    vector<int> included(n, 0), path(n, INT_MAX);
    q.push({0, src});
    path[src] = 0;
    
    while(q.size()) {
        int node = q.top().second;
        int p = q.top().first;
        q.pop();
        
        if(included[node])
        continue;
                
        included[node] = 1;
        
        for(auto it : adj[node]) {
            int v = it[0], totPath = p + it[1];
            if(totPath < path[v]) {
                path[v] = totPath;
                q.push({totPath, v});
            }
        }
    }
    return path;
}

// Normal Approach
vector <int> dijkstra(int n, vector<vector<int>> adj[], int src) {
    vector<int> path(n, INT_MAX);
    vector<int> included(n, 0);
    path[src] = 0;
    
    for(int i = 0; i < n - 1; i++) {
        int node, minPath = INT_MAX;
        for(int i = 0; i < n; i++)
            if(!included[i] && path[i] < minPath) {
                node = i;
                minPath = path[i];
            }
        
        included[node] = 1;
        
        for(auto it : adj[node]) {
            int vertex = it[0];
            int weight = it[1];
            int totalPath = weight + path[node];
            if(!included[vertex] && totalPath < path[vertex]) {
                path[vertex] = totalPath;
            }
        }
    }
    return path;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj[n];

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int S = 0;

    vector<int> ans = dijkstra(n, adj, S);

    for(auto it : ans) {
        cout << it << " ";
    }
}