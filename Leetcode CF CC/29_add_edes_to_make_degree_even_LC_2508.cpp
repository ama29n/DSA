#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/add-edges-to-make-degrees-of-all-nodes-even/description/

// Graph is undirected and can be disconnected. We have to tell if we can make degree of each node even by adding
// atmost 2 edges
// Nodes are from 1 to n
class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        unordered_set<int> adj[n + 1];
        vector<int> degree(n + 1, 0);
        vector<int> v;
        for(auto it : edges) {
            adj[it[0]].insert(it[1]); adj[it[1]].insert(it[0]);
            degree[it[0]]++; degree[it[1]]++;
        }
        for(int i = 1; i <= n; i++) {
            if(degree[i] % 2 != 0)
                v.push_back(i);
        }
        // 2 odd degree nodes -> we can connect nodes togather or with a node which is not connected with either of them
        if(v.size() == 2) {
            int a = v[0], b = v[1];
            for(int i = 1; i <= n; i++) {
                if(adj[i].find(b) == adj[i].end() && adj[i].find(a) == adj[i].end())
                return true;
            }
            return false;
        }
        // 4 odd degree nodes -> We have to connect them togather as it will take 2 edges
        if(v.size() == 4) {
            int a = v[0], b = v[1], c = v[2], d = v[3];
            bool x = (adj[a].find(b) == adj[a].end()) && (adj[c].find(d) == adj[c].end()) ? true : false;
            bool y = (adj[a].find(c) == adj[a].end()) && (adj[b].find(d) == adj[b].end()) ? true : false;
            bool z = (adj[a].find(d) == adj[a].end()) && (adj[c].find(b) == adj[c].end()) ? true : false;
            return x || y || z;
        }
        // 0 odd degree nodes -> return true, for all other cases ans will be 4
        return v.size() == 0 ? true : false;
    }
};