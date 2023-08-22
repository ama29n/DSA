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