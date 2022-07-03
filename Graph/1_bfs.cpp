#include <bits/stdc++.h>
using namespace std;

// n = number of nodes
// m = number of edges

vector<int> bfsOfGraph(int n, vector<int> adj[]) {
    vector<int> ans;
    vector<int> vis(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        if(!vis[i]){

            queue<int> q;
            q.push(i);
            vis[i]=1;

            while(q.size()>0) {

                int node=q.front();
                q.pop();
                ans.push_back(node);

                for(auto it : adj[node]) {

                    if(!vis[it]){

                        q.push(it);
                        vis[it]=1;
                    }
                }
            }
        }
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ans = bfsOfGraph(n, adj);
    for (auto it : ans)
        cout << it << " ";
}

// 7 6

// 1 2
// 2 7
// 7 5
// 5 3
// 3 2
// 4 6

// Output - 1, 2, 3, 7, 5, 4, 6