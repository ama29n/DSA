#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;

void spanningTree(int n, vector<vector<int>> adj[]) {
    vector<int> included(n, 0), weight(n, INT_MAX), parent(n, -1);
    priority_queue<p, vector<p>, greater<p>> q;
    q.push({0, 0});
    weight[0] = 0;
    while(!q.empty()) {
        int u = q.top().second;
        q.pop();
        if(included[u]) {
            continue;
        }
        included[u] = 1;
        for(auto it : adj[u]) {
            int v = it[0], w = it[1];
            if(w < weight[v]) {
                weight[v] = w;
                parent[v] = u;
                q.push({w, v});
            }
        }
    }
    for(int i = 1; i < n; i++) {
        cout << "Edge between " << i << " and " << parent[i] << " is part of MST" << endl;
    }
}

int main() {
    int n = 4;
    vector<vector<int>> adj[n];
    adj[0].push_back({1, 2}); adj[1].push_back({0, 3});
    adj[0].push_back({2, 3}); adj[2].push_back({0, 3});
    adj[3].push_back({1, 2}); adj[1].push_back({3, 2});
    adj[3].push_back({2, 6}); adj[2].push_back({3, 6});
    spanningTree(n, adj);
}