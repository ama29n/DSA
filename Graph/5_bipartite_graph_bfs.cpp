#include <bits/stdc++.h>
using namespace std;

bool isBipartite(vector<int> adj[], int n) {
    vector<int> color(n + 1, -1);

    for(int i = 1; i<= n; i++) {
        if(color[i] == -1) {
            queue<int> q;
            q.push(i);
            color[i] = 1;
            while(q.size() != 0) {
                int node = q.front();
                q.pop();
                for(auto it : adj[node]) {
                    if(color[it] == -1) {
                        color[it] = 1 - color[node];
                        q.push(it);
                    }
                    else if(color[it] == color[node]) return false;
                }
            }
        }
    }
    return true;
}

// A graph that can be colored with 2 different colors with no 2 adjacent nodes having the same color.

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

    bool ans = isBipartite(adj, n);
    if(!ans)
        cout<<"It is Not Bipartite";
    else
        cout<<"It is Bipartite";    
}



// 8 8

// 1 2
// 2 3
// 3 4
// 4 5
// 5 8
// 8 2
// 5 6
// 6 7

// Output = Not

