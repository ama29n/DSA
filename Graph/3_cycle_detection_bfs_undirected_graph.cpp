#include <bits/stdc++.h>
using namespace std;

// n = number of nodes
// m = number of edges

bool isCycle(vector<int> adj[], int n) {
    vector<int> vis(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            queue<pair<int, int>> q;
            q.push({i, -1});
            vis[i] = 1;
            while(q.size() != 0) {
                pair<int, int> node = q.front();
                q.pop();

                for(auto it : adj[node.first]) {
                    if(!vis[it]) {
                        q.push({it, node.first});
                        vis[it] = 1;
                    }
                    else if(it != node.second) return true;
                }
            }

        }
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

    bool ans = isCycle(adj, n);
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