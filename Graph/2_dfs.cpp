#include <bits/stdc++.h>
using namespace std;

// n = number of nodes
// m = number of edges

void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &ans)
{
    ans.push_back(node);
    vis[node] = 1;
    for (auto it : adj[node])
        if (!vis[it])
            dfs(it, adj, vis, ans);
}

vector<int> dfsOfGraph(int n, vector<int> adj[])
{
    vector<int> ans;
    vector<int> vis(n + 1, 0);

    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i, adj, vis, ans);

    return ans;
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

    vector<int> ans = dfsOfGraph(n, adj);
    for (auto it : ans)
        cout << it << " ";
}

// 7 6

// 1 2
// 2 7
// 7 6
// 6 4
// 4 2
// 3 5

// Output - 1, 2, 7, 6, 4, 3, 5.