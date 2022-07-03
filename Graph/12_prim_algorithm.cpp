#include <bits/stdc++.h>
using namespace std;

// This algorithm is used to find the Minimum Spanning Tree.

vector<int> findMST(vector<pair<int, int>> adj[], int n) {
    vector<int> weight(n, INT_MAX);
    vector<bool> mst(n, false);
    vector<int> parent(n, 0);

    weight[0] = 0;
    parent[0] = -1;

    for(int i = 0; i < n - 1; i++) { // n - 1, as MST will have n vertices, we don't need to do the process for last vertex

        // Finding the node pair with minimum weight and is also not part of MST.
        int minWeight = INT_MAX, node;
        for(int j = 0; j < n; j++) 
            if(mst[j] == false && weight[j] < minWeight)
                node = j, minWeight = weight[j];
        
        mst[node] = true;

        for(auto it : adj[node]) {
            int childNode = it.first, w = it.second;
            if(mst[childNode] == false && w < weight[childNode])
                parent[childNode] = node, weight[childNode] = w;
        }
    }

    return parent;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        int w;
        cin >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> parent = findMST(adj, n);

    for(int i = 0; i < n; i++)
        cout << "Node " << i << ", parent " << parent[i] << endl;
}

// n m
// 9 14

// u v
// w

// 0 1
// 4

// 1 2
// 8

// 2 3
// 7

// 3 4
// 9

// 4 5
// 10

// 5 6
// 2

// 6 7
// 1

// 7 0 
// 8

// 1 7
// 11

// 3 5
// 14

// 2 8 
// 2

// 8 6
// 6

// 7 8
// 7

// 2 5
// 4

// Output

// Node 0, parent -1
// Node 1, parent 0
// Node 2, parent 1
// Node 3, parent 2
// Node 4, parent 3
// Node 5, parent 2
// Node 6, parent 5
// Node 7, parent 6
// Node 8, parent 2