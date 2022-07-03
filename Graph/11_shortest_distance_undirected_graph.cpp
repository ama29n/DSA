#include <bits/stdc++.h>
using namespace std;

void shortestPath(int n, vector<int> adj[], int source)
{
    queue<int> q;
    q.push(source);
    vector<int> distance(n, INT_MAX);
    distance[source] = 0;

    while(q.size() > 0){

        int node = q.front();
        q.pop();

        for(auto it : adj[node]){

            if(distance[node] + 1 < distance[it]){

                distance[it] = distance[node] + 1;
                q.push(it);
            }
        }
    }
    for(auto it : distance)
    cout<< it << " ";
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
    shortestPath(n, adj, 0);  
}

// 9 11

// 0 1
// 0 3
// 1 3
// 1 2
// 2 6
// 3 4
// 4 5
// 5 6 
// 6 7
// 7 8
// 6 8

// Output - 0 1 2 1 2 3 3 4 4