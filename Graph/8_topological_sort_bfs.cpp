#include <bits/stdc++.h>
using namespace std;

vector<int> topoSortBfs(vector<int> adj[], int n) {
    // Kahn's Algorithm
    vector<int> inDegree(n + 1, 0);
    vector<int> ans;
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        for(auto it : adj[i])
            inDegree[it]++;
    }
    for(int i = 1; i <= n; i++)
        if(inDegree[i] == 0)
            q.push(i);
    while(q.size() != 0) {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto it : adj[node]) {
            if(inDegree[it]) {
                inDegree[it]--;
                if(inDegree[it] == 0)
                    q.push(it);
            }
        }
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

    vector<int> ans = topoSortBfs(adj, n);
    for(auto it : ans)
    cout<< it << " ";
}

// 6 6

// 6 1
// 6 3
// 3 4
// 4 2
// 5 1
// 5 2

// Output - 5 6 1 3 4 2 