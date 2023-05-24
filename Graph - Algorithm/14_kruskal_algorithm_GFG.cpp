#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1# 

class Solution {
private:
    class DSU {
    private:
        int n;
        vector<int> parent, rank;
    public:
        DSU(int size) : n(size) {
            rank = vector<int> (n, 0);
            parent = vector<int> (n);
            for(int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }
        int findParent(int n) {
            if(parent[n] == n) {
                return n;
            }
            return parent[n] = findParent(parent[n]);
        }
        void makePair(int a, int b) {
            a = findParent(a);
            b = findParent(b);
            if(rank[a] > rank[b]) {
                parent[b] = a; return;
            }
            if(rank[b] > rank[a]) {
                parent[a] = b; return;
            }
            parent[b] = a;
            rank[a]++;
        }
    };
public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<vector<int>> edges;
        for(int i = 0; i < V; i++) {
            for(auto it : adj[i]) 
            edges.push_back({it[1], i, it[0]});
        }
        sort(edges.begin(), edges.end());
        DSU dsu(V);
        int mst = 0;
        for(auto it : edges) {
            if(dsu.findParent(it[1]) != dsu.findParent(it[2])) {
                mst += it[0];
                dsu.makePair(it[1], it[2]);
            }
        }
        return mst;
    }
};

// Time Complexity - E (log E) 