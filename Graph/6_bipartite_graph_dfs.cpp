#include<bits/stdc++.h>
using namespace std;

bool check(vector<int> adj[], vector<int> &color, int node) {
    // Important condition becuase in other cases we made vis = 1, but if here the color is 0 we are making it 1 
    if(color[node] == -1)
        color[node] = 1;
    for(auto it : adj[node]) {
        if(color[it] == -1) {
            color[it] = 1 - color[node];
            if(!check(adj, color, it))
                return false;
        }
        else if(color[it] == color[node])
            return false;
    }
    return true;
}

bool isBipartite(vector<int> adj[], int n) {
    vector<int> color(n + 1, -1);

    for(int i = 1; i <= n; i++) {
        if(color[i] == -1) {
            if(!check(adj, color, i))
                return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool check = isBipartite(adj, n);
    cout<< check;
}