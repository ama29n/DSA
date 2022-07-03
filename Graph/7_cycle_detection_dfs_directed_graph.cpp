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

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    bool ans = isCycle(n, adj);
    if(ans)
        cout<<"Cycle";
    else
        cout<<"No cycle";    
}

// 9 10 

// 1 2 
// 2 3
// 3 4
// 4 5
// 3 6
// 6 5
// 7 2
// 7 8
// 8 9
// 9 7

// Output - Cycle
