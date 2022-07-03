#include <bits/stdc++.h>
using namespace std;

bool check(int i, int parent, vector<int> &vis, vector<int> adj[])
{
    vis[i] = 1;

    for(auto it : adj[i]){
        if(!vis[it])
        {
            if(check(it, i, vis, adj)) return true;
        }
        else if(it != parent) return true;
    }
    return false;
}

bool isCycle(int n, vector<int> adj[])
{
    vector<int> vis(n + 1, 0);
    for(int i = 1; i <= n; i++){

        if(vis[i] == 0)
        if(check(i, -1, vis, adj)) return true;
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
        adj[v].push_back(u);
    }

    bool ans = isCycle(n, adj);
    if(ans)
        cout<<"Cycle is Present";
    else
        cout<<"Cycle is not Present";    
}

// 7 6

// 1 2
// 2 7
// 7 5
// 5 3
// 3 2
// 4 6

// Output - Cycle is Present.
