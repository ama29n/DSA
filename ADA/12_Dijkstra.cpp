#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;
    
void dijkstra(int n, vector<vector<int>> adj[], int src) {
    priority_queue<p, vector<p>, greater<p>> q;
    vector<int> included(n, 0), path(n, INT_MAX);
    q.push({0, src});
    path[src] = 0;
    while(q.size()) {
        int u_path = q.top().first;
        int u = q.top().second;
        q.pop();
        if(included[u]) {
            continue;
        }       
        included[u] = 1;
        for(auto it : adj[u]) {
            int v = it[0], v_Path = u_path + it[1];
            if(v_Path < path[v]) {
                path[v] = v_Path;
                q.push({v_Path, v});
            }
        }
    }
    for(int i = 0; i < n; i++) {
        cout << "Minimum Distance between " << src << " and " << i << " is: " << path[i] << endl;
    }
}

int main() {
    int n = 4;
    vector<vector<int>> adj[n];
    adj[0].push_back({1, 2}); adj[1].push_back({0, 3});
    adj[0].push_back({2, 3}); adj[2].push_back({0, 3});
    adj[3].push_back({1, 2}); adj[1].push_back({3, 2});
    adj[3].push_back({2, 6}); adj[2].push_back({3, 6});
    dijkstra(n, adj, 0);
}