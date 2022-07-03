#include <bits/stdc++.h>
using namespace std;

bool isCyclic(int n, vector<int> adj[]) {
    // code here
    queue<int> q;
    vector<int> inDegree(n, 0);
    for(int i = 0; i < n; i++)
        for(auto it : adj[i])
            inDegree[it]++;
    
    for(int i = 0; i < n; i++)
        if(inDegree[i] == 0)
            q.push(i);
            
    int nodeCount = 0;
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        nodeCount++;
        for(auto it : adj[node]) {
            if(inDegree[it]) {
                inDegree[it]--;
                if(inDegree[it] == 0)
                    q.push(it);
            }
        }
    }
    return !(n == nodeCount);
}