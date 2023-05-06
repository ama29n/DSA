#include <bits/stdc++.h>
using namespace std;

bool check(int i, int parent, vector<int> &vis, vector<int> &dfs, vector<int> adj[]) {
    vis[i] = 1;
    dfs[i] = 1;

    for(auto it : adj[i]) {
        if(!vis[it])
            if(check(it, i, vis, dfs, adj)) 
                return true;
        else if(dfs[it] == 1)
            return true;
    }
    dfs[i] = 0;
    return false;
}

bool isCycle(int n, vector<int> adj[]) {
    vector<int> vis(n + 1, 0);
    vector<int> dfs(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        if(vis[i] == 0)
            if(check(i, -1, vis, dfs, adj))
                return true;
    }
    return false;
}