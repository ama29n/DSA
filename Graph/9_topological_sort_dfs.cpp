#include <bits/stdc++.h>
using namespace std;

void sort(int i, vector<int> &vis, vector<int> adj[], vector<int> &ans) {
    vis[i] = 1;

    for(auto it : adj[i]){
        if(!vis[it])
            sort(it, vis, adj, ans);
    }
    ans.push_back(i);
}

vector<int> topologicalSort(int n, vector<int> adj[]) {
    vector<int> vis(n + 1, 0), ans;

    for(int i = 1; i <= n; i++) {
        if(!vis[i])
            sort(i, vis, adj, ans);
    }
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
    }

    vector<int> ans = topologicalSort(n, adj);  
    for(int i = ans.size() - 1; i >= 0; i++)
        cout << ans[i] << " ";
}

// 6 6

// 6 1
// 6 3
// 3 4
// 4 2
// 5 1
// 5 2

// Output - 6 5 3 4 2 1 