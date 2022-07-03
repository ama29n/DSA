#include <bits/stdc++.h>
using namespace std;

// n = number of nodes
// m = number of edges
// w = weight



// Priority Queue Method

typedef pair<int, int> p; // <weight, node>

vector<int> dijkstra(int n, vector<vector<int>> adj[], int S) {
    vector<int> weight(n, INT_MAX), vis(n, 0);
    weight[S] = 0;
    priority_queue<p, vector<p>, greater<p>> q;
    q.push({0, S});

    while(q.size()) {
        pair<int, int> node = q.top();
        q.pop();

        if(vis[node.second]) continue;
        vis[node.second] = 1;
        
        for(auto it : adj[node.second]) {
            int d = it[1] + node.first;
            
            if(d < weight[it[0]]) {
                weight[it[0]] = d;
                q.push({d, it[0]});
            }
        }
    }
    return weight;
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