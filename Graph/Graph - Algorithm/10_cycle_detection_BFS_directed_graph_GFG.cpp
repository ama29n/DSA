#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1 

bool checkDAG(int n, vector<int> adj[]) {
    queue<int> q;
    vector<int> inDegree(n, 0);
    for(int i = 0; i < n; i++) {
        for(auto it : adj[i]) {
            inDegree[it]++;
        }
    }
    for(int i = 0; i < n; i++) {
        if(inDegree[i] == 0) {
            q.push(i);
        }
    }
    int node_count = 0;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        node_count++;
        for(auto it : adj[node]) {
            if(inDegree[it]) {
                inDegree[it]--;
                if(inDegree[it] == 0) {
                    q.push(it);
                }
            }
        }
    }
    return n == node_count;
}